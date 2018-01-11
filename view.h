﻿#pragma once
#include "controller.h"
#include "model.h"
#include <QFrame>
#include <QPointer>
#include <QBasicTimer>
#include <iostream>

class QLCDNumber;
class QLabel;
class QPushButton;
class controller;
class model;
class view :public QFrame
{
    Q_OBJECT
public:
        view() { ; }
        void Tetrisrepaint(model* newModel);
        void set(model* m, controller* c) { mycontroller = c;mymodel = m; }
        void setNextPieceLabel(QLabel *label);
        void gameover();
        void showNextPiece();
        void drawSquare(QPainter &painter, int x, int y,int shapeIndex);
        int squareWidth() { return contentsRect().width() / 10; }
        int squareHeight() { return contentsRect().height() / 20; }

signals:
    void scoreChanged(int score);

private:
        void keyPressEvent(QKeyEvent *event) override;
        void paintEvent(QPaintEvent *event) override;
        QPointer<QLabel> nextPieceLabel;
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
        void setmodel(){board->set(mymodel,mycontroller);}
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
        void paintEvent(QPaintEvent *event) override{;}
};

class view_2 : public view
{
        Q_OBJECT

public:
        view_2();
        void showNext(){board->showNextPiece();}
        void setmodel(){board->set(mymodel,mycontroller);}
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
        void paintEvent(QPaintEvent *event) override{;}
};

class view_3 : public view
{
        Q_OBJECT

public:
        view_3();
        void showNextPiece();
        void setmodel(){board->set(mymodel,mycontroller);}
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
        void paintEvent(QPaintEvent *event) override{;}
};

class view_4 : public view
{
        Q_OBJECT

public:
        view_4();
        void showNextPiece();
        void setmodel(){board->set(mymodel,mycontroller);}
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
        void paintEvent(QPaintEvent *event) override{;}
};

class view_5 : public view
{
        Q_OBJECT

public:
        view_5();
        void showNextPiece();
        void setmodel(){board->set(mymodel,mycontroller);}
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
        void paintEvent(QPaintEvent *event) override{;}
};
