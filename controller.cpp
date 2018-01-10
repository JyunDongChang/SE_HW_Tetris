#include "controller.h"

controller::controller()
{
	mymodel = new model;
    myview = new view;
    //这边要是view_1
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
    myview->show();
	return 0;
}
