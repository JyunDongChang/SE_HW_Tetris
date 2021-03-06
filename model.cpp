﻿#include "model.h"
#include <QObject>
#include <QTimer>
#include <QTime>

void model::setgame()
{
	//初始化參數

    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    level = score = deleteLineCount = 0;
    fallSpeed = 1500;
    //inTurnChangeTime = false;

	tetris = new int*[tetrisRow];
	for (int i = 0; i < tetrisRow; i++)
		tetris[i] = new int[tetrisColumn];
	//初始化遊戲設定
	//EX:設定初始掉落速度，開始mainloop之類的

	for (int i = 0; i < tetrisRow; i++)
		for (int j = 0; j < tetrisColumn; j++)
			tetris[i][j] = 0;
    setoriginalshape();
	//設置block
	myblock = createnewpeace();
	//paintintetris();
	nextblock = createnewpeace();
    myview->showNext();
    tetris_shape();
	//設定完後就讓view把遊戲畫面畫出來
    myview->Tetrisrepaint(this);
	//啟動timer
    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mainloop()));
	timer->start(fallSpeed);
    isStart = true;
}

void model::reStart()
{
    if(isPause){
    timer->start(fallSpeed);
    inTurnChangeTime = false;
    isPause = false;
    myview->Tetrisrepaint(this);
    }
}

void model::pause()
{
    printf("in\n");
    isPause = true;
    timer->stop();
    inTurnChangeTime = true;
    myview->Tetrisrepaint(this);
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
		//根據指令去更動next的pos
		//注意tetris中原本就有東西的地方
		//若已經無法再下墜則把nextblock給myblock  //須再討論
        tetris_shape();
		//做完後
        myview->Tetrisrepaint(this);
	}
    else
    {
        printf("GG\n");
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
		//根據指令去更動next的pos
		//注意tetris中原本就有東西的地方
		//若已經無法再下墜則把nextblock給myblock  //須再討論
        tetris_shape();
		//做完後
        myview->Tetrisrepaint(this);
	}
}

void model::tetris_storage()
{
	if (!inTurnChangeTime) {
        if(!isStorage)
        {
            isStorage = true;
            if(!isEmptyStorage)
            {
                isEmptyStorage = true;
                storageblock = copyablock(originalshape[myblock.type-1][0]);
                myblock = copyablock(nextblock);
                nextblock = createnewpeace();
                myview->showNext();
                myview->showStorage();
            }
            else
            {
                block temp = copyablock(originalshape[myblock.type-1][0]);
                myblock = copyablock(storageblock);
                storageblock = copyablock(temp);
                myview->showStorage();
            }
            tetris_shape();
            if(!checkfloar())
            {
                inTurnChangeTime = false;
            }
            //做完後
            myview->Tetrisrepaint(this);
        }
	}
}

void model::tetris_shape()
{
    block temp;
    shapeblock = copyablock(myblock);
    while (true)
    {
        temp = copyablock(shapeblock);
        temp.pos[1] += 1;
        if (!checkintetris(temp))
        {
           break;
        }
        else
        {
            shapeblock = copyablock(temp);
        }
    }
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(shapeblock.cell[i][j] != 0)
            {
                shapeblock.cell[i][j] = 8;
            }
        }
    }
}

void model::tetris_Quickfall()
{
    block temp;

    if (!inTurnChangeTime) {

        inTurnChangeTime = true;
        //timer->stop();

        temp = copyablock(myblock);
        temp.pos[1] += 1;
        if (checkintetris(temp))
        {
            myblock = copyablock(temp);
        }
        else
        {
            timer->stop();
            paintintetris();
            checkline();
            myblock = copyablock(nextblock);
            nextblock = createnewpeace();
            myview->showNext();
            isStorage = false;
        }
        if(!checkfloar())
            inTurnChangeTime = false;
        tetris_shape();
        myview->Tetrisrepaint(this);
    }

    //同move
}

void model::tetris_fall()
{
	block temp;

	if (!inTurnChangeTime) {
        printf("can/n");
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
        myview->showNext();
        isStorage = false;
        if(!checkfloar())
            inTurnChangeTime = false;
        tetris_shape();
        myview->Tetrisrepaint(this);
        //timer->start();
	}
    else
    {
        printf("can't/n");
    }
	//同move
}

void model::mainloop()
{//score++;
	block temp;
	if (!inTurnChangeTime) {
		inTurnChangeTime = true;
		temp = copyablock(myblock);
        temp.pos[1] += 1;
		if (checkintetris(temp))
		{
			myblock = copyablock(temp);
            myview->Tetrisrepaint(this);
            inTurnChangeTime = false;
		}
		else
		{
			//inTurnChangeTime = true;
			paintintetris();
			checkline();
			myblock = copyablock(nextblock);
			nextblock = createnewpeace();
            myview->showNext();
            isStorage = false;
            if(!checkfloar())
                inTurnChangeTime = false;
            tetris_shape();
            myview->Tetrisrepaint(this);

		}
	}
	//每秒執行，調降myblock
	//QObject類提供時期的功能。與定時相關的函示有:startTimer()、timeEvent()、killTimer()
	//做完後一樣

	//然後再去確認


}
//未完成
void model::checkline()
{
	bool checkReg;
    int thisTimeDL = 0;
	bool isFull[tetrisColumn] = { false };
	for (int i = 0; i < tetrisColumn; i++) {
		checkReg = true;
		for (int j = 0; j < tetrisRow; j++) {
			if (tetris[j][i] == 0)
			{
				checkReg = false;
				break;
			}
		}
		if (checkReg)
		{
			isFull[i] = true;
            thisTimeDL++;
            deleteLineCount++;
            //score += level;
            //level++;

		}
	}
    if(level<10)
    {
        level = deleteLineCount/10;
    }
    switch (thisTimeDL) {
    case 0:
        break;
    case 1: score += 4*(level+1);
        break;
    case 2: score += 10*(level+1);
        break;
    case 3:  score += 30*(level+1);
        break;
    case 4:  score += 120*(level+1);
        break;
    default:
        break;
    }
     //printf("%f\n",&level);

    fallSpeed = 1500-(level*100);

    int k = tetrisColumn-1;
    for (int i = tetrisColumn-1; i >= 0; i--) {
		if (!isFull[i])
		{
            if (k != i) {
				for (int j = 0; j < tetrisRow; j++) {
					tetris[j][k] = tetris[j][i];
				}
			}
            k--;
		}
	}
	//檢查有沒有東西能消，有就加分
	//score++;
	//更改speed用
	//timer->changeInterval(msec);
    timer->start(fallSpeed);
	//檢查完就重新畫
    myview->Tetrisrepaint(this);
}

bool model::checkfloar()
{
	bool continueGame = checkintetris(myblock);
	//檢查tetris[]是不是撞上天花板了
	if (!continueGame)
	{
		timer->stop();
		inTurnChangeTime = true;
        isStart = false;
        isPause = false;
		//關掉timer
		//endgame
		//該stop要stop
		//tetris記得delete
        if(inTurnChangeTime)
            printf("end\n");
        return true;
	}
    return false;
}

bool model::checkintetris(block input)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
            if (input.cell[i][j] > 0)
			{
				//是否超界
                if (input.pos[0] + i < 0 || input.pos[0] + i >= tetrisRow || input.pos[1] + j < 0 || input.pos[1] + j >= tetrisColumn)
					return false;
				//是否重疊
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


	//直條
    originalshape[0][0].pos[0] = 2;
    originalshape[0][0].pos[1] = 0;

    originalshape[0][0].cell[2][0] = 1;
    originalshape[0][0].cell[2][1] = 1;
    originalshape[0][0].cell[2][2] = 1;
    originalshape[0][0].cell[2][3] = 1;
    originalshape[0][0].type = 1;
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

	//方塊
    originalshape[1][0].pos[0] = 4;
    originalshape[1][0].pos[1] = 0;

    originalshape[1][0].cell[0][0] = 2;
    originalshape[1][0].cell[1][0] = 2;
    originalshape[1][0].cell[0][1] = 2;
    originalshape[1][0].cell[1][1] = 2;
    originalshape[1][0].type = 2;
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

	//T型
    originalshape[2][0].pos[0] = 3;
    originalshape[2][0].pos[1] = 0;

    originalshape[2][0].cell[0][0] = 3;
    originalshape[2][0].cell[1][0] = 3;
    originalshape[2][0].cell[2][0] = 3;
    originalshape[2][0].cell[1][1] = 3;
    originalshape[2][0].type = 3;
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

	//正L
    originalshape[3][0].pos[0] = 4;
    originalshape[3][0].pos[1] = 0;

    originalshape[3][0].cell[0][0] = 4;
    originalshape[3][0].cell[1][0] = 4;
    originalshape[3][0].cell[2][0] = 4;
    originalshape[3][0].cell[0][1] = 4;
    originalshape[3][0].type = 4;
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
	//逆L
    originalshape[4][0].pos[0] = 3;
    originalshape[4][0].pos[1] = 0;

    originalshape[4][0].cell[0][0] = 5;
    originalshape[4][0].cell[1][0] = 5;
    originalshape[4][0].cell[2][0] = 5;
    originalshape[4][0].cell[2][1] = 5;
    originalshape[4][0].type = 5;
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
	//正S
    originalshape[5][0].pos[0] = 3;
    originalshape[5][0].pos[1] = 0;

    originalshape[5][0].cell[2][0] = 6;
    originalshape[5][0].cell[1][0] = 6;
    originalshape[5][0].cell[1][1] = 6;
    originalshape[5][0].cell[0][1] = 6;
    originalshape[5][0].type = 6;
	originalshape[5][0].rotate = 0;

    originalshape[5][1].cell[0][0] = 6;
    originalshape[5][1].cell[0][1] = 6;
    originalshape[5][1].cell[1][1] = 6;
    originalshape[5][1].cell[1][2] = 6;

    originalshape[5][2].cell[2][0] = 6;
    originalshape[5][2].cell[1][0] = 6;
    originalshape[5][2].cell[1][1] = 6;
    originalshape[5][2].cell[0][1] = 6;

    originalshape[5][3].cell[0][0] = 6;
    originalshape[5][3].cell[0][1] = 6;
    originalshape[5][3].cell[1][1] = 6;
    originalshape[5][3].cell[1][2] = 6;
	//Z
    originalshape[6][0].pos[0] = 3;
    originalshape[6][0].pos[1] = 0;

    originalshape[6][0].cell[0][0] = 7;
    originalshape[6][0].cell[1][0] = 7;
    originalshape[6][0].cell[1][1] = 7;
    originalshape[6][0].cell[2][1] = 7;
    originalshape[6][0].type = 7;
	originalshape[6][0].rotate = 0;

    originalshape[6][1].cell[1][0] = 7;
    originalshape[6][1].cell[1][1] = 7;
    originalshape[6][1].cell[0][1] = 7;
    originalshape[6][1].cell[0][2] = 7;

    originalshape[6][2].cell[0][0] = 7;
    originalshape[6][2].cell[1][0] = 7;
    originalshape[6][2].cell[1][1] = 7;
    originalshape[6][2].cell[2][1] = 7;

    originalshape[6][3].cell[1][0] = 7;
    originalshape[6][3].cell[1][1] = 7;
    originalshape[6][3].cell[0][1] = 7;
    originalshape[6][3].cell[0][2] = 7;
}

block model::createnewpeace()
{
    int n = qrand()%7;
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
    block temp = copyablock(originalshape[myblock.type-1][myblock.rotate]);
    temp.pos[0] = myblock.pos[0];
    temp.pos[1] = myblock.pos[1];
    temp.type = myblock.type;
    temp.rotate = myblock.rotate;
	return temp;
}
