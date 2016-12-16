#ifndef SNAKE_H
#define SNAKE_H
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QTimer>
#include<QObject>
#include <QList>
#include<string>
#include<stdlib.h>
#include "snakebody.h"
#include"food.h"
#include"gameover.h"
#include<QBrush>
#include<algorithm>

class Snake : public QObject, public QGraphicsRectItem{
        Q_OBJECT
public:
    Snake();
    void keyPressEvent(QKeyEvent * event);
    void grow();
    void move();
    void disconnectAll();
    void checkForCollision();
    void WallCollision();
    void eat();
    int PrevX;
    int PrevY;
private:
    QList<snakeBody*> body;
    std::string currentDirection = "right";
    QTimer * timer = new QTimer;
public slots:
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // SNAKE_H
