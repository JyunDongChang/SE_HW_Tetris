#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    controller startGame;
    startGame.startgame();
    return app.exec();
}
