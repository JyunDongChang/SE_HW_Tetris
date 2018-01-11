#pragma once
#include "model.h"
#include "view.h"

class model;
class view_2;
typedef view_2 view_controller;

class controller
{
public:
	controller();
	~controller();
	int startgame();
private:
	model* mymodel;
    view_controller* myview;
};
