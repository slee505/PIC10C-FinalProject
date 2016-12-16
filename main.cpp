#include "mainwindow.h"
#include "food.h"
#include <QApplication>

MainWindow * game;
Food * food;

//open new game window and show it
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new MainWindow();
    game->show();

    return a.exec();
}
