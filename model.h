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
	int pos;//�{�b�o��block�������ӵe�����y�СA�H���W����ǥh�p��
	int cell[9];
};
//  ____ ____ ____
// |pos | 1  | 2  |
//  �С� �С� �С�
// | 3  | 4  | 5  |
//  �С� �С� �С�
// | 6  | 7  | 8  |
//  �С� �С� �С�
// �Q�r���ܳo��
//  ____ ____ ____
// |    |true|    |
//  �С� �С� �С�
// |true|true|true|
//  �С� �С� �С�
// |    |true|    |
//  �С� �С� �С�
// �H��i�H����L�Ʀr�A�ӰϤ��C��
// �{�b����bool�Ϥ����S���N�n
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
	//�C�@�Ӿ�Ʀ�10��
	//�`�@��20�Ӿ�ư�
	int** tetris;
	int score = 0;
	block myblock;//�{�b���۪�block
	block nextblock;//�U�@��
};