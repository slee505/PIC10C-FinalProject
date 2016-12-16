#include "snakebody.h"
#include "mainwindow.h"

//create snake body and color it black
snakeBody::snakeBody(QGraphicsItem* Parent)
{
    setRect(0,0,10,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);

}

//getters for x and y positions of the body
int snakeBody::xPos()
{
    return x();
}

int snakeBody::yPos()
{
    return y();
}
