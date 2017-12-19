#include "model.h";
#include "view.h";
#include "controller.h"

void model::setgame()
{
	tetris = new int*[column];
	for (int i = 0;i < column;i++)
		tetris[i] = new int[row];
	//初始化游戏设定
	//EX:设定初始掉落速度，开始mainloop之类的

	//设定完后就让view把游戏画面画出来
	myview->paint();
}

void model::tetris_move(int direction)
{
	myblock;
	tetris;
	//根据指令去更动next的pos
	//注意tetris中原本就有东西的地方
	//若已经无法再下坠则把nextblock给myblock;
	bool can_fall=false;
	if (can_fall)
	{
		myblock = nextblock;
		//random一个新block给nextblock
		//pos记得设定
	}
	//做完后
	checkline();
}

void model::tetris_rotate()
{
	//同move
}

void model::tetris_fall()
{
	//同move
}

void model::mainloop()
{
	//每秒执行，调降myblock
	//QObject类提供定时期的功能。与定时器相关的函式有：startTimer()、timeEvent()、killTimer()
	//做完后一样
	checkline();
	//然后再去确认
	checkfloar();
}

void model::checkline()
{
	//检查有没有东西能消，有就加分
	score++;
	//检查完就重新画
	myview->paint();
}

void model::checkfloar()
{
	//检查tetris[]是不是撞上天花板了
	if (true)
	{
		//关掉timer
		//endgame
		//该stop要stop
		//tetris记得delete
	}
}
