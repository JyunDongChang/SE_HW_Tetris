#pragma once
#include "controller.h"
#include "view.h"
class controller;
class view;

#define row 10
#define column 20
#define right 0
#define left 1
#define down 2
struct block
{
	int pos;//现在这个block对应到整个画面的哪里，以左上为基准去算座标
	int cell[9];
};
//  ____ ____ ____
// |pos | 1  | 2  |
//  －－ －－ －－
// | 3  | 4  | 5  |
//  －－ －－ －－
// | 6  | 7  | 8  |
//  －－ －－ －－
// 十字的话这样
//  ____ ____ ____
// |    |true|    |
//  －－ －－ －－
// |true|true|true|
//  －－ －－ －－
// |    |true|    |
//  －－ －－ －－
// 以后可以改放其他数字，来区分颜色
// 现在先用bool区分有没有就好
class model
{
public:
	model() { ; }
	void set(view* v, controller* c) { myview = v;mycontroller = c; }
	void setgame();
	void tetris_move(int direction);
	void tetris_rotate();
	void tetris_fall();

	int getscore() { return score; }
	int** gettetris() {return tetris; }
	block getnextTetris() { return nextblock; }
	block getTetris() { return myblock; }
private:
	view* myview;
	controller* mycontroller;

	//
	void mainloop();
	void checkline();
	void checkfloar();
	//每一个横排有10个
	//总共有20个横排高
	int** tetris;
	int score = 0;
	block myblock;//现在拿著的block
	block nextblock;//下一个
};