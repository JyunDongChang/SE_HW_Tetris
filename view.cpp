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
	switch (event->key()) {
	case Qt::Key_Left:
		mymodel->tetris_move(left_move)
		break;
	case Qt::Key_Right:
		mymodel->tetris_move(right);
		break;
	case Qt::Key_Down:
		mymodel->tetris_fall();
		break;
	case Qt::Key_Up:
		mymodel->tetris_rotate(right);
		break;
	case Qt::Key_Space:
		break;
	case Qt::Key_D:
		oneLineDown();
		break;
	default:
		QFrame::keyPressEvent(event);
	}
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
view_1::TetrixWindow()
{
	board = new TetrixBoard;

	nextPieceLabel = new QLabel;
	nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
	nextPieceLabel->setAlignment(Qt::AlignCenter);
	board->setNextPieceLabel(nextPieceLabel);

	scoreLcd = new QLCDNumber(5);
	scoreLcd->setSegmentStyle(QLCDNumber::Filled);
	levelLcd = new QLCDNumber(2);
	levelLcd->setSegmentStyle(QLCDNumber::Filled);
	linesLcd = new QLCDNumber(5);
	linesLcd->setSegmentStyle(QLCDNumber::Filled);

	startButton = new QPushButton(tr("&Start"));
	startButton->setFocusPolicy(Qt::NoFocus);
	quitButton = new QPushButton(tr("&Quit"));
	quitButton->setFocusPolicy(Qt::NoFocus);
	pauseButton = new QPushButton(tr("&Pause"));
	pauseButton->setFocusPolicy(Qt::NoFocus);

	connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
	connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
	connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
	connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
	connect(board, SIGNAL(linesRemovedChanged(int)),
		linesLcd, SLOT(display(int)));

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(createLabel(tr("NEXT")), 0, 0);
	layout->addWidget(nextPieceLabel, 1, 0);
	layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
	layout->addWidget(levelLcd, 3, 0);
	layout->addWidget(startButton, 4, 0);
	layout->addWidget(board, 0, 1, 6, 1);
	layout->addWidget(createLabel(tr("SCORE")), 0, 2);
	layout->addWidget(scoreLcd, 1, 2);
	layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
	layout->addWidget(linesLcd, 3, 2);
	layout->addWidget(quitButton, 4, 2);
	layout->addWidget(pauseButton, 5, 2);
	setLayout(layout);

	setWindowTitle(tr("Tetrix"));
	resize(550, 370);

	//�̾�Model����Ƶe�X�ӹC���e��
	//�i�H�Ҽ{�bview���g�nPaintScore(�y��) PaintNextBlock(�y��)������
	//�M��o��N�ǤJ���P���ѼƴN�i�H�ܧ�F
	//��M���٨S��qt�A���M���o�{�ꤣ�{��
}

QLabel *view_1::createLabel(const QString &text)
{
	QLabel *lbl = new QLabel(text);
	lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	return lbl;
}/*
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
*/