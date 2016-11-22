#include "snake.h"
#include <QWidget>

Snake::Snake()
{
    setRect(0,0,10,10);
    connect(timer, SIGNAL(timeout()), this, SLOT(currentPosition()));
    timer->start(50);
    move();
}

void Snake::keyPressEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Left){
        if(currentDirection == "right")
            return;
        currentDirection = "left";
        move();
    }
    else if(event -> key() == Qt::Key_Right){
        if(currentDirection == "left")
            return;
        currentDirection = "right";
        move();
    }
    else if(event -> key() == Qt::Key_Up){
        if(currentDirection == "down")
            return;
        currentDirection = "up";
        move();
    }
    else if(event -> key() == Qt::Key_Down){
        if(currentDirection == "up")
            return;
        currentDirection = "down";
        move();
    }
}

void Snake::move()
{
    if(currentDirection == "left"){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        timer->start(50);
    }
    else if(currentDirection == "right"){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        timer->start(50);
    }
    else if(currentDirection == "up"){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        timer->start(50);
    }
    else if(currentDirection == "down"){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        timer->start(50);
    }
}

int Snake::xPos()
{
    return xPosition;
}

int Snake::yPos()
{
    return yPosition;
}

void Snake::currentPosition()
{
    xPosition = x();
    yPosition = y();
}


void Snake::moveRight()
{
    setPos(x()+10, y());
    if(xPos() > 600)
        setPos(0, y());
    if(xPos() < 0)
        setPos(600, y());
}

void Snake::moveLeft()
{
    setPos(x()-10, y());
    if(xPos() > 600)
        setPos(0, y());
    if(xPos() < 0)
        setPos(600, y());
}

void Snake::moveUp()
{
    setPos(x(), y()-10);
    if(yPos() > 600)
        setPos(x(), 0);
    if(yPos() < 0)
        setPos(x(), 600);
}

void Snake::moveDown()
{
    setPos(x(), y()+10);
    if(yPos() > 600)
        setPos(x(), 0);
    if(yPos() < 0)
        setPos(x(), 600);
}
