#include "snake.h"

Snake::Snake()
{
    setRect(0,0,5,5);

    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
    timer->start(50);
}

void Snake::keyPressEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Left){
        connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        timer->start(50);
    }
    else if(event -> key() == Qt::Key_Right){
        connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        timer->start(50);
    }
    else if(event -> key() == Qt::Key_Up){
        connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        timer->start(50);
    }
    else if(event -> key() == Qt::Key_Down){
        connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        timer->start(50);
    }
}


void Snake::moveRight()
{
    setPos(x()+10, y());
}

void Snake::moveLeft()
{
    setPos(x()-10, y());
}

void Snake::moveUp()
{
    setPos(x(), y()-10);
}

void Snake::moveDown()
{
    setPos(x(), y()+10);
}
