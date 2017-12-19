#pragma once


class model;
class view;
class controller
{
public:
	controller();
	~controller();
	int startgame();
private:
	model* mymodel;
	view* myview;
};