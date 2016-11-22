#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsScene>
#include"snake.h"
#include<QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Snek");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Create snake
    Snake * snake = new Snake;
    snake->setPos(300,300);

    //Add Item To Scene
    scene->addItem(snake);

    //Make snake focused
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();

    //View
    board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->resize(600,600);
    board->show();


    hide();
}
