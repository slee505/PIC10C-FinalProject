#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"snake.h"
#include"snakebody.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Snek Eater");
    QPalette * palette = new QPalette();
    palette->setBrush(QPalette::Window, QPixmap(":/images/Snake.jpg"));
    this->setPalette(*palette);
    this->setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Create snake
    Snake * snake = new Snake;
    snake->setPos(150,150);

    music->setMedia(QUrl("qrc:/sounds/Metal Gear Solid OST - OST.mp3"));
    music->play();

    //Add Item To Scene
    scene->addItem(snake);

    //Make snake focused
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();

    //View
    board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->resize(300,300);
    board->show();


    hide();
}
