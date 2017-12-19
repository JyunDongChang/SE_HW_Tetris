#include "model.h";
#include "view.h";
#include "controller.h"

controller::controller()
{
	mymodel = new model;
	myview = new view_1;
	mymodel->set(myview, this);
	myview->set(mymodel, this);
}

controller::~controller()
{
	delete mymodel;
	delete myview;
}

int controller::startgame()
{
	mymodel->setgame();
	return 0;
}
