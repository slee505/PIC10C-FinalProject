#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QMediaPlayer>
#include<QBrush>
#include<QImage>
#include<QPixmap>
#include<QPalette>
//#include<QPaintEvent>
#include<QMediaPlaylist>
#include"snake.h"
#include"food.h"
#include"score.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QGraphicsScene * scene = new QGraphicsScene(0, 0, 300, 300);
    QGraphicsView * board = new QGraphicsView(scene);
    QMediaPlayer * music = new QMediaPlayer();
    Score * score;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer = new QTimer;
};

#endif // MAINWINDOW_H
