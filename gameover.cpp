#include "gameover.h"
#include "mainwindow.h"
#include "ui_gameover.h"
#include <QMessageBox>

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

void GameOver::on_lineEdit_editingFinished()
{
    ui->lineEdit->text();
}

void GameOver::on_pushButton_2_clicked()
{
    QFile scores("scores.txt");

    if(!scores.open(QFile::WriteOnly | QFile::Append)){
        QMessageBox::warning(this, "Error", "Something went wrong with the input");
    }
    QTextStream out(&scores);
    QString name = ui->lineEdit->text();
    int gameScore = game->score->getScore();
    out << name << " " << gameScore << "\n";

    scores.flush();
    scores.close();

    hide();


    leaderboard * Leaderboard = new leaderboard();
    Leaderboard->show();

}
