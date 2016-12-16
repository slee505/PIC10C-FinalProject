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
    //defines behavior for arrow key presses
    void keyPressEvent(QKeyEvent * event);
    //increase snake size
    void grow();
    //keeps snake moving
    void move();
    //disconnects movement slots
    void disconnectAll();
    //checks for collision with snake body
    void checkForCollision();
    //checks for collision with wall
    void WallCollision();
    //defines behavior for eating food
    void eat();
        
    //int values for previous positions
    int PrevX;
    int PrevY;
private:
    //list of positions of snake's body
    QList<snakeBody*> body;
    //set starting direction to right
    std::string currentDirection = "right";
    QTimer * timer = new QTimer;
public slots:
    //directional slots
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // SNAKE_H
