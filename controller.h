#pragma once
#include "model.h"
#include "view.h"

class model;
class view_1;
class controller
{
public:
	controller();
	~controller();
	int startgame();
private:
	model* mymodel;
    view_1* myview;
};
