#include "view.h"
#include <QtWidgets>
void view_1::showNextPiece()
{/*
  if (!nextPieceLabel)
            return;
  block next = mymodel->getnextTetris();
        QPixmap pixmap(4 * squareWidth(), 4 * squareHeight());
        QPainter painter(&pixmap);
        painter.fillRect(pixmap.rect(), nextPieceLabel->palette().background());

        for (int i = 0; i < 4; ++i) {
           for(int j=0;j<4;++j){
                if(next.cell[i][j])
                    drawSquare(painter,(next.pos[0]+i) * squareWidth(),(next.pos[1]+j - 1) * squareHeight()
                               ,next.cell[i][j]);

                }
        }
    nextPieceLabel->setPixmap(pixmap);*/
}
void view::paintEvent(QPaintEvent *event)
{
    static model* temp;
    if(temp)
    {
       mymodel=temp;
       emit scoreChanged(temp->getscore());//預計要寫mymodel->getscore()
    }
    else
    {
       temp=mymodel;
       emit scoreChanged(mymodel->getscore());//預計要寫mymodel->getscore()
    }

    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect rect = contentsRect();

//    if (isPaused) {
//        painter.drawText(rect, Qt::AlignCenter, tr("Pause"));
//        return;
//    }

    block curPiece=mymodel->getTetris();
    block shapePiece=mymodel->getshapeTetris();
    int ** tetrisBoard= mymodel->gettetris();
    int boardTop = rect.bottom() - tetrisColumn*squareHeight();

    for (int i = 0; i <tetrisRow ; ++i) {
        for (int j = 0; j <tetrisColumn ; ++j) {
            //TetrixShape shape = shapeAt(j, BoardHeight - i - 1);
            //printf("test\n");
            if (tetrisBoard[i][j])
                drawSquare(painter, rect.left() + i * squareWidth(),
                           boardTop + j * squareHeight(),tetrisBoard[i][j]);
           // printf("Error\n");
        }
    }

// 這裡是在畫目前的方塊

    for (int i = 0; i < 4; ++i) {
       for(int j=0;j<4;++j){
            if(shapePiece.cell[i][j])
                drawSquare(painter, rect.left() + (shapePiece.pos[0]+i) * squareWidth(),
                       boardTop + (shapePiece.pos[1]+j) * squareHeight(),shapePiece.cell[i][j]);
            }
    }
    for (int i = 0; i < 4; ++i) {
       for(int j=0;j<4;++j){
            if(curPiece.cell[i][j])
                drawSquare(painter, rect.left() + (curPiece.pos[0]+i) * squareWidth(),
                       boardTop + (curPiece.pos[1]+j) * squareHeight(),curPiece.cell[i][j]);
            }
    }



}
void view::keyPressEvent(QKeyEvent *event)
{
	//不斷刷新抓input(qt抓鍵盤的event看最下面註解掉的)
	//抓到丟給controller
	switch (event->key()) {
	case Qt::Key_Left:
        mymodel->tetris_move(left_move);
		break;
	case Qt::Key_Right:
        mymodel->tetris_move(right_move);
		break;
	case Qt::Key_Down:
        mymodel->tetris_Quickfall();
		break;
	case Qt::Key_Up:
        mymodel->tetris_rotate(right_rotate);
		break;
	case Qt::Key_Space:
        mymodel->tetris_fall();
		break;
	case Qt::Key_D:
        mymodel->tetris_storage();
        //oneLineDown();
		break;
	default:
        QFrame::keyPressEvent(event);
	}
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
void view::drawSquare(QPainter &painter, int x, int y,int shapeIndex)
{
    static const QRgb colorTable[9] = {
        0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
        0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00, 0x5B5B5B
    };
    QColor color = colorTable[shapeIndex];

    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
                     color);

    painter.setPen(color.light());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    painter.setPen(color.dark());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidth() - 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + 1);
}
void view::gameover()
{
	//在正中間畫個"Game Over"的text
	//當然願意去弄貼圖是最好的
}
void view::Tetrisrepaint(model* newModel)
{
    mymodel = newModel;
    repaint();
}
view_1::view_1()
{
    board = new view;

	nextPieceLabel = new QLabel;
	nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
	nextPieceLabel->setAlignment(Qt::AlignCenter);
    //board->setNextPieceLabel(nextPieceLabel);

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

    //connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));

	QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
	layout->addWidget(startButton, 4, 0);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 2, 0);
    layout->addWidget(scoreLcd, 3, 0);
    //layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    //layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 5, 0);
    layout->addWidget(pauseButton, 6, 0);
	setLayout(layout);

	setWindowTitle(tr("Tetrix"));
	resize(550, 370);
    //依據Model的資料畫出來遊戲畫面
	//可以考慮在view先寫好PaintScore(座標) PaintNextBlock(座標)之類的
	//然後這邊就傳入不同的參數就可以變更了
	//當然我還沒看qt，不清楚這現實不現實
}
QLabel *view_1::createLabel(const QString &text)
{
	QLabel *lbl = new QLabel(text);
	lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	return lbl;
}

view_2::view_2()
{
    board = new view;

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    //board->setNextPieceLabel(nextPieceLabel);

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

    //connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 1);
    layout->addWidget(nextPieceLabel, 1, 1);
    layout->addWidget(createLabel(tr("SCORE")), 2, 1);
    layout->addWidget(scoreLcd, 3, 1);
    //layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    //layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(startButton, 4, 1);
    layout->addWidget(quitButton, 5, 1);
    layout->addWidget(pauseButton, 6, 1);
    layout->addWidget(board, 0, 0, 6, 1);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
    //依據Model的資料畫出來遊戲畫面
    //可以考慮在view先寫好PaintScore(座標) PaintNextBlock(座標)之類的
    //然後這邊就傳入不同的參數就可以變更了
    //當然我還沒看qt，不清楚這現實不現實
}
QLabel *view_2::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

view_3::view_3()
{
    board = new view;

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    //board->setNextPieceLabel(nextPieceLabel);

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

    //connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(startButton, 7, 0);
    layout->addWidget(board, 2, 1, 8, 1);
    layout->addWidget(createLabel(tr("SCORE")), 0, 1);
    layout->addWidget(scoreLcd, 1, 1);
    //layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    //layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 8, 0);
    layout->addWidget(pauseButton, 9, 0);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
    //依據Model的資料畫出來遊戲畫面
    //可以考慮在view先寫好PaintScore(座標) PaintNextBlock(座標)之類的
    //然後這邊就傳入不同的參數就可以變更了
    //當然我還沒看qt，不清楚這現實不現實
}
QLabel *view_3::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

view_4::view_4()
{
    board = new view;

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    //board->setNextPieceLabel(nextPieceLabel);

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

    //connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 1);
    layout->addWidget(nextPieceLabel, 1, 1);
    layout->addWidget(startButton, 7, 0);
    layout->addWidget(board, 2, 1, 8, 1);
    layout->addWidget(createLabel(tr("SCORE")), 0, 0);
    layout->addWidget(scoreLcd, 1, 0);
    //layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    //layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 8, 0);
    layout->addWidget(pauseButton, 9, 0);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
    //依據Model的資料畫出來遊戲畫面
    //可以考慮在view先寫好PaintScore(座標) PaintNextBlock(座標)之類的
    //然後這邊就傳入不同的參數就可以變更了
    //當然我還沒看qt，不清楚這現實不現實
}
QLabel *view_4::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

view_5::view_5()
{
    board = new view;

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    //board->setNextPieceLabel(nextPieceLabel);

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

    //connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(startButton, 1, 2);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 3, 0);
    layout->addWidget(scoreLcd, 4, 0);
    //layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    //layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 2, 2);
    layout->addWidget(pauseButton, 3, 2);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
    //依據Model的資料畫出來遊戲畫面
    //可以考慮在view先寫好PaintScore(座標) PaintNextBlock(座標)之類的
    //然後這邊就傳入不同的參數就可以變更了
    //當然我還沒看qt，不清楚這現實不現實
}
QLabel *view_5::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}
