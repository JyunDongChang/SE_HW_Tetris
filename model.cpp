#include "model.h"
#include <QObject>
#include <QTimer>
#include <QTime>

void model::setgame()
{
	//��l�ưѼ�
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

	level = score = 0;
    fallSpeed = 1500;
	inTurnChangeTime = false;

	tetris = new int*[tetrisColumn];
	for (int i = 0; i < tetrisColumn; i++)
		tetris[i] = new int[tetrisRow];
	//��l�ƹC���]�w
	//EX:�]�w��l�����t�סA�}�lmainloop������

	for (int i = 0; i < tetrisColumn; i++)
		for (int j = 0; j < tetrisRow; j++)
			tetris[i][j] = 0;

	//�]�mblock
	myblock = createnewpeace();
	//paintintetris();
	nextblock = createnewpeace();

	//�]�w����N��view��C���e���e�X��
	myview->paint();
	//�Ұ�timer
    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mainloop()));
	timer->start(fallSpeed);
}

void model::tetris_move(int direction)
{
	if (!inTurnChangeTime) {
		block temp = copyablock(myblock);

		switch (direction)
		{
        case right_move: temp.pos[0]++; break;
        case left_move: temp.pos[0]--; break;
		default:
			break;
		}

		if (checkintetris(temp))
		{
			myblock = copyablock(temp);
		}
		//�ھګ��O�h���next��pos
		//�`�Ntetris���쥻�N���F�誺�a��
		//�Y�w�g�L�k�A�U�Y�h��nextblock��myblock  //���A�Q��

		//������
		myview->paint();
	}
}

void model::tetris_rotate(int direction)
{
	if (!inTurnChangeTime) {
		block temp;

		if (direction == right_rotate)
		{
			myblock.rotate++;
			if (myblock.rotate > 3)
				myblock.rotate = 0;
			temp = copyrotateblock();
		}
		else if (direction == left_rotate)
		{
			myblock.rotate--;
			if (myblock.rotate < 0)
				myblock.rotate = 3;
			temp = copyrotateblock();
		}

		if (checkintetris(temp))
		{
			myblock = copyablock(temp);
		}
		//�ھګ��O�h���next��pos
		//�`�Ntetris���쥻�N���F�誺�a��
		//�Y�w�g�L�k�A�U�Y�h��nextblock��myblock  //���A�Q��

		//������
		myview->paint();
	}
}

void model::tetris_storage()
{
	if (!inTurnChangeTime) {
		block temp = copyablock(originalshape[myblock.type][0]);
		myblock = copyablock(storageblock);
		storageblock = copyablock(temp);

		checkfloar();
		//������
		myview->paint();
	}
}

void model::tetris_fall()
{
	block temp;
	if (!inTurnChangeTime) {
		inTurnChangeTime = true;
		timer->stop();
		while (true)
		{
			temp = copyablock(myblock);
            temp.pos[1] += 1;
			if (checkintetris(temp))
			{
				myblock = copyablock(temp);
			}
			else
			{
				break;
			}
		}

		paintintetris();
		checkline();
		myblock = copyablock(nextblock);
		nextblock = createnewpeace();
		checkfloar();

		myview->paint();
		timer->start();
		inTurnChangeTime = false;
	}
	//�Pmove
}

void model::mainloop()
{
	block temp;
	if (!inTurnChangeTime) {
		inTurnChangeTime = true;
		temp = copyablock(myblock);
        temp.pos[1] += 1;
		if (checkintetris(temp))
		{
			myblock = copyablock(temp);
		}
		else
		{
			//inTurnChangeTime = true;
			paintintetris();
			checkline();
			myblock = copyablock(nextblock);
			nextblock = createnewpeace();
			checkfloar();
		}

		myview->paint();
		inTurnChangeTime = false;
	}
	//�C�����A�խ�myblock
	//QObject�����Ѯɴ����\��C�P�w�ɬ�������ܦ�:startTimer()�BtimeEvent()�BkillTimer()
	//������@��

	//�M��A�h�T�{


}
//������
void model::checkline()
{
	bool checkReg;
	bool isFull[tetrisColumn] = { false };
	for (int i = 0; i < tetrisColumn; i++) {
		checkReg = true;
		for (int j = 0; j < tetrisRow; j++) {
			if (tetris[i][j] == 0)
			{
				checkReg = false;
				break;
			}
		}
		if (checkReg)
		{
			isFull[i] = true;
			score += level;
			level++;
		}
	}

	if (level / 5 > 0)
	{
        fallSpeed -= (level/5)*10;
	}

	int k = 0;
	for (int i = 0; i < tetrisColumn; i++) {
		if (!isFull[i])
		{
            if (k != i) {
				for (int j = 0; j < tetrisRow; j++) {
					tetris[k][j] = tetris[i][j];
				}
			}
			k++;
		}
	}
	//�ˬd���S���F�����A���N�[��
	//score++;
	//���speed��
	//timer->changeInterval(msec);

	//�ˬd���N���s�e
	//myview->paint();
}

void model::checkfloar()
{
	bool continueGame = checkintetris(myblock);
	//�ˬdtetris[]�O���O���W�Ѫ�O�F
	if (!continueGame)
	{
		timer->stop();
		inTurnChangeTime = true;
		//����timer
		//endgame
		//��stop�nstop
		//tetris�O�odelete
	}
}

bool model::checkintetris(block input)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
            if (input.cell[i][j] > 0)
			{
				//�O�_�W��
                if (input.pos[0] + i < 0 || input.pos[0] + i >= tetrisRow || input.pos[1] + j < 0 || input.pos[1] + j >= tetrisColumn)
					return false;
				//�O�_���|
                if (tetris[input.pos[0] + i][input.pos[1] + j] > 0)
					return false;
			}
		}
	}
	return true;
}

void model::paintintetris()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
            if (myblock.cell[i][j] > 0)
			{
                tetris[myblock.pos[0] + i][myblock.pos[1] + j] = myblock.cell[i][j];
			}
		}
	}
}

void model::setoriginalshape()
{


	//����
    originalshape[0][0].pos[0] = 3;
    originalshape[0][0].pos[1] = 0;

    originalshape[0][0].cell[2][0] = 1;
    originalshape[0][0].cell[2][1] = 1;
    originalshape[0][0].cell[2][2] = 1;
    originalshape[0][0].cell[2][3] = 1;
	originalshape[0][0].type = 0;
	originalshape[0][0].rotate = 0;

    originalshape[0][1].cell[0][2] = 1;
    originalshape[0][1].cell[1][2] = 1;
    originalshape[0][1].cell[2][2] = 1;
    originalshape[0][1].cell[3][2] = 1;

    originalshape[0][2].cell[2][0] = 1;
    originalshape[0][2].cell[2][1] = 1;
    originalshape[0][2].cell[2][2] = 1;
    originalshape[0][2].cell[2][3] = 1;

    originalshape[0][3].cell[0][2] = 1;
    originalshape[0][3].cell[1][2] = 1;
    originalshape[0][3].cell[2][2] = 1;
    originalshape[0][3].cell[3][2] = 1;

	//���
    originalshape[1][0].pos[0] = 5;
    originalshape[1][0].pos[1] = 0;

    originalshape[1][0].cell[0][0] = 2;
    originalshape[1][0].cell[1][0] = 2;
    originalshape[1][0].cell[0][1] = 2;
    originalshape[1][0].cell[1][1] = 2;
	originalshape[1][0].type = 1;
	originalshape[1][0].rotate = 0;

    originalshape[1][1].cell[0][0] = 2;
    originalshape[1][1].cell[1][0] = 2;
    originalshape[1][1].cell[0][1] = 2;
    originalshape[1][1].cell[1][1] = 2;

    originalshape[1][2].cell[0][0] = 2;
    originalshape[1][2].cell[1][0] = 2;
    originalshape[1][2].cell[0][1] = 2;
    originalshape[1][2].cell[1][1] = 2;

    originalshape[1][3].cell[0][0] = 2;
    originalshape[1][3].cell[1][0] = 2;
    originalshape[1][3].cell[0][1] = 2;
    originalshape[1][3].cell[1][1] = 2;

	//T��
    originalshape[2][0].pos[0] = 4;
    originalshape[2][0].pos[1] = 0;

    originalshape[2][0].cell[0][0] = 3;
    originalshape[2][0].cell[1][0] = 3;
    originalshape[2][0].cell[2][0] = 3;
    originalshape[2][0].cell[1][1] = 3;
	originalshape[2][0].type = 2;
	originalshape[2][0].rotate = 0;

    originalshape[2][1].cell[0][1] = 3;
    originalshape[2][1].cell[1][0] = 3;
    originalshape[2][1].cell[1][1] = 3;
    originalshape[2][1].cell[1][2] = 3;

    originalshape[2][2].cell[0][1] = 3;
    originalshape[2][2].cell[1][1] = 3;
    originalshape[2][2].cell[2][1] = 3;
    originalshape[2][2].cell[1][0] = 3;

    originalshape[2][3].cell[0][0] = 3;
    originalshape[2][3].cell[0][1] = 3;
    originalshape[2][3].cell[0][2] = 3;
    originalshape[2][3].cell[1][1] = 3;

	//��L
    originalshape[3][0].pos[0] = 5;
    originalshape[3][0].pos[1] = 0;

    originalshape[3][0].cell[0][0] = 4;
    originalshape[3][0].cell[1][0] = 4;
    originalshape[3][0].cell[2][0] = 4;
    originalshape[3][0].cell[0][1] = 4;
	originalshape[3][0].type = 3;
	originalshape[3][0].rotate = 0;

    originalshape[3][1].cell[2][0] = 4;
    originalshape[3][1].cell[2][1] = 4;
    originalshape[3][1].cell[2][2] = 4;
    originalshape[3][1].cell[1][0] = 4;

    originalshape[3][2].cell[0][2] = 4;
    originalshape[3][2].cell[1][2] = 4;
    originalshape[3][2].cell[2][2] = 4;
    originalshape[3][2].cell[2][1] = 4;

    originalshape[3][3].cell[0][0] = 4;
    originalshape[3][3].cell[0][1] = 4;
    originalshape[3][3].cell[0][2] = 4;
    originalshape[3][3].cell[1][2] = 4;
	//�fL
    originalshape[4][0].pos[0] = 4;
    originalshape[4][0].pos[1] = 0;

    originalshape[4][0].cell[0][0] = 5;
    originalshape[4][0].cell[1][0] = 5;
    originalshape[4][0].cell[2][0] = 5;
    originalshape[4][0].cell[2][1] = 5;
	originalshape[4][0].type = 4;
	originalshape[4][0].rotate = 0;

    originalshape[4][1].cell[2][0] = 5;
    originalshape[4][1].cell[2][1] = 5;
    originalshape[4][1].cell[2][2] = 5;
    originalshape[4][1].cell[1][2] = 5;

    originalshape[4][2].cell[0][2] = 5;
    originalshape[4][2].cell[1][2] = 5;
    originalshape[4][2].cell[2][2] = 5;
    originalshape[4][2].cell[0][1] = 5;

    originalshape[4][3].cell[0][0] = 5;
    originalshape[4][3].cell[0][1] = 5;
    originalshape[4][3].cell[0][2] = 5;
    originalshape[4][3].cell[1][0] = 5;
	//��S
    originalshape[5][0].pos[0] = 4;
    originalshape[5][0].pos[1] = 0;

    originalshape[5][0].cell[2][0] = 6;
    originalshape[5][0].cell[1][0] = 6;
    originalshape[5][0].cell[1][1] = 6;
    originalshape[5][0].cell[0][2] = 6;
	originalshape[5][0].type = 5;
	originalshape[5][0].rotate = 0;

    originalshape[5][1].cell[0][0] = 6;
    originalshape[5][1].cell[0][1] = 6;
    originalshape[5][1].cell[1][1] = 6;
    originalshape[5][1].cell[1][2] = 6;

    originalshape[5][2].cell[2][0] = 6;
    originalshape[5][2].cell[1][0] = 6;
    originalshape[5][2].cell[1][1] = 6;
    originalshape[5][2].cell[0][2] = 6;

    originalshape[5][3].cell[0][0] = 6;
    originalshape[5][3].cell[0][1] = 6;
    originalshape[5][3].cell[1][1] = 6;
    originalshape[5][3].cell[1][2] = 6;
	//Z
    originalshape[6][0].pos[0] = 4;
    originalshape[6][0].pos[1] = 0;

    originalshape[6][0].cell[0][0] = 7;
    originalshape[6][0].cell[1][0] = 7;
    originalshape[6][0].cell[1][1] = 7;
    originalshape[6][0].cell[2][0] = 7;
	originalshape[6][0].type = 6;
	originalshape[6][0].rotate = 0;

    originalshape[6][1].cell[1][0] = 7;
    originalshape[6][1].cell[1][1] = 7;
    originalshape[6][1].cell[0][1] = 7;
    originalshape[6][1].cell[0][2] = 7;

    originalshape[6][2].cell[0][0] = 7;
    originalshape[6][2].cell[1][0] = 7;
    originalshape[6][2].cell[1][1] = 7;
    originalshape[6][2].cell[2][0] = 7;

    originalshape[6][3].cell[1][0] = 7;
    originalshape[6][3].cell[1][1] = 7;
    originalshape[6][3].cell[0][1] = 7;
    originalshape[6][3].cell[0][2] = 7;
}

block model::createnewpeace()
{
    int n = qrand()%8;
	block temp = copyablock(originalshape[n][0]);
	return temp;
}

block model::copyablock(block input)
{
	block temp;
    temp.pos[0] = input.pos[0];
    temp.pos[1] = input.pos[1];
	temp.type = input.type;
	temp.rotate = input.rotate;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
            temp.cell[i][j] = input.cell[i][j];
	return temp;
}

block model::copyrotateblock()
{
	block temp = copyablock(originalshape[myblock.type][myblock.rotate]);
    temp.pos[0] = myblock.pos[0];
    temp.pos[1] = myblock.pos[1];
	return temp;
}
