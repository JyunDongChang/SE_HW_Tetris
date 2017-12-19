#include "model.h";
#include "view.h";
#include "controller.h"

void model::setgame()
{
	tetris = new int*[column];
	for (int i = 0;i < column;i++)
		tetris[i] = new int[row];
	//初始化遊戲設定
	//EX:設定初始掉落速度，開始mainloop之類的

	//設定完後就讓view把遊戲畫面畫出來
	myview->paint();
}

void model::tetris_move(int direction)
{
	myblock;
	tetris;
	//根據指令去更動next的pos
	//注意tetris中原本就有東西的地方
	//若已經無法再下墜則把nextblock給myblock
	bool can_fall=false;
	if (can_fall)
	{
		myblock = nextblock;
		//random一個新block給nextblock
		//pos記得設定
	}
	//做完後
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
	//每秒執行，調降myblock
	//QObject類提供時期的功能。與定時相關的函示有:startTimer()、timeEvent()、killTimer()
	//做完後一樣
	checkline();
	//然後再去確認
	checkfloar();
}

void model::checkline()
{
	//檢查有沒有東西能消，有就加分
	score++;
	//檢查完就重新畫
	myview->paint();
}

void model::checkfloar()
{
	//檢查tetris[]是不是撞上天花板了
	if (true)
	{
		//關掉timer
		//endgame
		//該stop要stop
		//tetris記得delete
	}
}
