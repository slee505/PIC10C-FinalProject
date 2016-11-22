#ifndef SNAKE_H
#define SNAKE_H
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QTimer>
#include<QObject>
#include<string>


class Snake : public QObject, public QGraphicsRectItem{
        Q_OBJECT
public:
    Snake();
    void keyPressEvent(QKeyEvent * event);
    void move();
    int xPos();
    int yPos();
private:
    std::string currentDirection = "right";
    QTimer * timer = new QTimer;
    int xPosition;
    int yPosition;
public slots:
    void currentPosition();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // SNAKE_H
