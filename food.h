#ifndef FOOD_H
#define FOOD_H
#include<QGraphicsRectItem>
#include<QObject>

class Food: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Food();
    void addFood();
};

#endif // FOOD_H
