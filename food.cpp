#include "food.h"
#include"mainwindow.h"

extern MainWindow* game;

Food::Food()
{
    setRect(0,0, 10,10);
}

void Food::addFood()
{
    Food* newFood = new Food();
    newFood->setPos(300,300);
    game->scene->addItem(newFood);
}
