#include "mainwindow.h"
#include "gamelogic.h"
#include <QApplication>

//Github link: https://github.com/Tomas-Deane/zorkcpp

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameLogic gameLogic; // instance of GameLogic
    MainWindow w(nullptr, &gameLogic); // Pass GL to MainWindow


    w.show();
    return a.exec();
}

