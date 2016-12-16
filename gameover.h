#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include<QFile>
#include<QString>
#include<QTextStream>
#include<iostream>
#include"leaderboard.h"

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0);
    ~GameOver();

private slots:
    //function when the enter button is clicked
    void on_pushButton_2_clicked();

private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
