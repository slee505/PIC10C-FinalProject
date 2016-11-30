#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include<QGraphicsRectItem>
#include<QObject>
#include<QBrush>


class snakeBody : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    snakeBody(QGraphicsItem* Parent = NULL);
    int xPos();
    int yPos();
public slots:
    //void move();
};

#endif // SNAKEBODY_H
