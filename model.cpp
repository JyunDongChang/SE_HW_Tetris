#include "model.h";
#include "view.h";
#include "controller.h"

void model::setgame()
{
	tetris = new int*[column];
	for (int i = 0;i < column;i++)
		tetris[i] = new int[row];
	//��l�ƹC���]�w
	//EX:�]�w��l�����t�סA�}�lmainloop������

	//�]�w����N��view��C���e���e�X��
	myview->paint();
}

void model::tetris_move(int direction)
{
	myblock;
	tetris;
	//�ھګ��O�h���next��pos
	//�`�Ntetris���쥻�N���F�誺�a��
	//�Y�w�g�L�k�A�U�Y�h��nextblock��myblock
	bool can_fall=false;
	if (can_fall)
	{
		myblock = nextblock;
		//random�@�ӷsblock��nextblock
		//pos�O�o�]�w
	}
	//������
	checkline();
}

void model::tetris_rotate()
{
	//�Pmove
}

void model::tetris_fall()
{
	//�Pmove
}

void model::mainloop()
{
	//�C�����A�խ�myblock
	//QObject�����Ѯɴ����\��C�P�w�ɬ�������ܦ�:startTimer()�BtimeEvent()�BkillTimer()
	//������@��
	checkline();
	//�M��A�h�T�{
	checkfloar();
}

void model::checkline()
{
	//�ˬd���S���F�����A���N�[��
	score++;
	//�ˬd���N���s�e
	myview->paint();
}

void model::checkfloar()
{
	//�ˬdtetris[]�O���O���W�Ѫ�O�F
	if (true)
	{
		//����timer
		//endgame
		//��stop�nstop
		//tetris�O�odelete
	}
}
