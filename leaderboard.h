#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QWidget>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "mainwindow.h"

namespace Ui {
class leaderboard;
}

class leaderboard : public QWidget
{
    Q_OBJECT

public:
    explicit leaderboard(QWidget *parent = 0);
    ~leaderboard();
    void sortScore();

private slots:
    void on_pushButton_clicked();

private:
    Ui::leaderboard *ui;
};

#endif // LEADERBOARD_H
