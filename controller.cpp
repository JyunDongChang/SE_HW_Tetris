#include "controller.h"

controller::controller()
{
	mymodel = new model;
    myview = new view_1;
	mymodel->set(myview, this);
	myview->set(mymodel, this);
    myview->setmodel();
}

controller::~controller()
{
	delete mymodel;
	delete myview;
}

int controller::startgame()
{
	mymodel->setgame();
    myview->show();
	return 0;
}
