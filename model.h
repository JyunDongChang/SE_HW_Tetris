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
	int pos;//�������block��Ӧ��������������������Ϊ��׼ȥ������
	int cell[9];
};
//  ____ ____ ____
// |pos | 1  | 2  |
//  ���� ���� ����
// | 3  | 4  | 5  |
//  ���� ���� ����
// | 6  | 7  | 8  |
//  ���� ���� ����
// ʮ�ֵĻ�����
//  ____ ____ ____
// |    |true|    |
//  ���� ���� ����
// |true|true|true|
//  ���� ���� ����
// |    |true|    |
//  ���� ���� ����
// �Ժ���Ըķ��������֣���������ɫ
// ��������bool������û�оͺ�
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
	//ÿһ��������10��
	//�ܹ���20�����Ÿ�
	int** tetris;
	int score = 0;
	block myblock;//����������block
	block nextblock;//��һ��
};