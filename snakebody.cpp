#include "snakebody.h"
#include "mainwindow.h"

snakeBody::snakeBody(QGraphicsItem* Parent)
{
    setRect(0,0,10,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);

}

int snakeBody::xPos()
{
    return x();
}

int snakeBody::yPos()
{
    return y();
}
