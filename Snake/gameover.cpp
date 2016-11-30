#include "gameover.h"
#include "mainwindow.h"
#include "ui_gameover.h"

extern MainWindow * game;

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    game = new MainWindow();
    game->show();
    hide();
}
