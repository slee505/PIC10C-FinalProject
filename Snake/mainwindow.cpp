#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include<QGraphicsScene>
#include"snake.h"
#include<QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Snek");
    /*QPixmap background("/Users/stephenlee/Documents/Snake/Snake/Snek.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*GameWindow  gamewindow;
    gamewindow.setModal(true);
    gamewindow.exec();*/

    //Create a scene
    QGraphicsScene * scene = new QGraphicsScene;

    //Create snake
    Snake * snake = new Snake;

    //Add Item To Scene
    scene->addItem(snake);

    //Make snake focused
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();

    //View
    QGraphicsView * board = new QGraphicsView(scene);
    board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->show();
    hide();
}
