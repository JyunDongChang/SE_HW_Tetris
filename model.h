#pragma once
#include "controller.h"
#include "view.h"
class controller;
class view;

#define row 10
#define column 20
#define right_move 0
#define left_move 1
#define right_rotate 2
#define left_rotate 3
#define down 4
#define storage 5
struct block
{
	int pos[2];//�{�b�o��block�������ӵe�����y�СA�H���W����ǥh�p��
	int cell[4][4];//�令4*4
	int type, rotate;
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
private:
	view* myview;
	controller* mycontroller;

	//
	void mainloop();
	void checkline();
	void checkfloar();
	//�N���᪺block��i�ӥ��P�_�O�_�|�X�{ 1.�W�� 2.���|��l���
	bool checkintetris();
	//�N�T�{��ø�s�i�Dtetris��myblock��Jtetris
	void paintintetris();
	void setoriginalshape();
	block createnewpeace();
	block copyablock();
	block copyrotateblock();
	//�C�@�Ӿ�Ʀ�10��
	//�`�@��20�Ӿ�ư�
	int** tetris;
	float level;
	int fallSpeed;
	int score = 0;
	bool inTurnChangeTime;
	block myblock;//�{�b���۪�block
	block nextblock;//�U�@��
	block storageblock;
	block** originalshape;
	QTimer timer;
};