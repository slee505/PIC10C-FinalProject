#include "food.h"
#include"mainwindow.h"

extern MainWindow* game;

Food::Food()
{
    //set food shape
    setRect(0,0, 10,10);
}

void Food::addFood()
{
    //create new food item
    Food* newFood = new Food();
    
    //set food position
    newFood->setPos(300,300);
    
    //add food to scene
    game->scene->addItem(newFood);
}
