#include "model.h";
#include "view.h";
#include "controller.h"

void view::paint()
{
}
void view::input()
{
	//���_��s��input(qt����L��event�ݳ̤U�����ѱ���)
	//���ᵹcontroller
	int direct=0;
	if (direct == right)//�ھڸ�Ū�X�Ӫ��U���O
	{
		mymodel->tetris_move(right);//���k�첾
		//mymodel->tetris_rotate(right);//����������
		//mymodel->tetris_fall();//�������U
	}
	//model.h���w�q��V�A�W�[�iŪ�ʽХγodefine�h�g�Ҥl�p�W
	//#define right 0
	//#define left 1
	//#define down 2

	/*
	// ��M�ninclude qt���Ǧ����S������
	// ��L���U�ƥ�

	void Widget::keyPressEvent(QKeyEvent *event)
	{
	// �O�_���UCtrl�� �S�����
	if (event->modifiers() == Qt::ControlModifier) {
	// �O�_���UM�� ���q���� ����
	if (event->key() == Qt::Key_M)
	...
	}
	else QWidget::keyPressEvent(event);   //�O�s�q�{�ƥ�
	// �p�G�O�B�z��Ӵ��q����A�o�קK�۰ʭ��ơA���񤤤]�n�B�z
	if (event->key() == Qt::Key_Up) {
	// �ץ󭫽Ʈɤ����B�z
	if (event->isAutoRepeat()) return;
	// �аO�V�W��V��w�g���U
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
	//�b�������e��"Game Over"��text
	//��M�@�N�h�˶K�ϬO�̦n��
}
/*void view::repaint()
{
	//����ƵM�᭫�e
	//�i��Minit����
}*/

void view_1::paint()
{
	mymodel->getTetris();
	mymodel->getnextTetris();
	mymodel->getscore();
	mymodel->gettetris();
	//�̾�Model����Ƶe�X�ӹC���e��
	//�i�H�Ҽ{�bview���g�nPaintScore(�y��) PaintNextBlock(�y��)������
	//�M��o��N�ǤJ���P���ѼƴN�i�H�ܧ�F
	//��M���٨S��qt�A���M���o�{�ꤣ�{��
}