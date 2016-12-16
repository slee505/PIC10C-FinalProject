#include "gameover.h"
#include "mainwindow.h"
#include "ui_gameover.h"
#include <QMessageBox>

//global game variable
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

//Enters player name and leads to leaderboard
void GameOver::on_pushButton_2_clicked()
{
    //open a file of past scores
    QFile scores("scores.txt");
    
    //check for file being open
    if(!scores.open(QFile::WriteOnly | QFile::Append)){
        QMessageBox::warning(this, "Error", "Something went wrong with the input");
    }
    
    //Text stream to input scores
    QTextStream out(&scores);
    
    //Input the text entered in the lineEdit
    QString name = ui->lineEdit->text();
    int gameScore = game->score->getScore();
    
    //combines score with name and inputs it into file
    out << name << " " << gameScore << "\n";

    scores.flush();
    scores.close();

    hide();


    leaderboard * Leaderboard = new leaderboard();
    Leaderboard->show();

}
