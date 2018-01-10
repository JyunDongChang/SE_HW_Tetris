#include "controller.h"

controller::controller()
{
	mymodel = new model;
    myview = new view;
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
