#pragma once
#include "controller.h"
#include "model.h"
#include <QFrame>
#include <QPointer>
#include <QBasicTimer>

class QLCDNumber;
class QLabel;
class QPushButton;
class controller;
class model;
class view :public QFrame
{
public:
        view() { ; }
        void set(model* m, controller* c) { mycontroller = c;mymodel = m; }
        virtual void paint();
        void gameover();
        void drawSquare(QPainter &painter, int x, int y);
        int squareWidth() { return contentsRect().width() / 10; }
        int squareHeight() { return contentsRect().height() / 20; }
private:
        void keyPressEvent(QKeyEvent *event) override;
protected:
        model* mymodel;
        controller* mycontroller;
};
//
class view_1 : public view
{
        Q_OBJECT

public:
        view_1();

private:
        QLabel *createLabel(const QString &text);

        view *board;
        QLabel *nextPieceLabel;
        QLCDNumber *scoreLcd;
        QLCDNumber *levelLcd;
        QLCDNumber *linesLcd;
        QPushButton *startButton;
        QPushButton *quitButton;
        QPushButton *pauseButton;
};
