#include "model.h";
#include "view.h";
#include "controller.h"

void view::paint()
{
}
void view::input()
{
	//����ˢ��ץinput(qtץ���̵�event��������ע�����)
	//ץ������controller
	int direct=0;
	if (direct == right)//���ݽ����������ָ��
	{
		mymodel->tetris_move(right);//����λ��
		//mymodel->tetris_rotate(right);//˳ʱ����ת
		//mymodel->tetris_fall();//ֱ������
	}
	//model.h�ж��巽�����ӿɶ���������defineȥд����������
	//#define right 0
	//#define left 1
	//#define down 2

	/*
	// ��ȻҪinclude qt��Щ�е�û���
	// ���̰����¼�

	void Widget::keyPressEvent(QKeyEvent *event)
	{
	// �Ƿ���Ctrl��      ���ⰴ��
	if (event->modifiers() == Qt::ControlModifier) {
	// �Ƿ���M��    ��ͨ����  ����
	if (event->key() == Qt::Key_M)
	������
	}
	else QWidget::keyPressEvent(event);   //����Ĭ���¼�
	//����Ǵ���������ͨ�������ñ����Զ��ظ����ͷ���ҲҪ����
	if (event->key() == Qt::Key_Up) {
	// �����ظ�ʱ��������
	if (event->isAutoRepeat()) return;
	// ������Ϸ�����Ѿ�����
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
	//�����м仭��"Game Over"��text
	//��ȻԸ��ȥŪ��ͼ����õ�
}
/*void view::repaint()
{
	//������Ȼ���ػ�
	//���ܺ�init���ƣ�
}*/

void view_1::paint()
{
	mymodel->getTetris();
	mymodel->getnextTetris();
	mymodel->getscore();
	mymodel->gettetris();
	//����model�����ϻ�������Ϸ����
	//���Կ�����view��д��PaintScore(����) PaintNextBlock(����)֮���
	//Ȼ����߾ʹ��벻ͬ�Ĳ����Ϳ��Ա����
	//��Ȼ�һ�û��qt�����������ʵ����ʵ
}