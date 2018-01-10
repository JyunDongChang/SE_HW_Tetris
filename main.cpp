#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //view_1 myView;
    //myView.show();
    controller startGame;
    startGame.startgame();
    return app.exec();
}
