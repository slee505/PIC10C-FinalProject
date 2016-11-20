#include "gamewindow.h"
#include "ui_gamewindow.h"
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsView>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //Create a scene
    QGraphicsScene * scene = new QGraphicsScene;
    //Create snake
    QGraphicsRectItem * snake = new QGraphicsRectItem;
    snake->setRect(0,0,5,5);
    //Add Item To Scene
    scene->addItem(snake);
    //View
    QGraphicsView * board = new QGraphicsView(scene);
    board->show();

}

GameWindow::~GameWindow()
{
    delete ui;
}
