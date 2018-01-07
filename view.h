#pragma once
#include "controller.h"
#include "model.h"
#include <QFrame>
#include <QWidget>
class QLCDNumber;
class QLabel;
class QPushButton;
class controller;
class model;
class view
{
public:
	view() { ; }
	void set(model* m, controller* c) { mycontroller = c;mymodel = m; }
	virtual void paint() = 0;
	void input();
	void gameover();
protected:
	model* mymodel;
	controller* mycontroller;
};
//實現每個人的view去
class view_1 : public QWidget
{
	Q_OBJECT

public:
	TetrixWindow();

private:
	QLabel *createLabel(const QString &text);

	TetrixBoard *board;
	QLabel *nextPieceLabel;
	QLCDNumber *scoreLcd;
	QLCDNumber *levelLcd;
	QLCDNumber *linesLcd;
	QPushButton *startButton;
	QPushButton *quitButton;
	QPushButton *pauseButton;
};
