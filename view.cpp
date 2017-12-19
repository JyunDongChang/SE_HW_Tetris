#include "model.h";
#include "view.h";
#include "controller.h"

void view::paint()
{
}
void view::input()
{
	//不斷刷新抓input(qt抓鍵盤的event看最下面註解掉的)
	//抓到丟給controller
	int direct=0;
	if (direct == right)//根據解讀出來的下指令
	{
		mymodel->tetris_move(right);//左右位移
		//mymodel->tetris_rotate(right);//順時鐘旋轉
		//mymodel->tetris_fall();//直接落下
	}
	//model.h有定義方向，增加可讀性請用這define去寫例子如上
	//#define right 0
	//#define left 1
	//#define down 2

	/*
	// 當然要include qt那些有的沒有的喔
	// 鍵盤按下事件

	void Widget::keyPressEvent(QKeyEvent *event)
	{
	// 是否按下Ctrl鍵 特殊按鍵
	if (event->modifiers() == Qt::ControlModifier) {
	// 是否按下M鍵 普通案鍵 類似
	if (event->key() == Qt::Key_M)
	...
	}
	else QWidget::keyPressEvent(event);   //保存默認事件
	// 如果是處理兩個普通按鍵，得避免自動重複，釋放中也要處理
	if (event->key() == Qt::Key_Up) {
	// 案件重複時不做處理
	if (event->isAutoRepeat()) return;
	// 標記向上方向鍵已經按下
	keyUp = true;
	}
	else if (event->key() == Qt::Key_Left) {
	if (event->isAutoRepeat()) return;
	keyLeft = true;
	}
	*/
}
void view::gameover()
{
	//在正中間畫個"Game Over"的text
	//當然願意去弄貼圖是最好的
}
/*void view::repaint()
{
	//拿資料然後重畫
	//可能和init類似
}*/

void view_1::paint()
{
	mymodel->getTetris();
	mymodel->getnextTetris();
	mymodel->getscore();
	mymodel->gettetris();
	//依據Model的資料畫出來遊戲畫面
	//可以考慮在view先寫好PaintScore(座標) PaintNextBlock(座標)之類的
	//然後這邊就傳入不同的參數就可以變更了
	//當然我還沒看qt，不清楚這現實不現實
}