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
    setWindowTitle("Snake!");
    //change background
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
    
    //Set background music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/GuileTheme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music->setPlaylist(playlist);
    music->play();
    
    //Reset score
    score = new Score();

    //Add Item To Scene
    scene->addItem(snake);
    scene->addItem(score);

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
