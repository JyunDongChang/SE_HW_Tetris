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
	int pos;//現在這個block對應到整個畫面的座標，以左上為基準去計算
	int cell[9];
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
	//每一個橫排有10個
	//總共有20個橫排高
	int** tetris;
	int score = 0;
	block myblock;//現在拿著的block
	block nextblock;//下一個
};