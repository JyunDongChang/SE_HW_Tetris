#pragma once
#include "model.h"
#include "view.h"

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
