#include "snake.h"
#include "mainwindow.h"
#include<iostream>

extern MainWindow * game;
extern Food * food;

Snake::Snake()
{
    //define snake head
    setRect(0,0,10,10);
    //color snake black
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
    //set snake moving
    move();
    //set base size to 5
    for(size_t iter = 0; iter < 5; ++iter){
        grow();
    }
    //put food item on the board
    food = new Food();
    food->setPos(100,100);
    game->scene->addItem(food);
}

void Snake::disconnectAll()
{
    //disconnect all movement slots in order to prevent compounding movements together
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
}

void Snake::checkForCollision()
{
    //check to see if the head is in the same position with any of the body
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

//check to see if snake has hit border of the board
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

//makes snake grow when it has reached the same position as a food item
void Snake::eat()
{
    if(pos() == food->pos()){
        food->setPos((std::rand() % (25 + 1)) * 10, (std::rand() % (25 + 1)) * 10);
        for (size_t i = 0; i < body.size(); ++i){
            if(food->pos() == body.at(i)->pos()){
                food->setPos((std::rand() % (25 + 1)) * 10, (std::rand() % (25 + 1)) * 10);
            }
            game->score->increase();
        }
        grow();
    }
}

//changes the direction of the snake when an arrow key is pressed
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

//Increases the snake size by 1
void Snake::grow()
{
    snakeBody* b = new snakeBody();
    body.prepend(b);
    game->scene->addItem(b);
}

//connects the appropriate movement slot depending on the previous key press event
void Snake::move()
{
    if(currentDirection == "left"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        timer->start(70);
    }
    else if(currentDirection == "right"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        timer->start(70);
    }
    else if(currentDirection == "up"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        timer->start(70);
    }
    else if(currentDirection == "down"){
        disconnectAll();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        timer->start(70);
    }
}

//directional movement slots

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

