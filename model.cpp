#include "model.h";
#include "view.h";
#include "controller.h"

void model::setgame()
{
	tetris = new int*[column];
	for (int i = 0;i < column;i++)
		tetris[i] = new int[row];
	//��ʼ����Ϸ�趨
	//EX:�趨��ʼ�����ٶȣ���ʼmainloop֮���

	//�趨������view����Ϸ���滭����
	myview->paint();
}

void model::tetris_move(int direction)
{
	myblock;
	tetris;
	//����ָ��ȥ����next��pos
	//ע��tetris��ԭ�����ж����ĵط�
	//���Ѿ��޷�����׹���nextblock��myblock;
	bool can_fall=false;
	if (can_fall)
	{
		myblock = nextblock;
		//randomһ����block��nextblock
		//pos�ǵ��趨
	}
	//�����
	checkline();
}

void model::tetris_rotate()
{
	//ͬmove
}

void model::tetris_fall()
{
	//ͬmove
}

void model::mainloop()
{
	//ÿ��ִ�У�����myblock
	//QObject���ṩ��ʱ�ڵĹ��ܡ��붨ʱ����صĺ�ʽ�У�startTimer()��timeEvent()��killTimer()
	//�����һ��
	checkline();
	//Ȼ����ȥȷ��
	checkfloar();
}

void model::checkline()
{
	//�����û�ж����������оͼӷ�
	score++;
	//���������»�
	myview->paint();
}

void model::checkfloar()
{
	//���tetris[]�ǲ���ײ���컨����
	if (true)
	{
		//�ص�timer
		//endgame
		//��stopҪstop
		//tetris�ǵ�delete
	}
}
