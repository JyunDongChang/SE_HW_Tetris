#pragma once
#include "controller.h"
#include "model.h"

class controller;
class model;
class view
{
public:
	view() { ; }
	void set(model* m, controller* c) { mycontroller = c;mymodel = m; }
	virtual void paint() = 0;
	void input();
	void gameover();
protected:
	model* mymodel;
	controller* mycontroller;
};
//��{�C�ӤH��view�h
class view_1:public view
{
public:
	void paint();
private:

};
