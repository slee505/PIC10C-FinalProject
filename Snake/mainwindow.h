#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include<QGraphicsView>
#include<QGraphicsScene>
#include"snake.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene = new QGraphicsScene(0, 0, 600, 600);
    QGraphicsView * board = new QGraphicsView(scene);
    QTimer * timer = new QTimer;
};

#endif // MAINWINDOW_H
