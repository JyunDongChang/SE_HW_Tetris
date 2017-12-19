#include "model.h";
#include "view.h";
#include "controller.h"

void view::paint()
{
}
void view::input()
{
	//不断刷新抓input(qt抓键盘的event看最下面注解掉的)
	//抓到丢给controller
	int direct=0;
	if (direct == right)//根据解读出来的下指令
	{
		mymodel->tetris_move(right);//左右位移
		//mymodel->tetris_rotate(right);//顺时钟旋转
		//mymodel->tetris_fall();//直接落下
	}
	//model.h有定义方向，增加可读性请用这define去写，例子如上
	//#define right 0
	//#define left 1
	//#define down 2

	/*
	// 当然要include qt那些有的没的喔
	// 键盘按下事件

	void Widget::keyPressEvent(QKeyEvent *event)
	{
	// 是否按下Ctrl键      特殊按键
	if (event->modifiers() == Qt::ControlModifier) {
	// 是否按下M键    普通按键  类似
	if (event->key() == Qt::Key_M)
	···
	}
	else QWidget::keyPressEvent(event);   //保存默认事件
	//如果是处理两个普通按键，得避免自动重复，释放中也要处理
	if (event->key() == Qt::Key_Up) {
	// 按键重复时不做处理
	if (event->isAutoRepeat()) return;
	// 标记向上方向键已经按下
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
	//在正中间画个"Game Over"的text
	//当然愿意去弄贴图是最好的
}
/*void view::repaint()
{
	//拿资料然后重画
	//可能和init类似？
}*/

void view_1::paint()
{
	mymodel->getTetris();
	mymodel->getnextTetris();
	mymodel->getscore();
	mymodel->gettetris();
	//依据model的资料画出来游戏画面
	//可以考虑在view先写好PaintScore(座标) PaintNextBlock(座标)之类的
	//然后这边就传入不同的参数就可以变更了
	//当然我还没看qt，不清楚这现实不现实
}