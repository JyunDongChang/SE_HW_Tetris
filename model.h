#pragma once
#include "controller.h"
#include "view.h"
#include <QObject>
#include <QTimer>
class controller;
class view;

#define tetrisRow 10
#define tetrisColumn 20
#define right_move 0
#define left_move 1
#define right_rotate 2
#define left_rotate 3
#define down 4
#define tetrisStorage 5
struct block
{
    int pos[2] = {0};//現在這個block對應到整個畫面的座標，以左上為基準去計算
    int cell[4][4] = {{0},{0}};//改成4*4
	int type, rotate;
};
//  ____ ____ ____
// |pos | 1  | 2  |
//  －－ －－ －－
// | 3  | 4  | 5  |
//  －－ －－ －－
// | 6  | 7  | 8  |
//  －－ －－ －－
// 十字的話這樣
//  ____ ____ ____
// |    |true|    |
//  －－ －－ －－
// |true|true|true|
//  －－ －－ －－
// |    |true|    |
//  －－ －－ －－
// 以後可以改放其他數字，來區分顏色
// 現在先用bool區分有沒有就好
class model : public QObject
{
    Q_OBJECT
public:
    model(){;}
    void set(view* v, controller* c) { myview = v; mycontroller = c; }
	void setgame();
	void tetris_move(int direction);
	void tetris_rotate(int direction);
	void tetris_storage();
    void tetris_fall();

	int getscore() { return score; }
	int** gettetris() { return tetris; }
	block getnextTetris() { return nextblock; }
	block getstorageTetris() { return storageblock; }
	block getTetris() { return myblock; }
    int gettest(){return test;}
public slots:
    void mainloop();

private:
    view* myview;
	controller* mycontroller;
	//

	void checkline();
    bool checkfloar();
	//將更改後的block丟進來先判斷是否會出現 1.超界 2.重疊原始資料
    bool checkintetris(block input);
	//將確認能繪製進主tetris的myblock填入tetris
	void paintintetris();
	void setoriginalshape();
	block createnewpeace();
    block copyablock(block input);
	block copyrotateblock();
	//每一個橫排有10個
	//總共有20個橫排高
	int** tetris;
	float level;
	int fallSpeed;
    int score=100;
    bool inTurnChangeTime = false;
	block myblock;//現在拿著的block
	block nextblock;//下一個
	block storageblock;
    block originalshape[7][4];
    QTimer *timer;
    int test=5;
};
