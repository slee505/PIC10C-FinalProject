#include "snake.h"
#include "mainwindow.h"
#include<iostream>

extern MainWindow * game;
extern Food * food;

Snake::Snake()
{
    setRect(0,0,10,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);

    move();
    for(size_t iter = 0; iter < 5; ++iter){
        grow();
    }
    food = new Food();
    food->setPos(100,100);
    game->scene->addItem(food);
}

void Snake::disconnectAll()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
}

void Snake::checkForCollision()
{
    for(snakeBody * b: body){
       if(x() == b->xPos() && y() == b->yPos()){
           disconnectAll();
           GameOver * gameOver = new GameOver();
           gameOver->show();
           game->board->hide();
           game->music->stop();
       }
    }
}

void Snake::WallCollision()
{
    if(x() > 300 || x()<0 || y() >300 || y() < 0){
        disconnectAll();
        GameOver * gameOver = new GameOver();
        gameOver->show();
        game->board->hide();
        game->music->stop();
    }
}

void Snake::eat()
{
    if(pos() == food->pos()){
        food->setPos((std::rand() % (25 + 1)) * 10, (std::rand() % (25 + 1)) * 10);
        grow();
    }
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

void Snake::grow()
{
    snakeBody* b = new snakeBody();
    body.prepend(b);
    game->scene->addItem(b);
}

void Snake::move()
{
    if(currentDirection == "left"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        timer->start(50);
    }
    else if(currentDirection == "right"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        timer->start(50);
    }
    else if(currentDirection == "up"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        timer->start(50);
    }
    else if(currentDirection == "down"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        timer->start(50);
    }
}

void Snake::moveRight()
{
    PrevX = x();
    PrevY = y();
    setPos(x()+10, y());
    WallCollision();
    eat();
    for (size_t i = 0, n = body.size()-1; i < n; ++i){
            body[i]->setPos(body[i+1]->pos());
        }
    body.last()->setPos(PrevX, PrevY);
    checkForCollision();

}

void Snake::moveLeft()
{
    PrevX = x();
    PrevY = y();
    setPos(x()-10, y());
    WallCollision();
    eat();
    for (size_t i = 0, n = body.size()-1; i < n; ++i){
            body[i]->setPos(body[i+1]->pos());
        }
    body.last()->setPos(PrevX, PrevY);
    checkForCollision();

}

void Snake::moveUp()
{
    PrevX = x();
    PrevY = y();
    setPos(x(), y()-10);
    WallCollision();
    eat();
    for (size_t i = 0, n = body.size()-1; i < n; ++i){
            body[i]->setPos(body[i+1]->pos());
        }
    body.last()->setPos(PrevX, PrevY);
    checkForCollision();
}

void Snake::moveDown()
{
    PrevX = x();
    PrevY = y();
    setPos(x(), y()+10);
    WallCollision();
    eat();
    for (size_t i = 0, n = body.size()-1; i < n; ++i){
            body[i]->setPos(body[i+1]->pos());
        }
    body.last()->setPos(PrevX, PrevY);
    checkForCollision();
}

