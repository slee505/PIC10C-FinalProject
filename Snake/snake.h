#ifndef SNAKE_H
#define SNAKE_H
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QTimer>
#include<QObject>


class Snake : public QObject, public QGraphicsRectItem{
        Q_OBJECT
public:
    Snake();
    void keyPressEvent(QKeyEvent * event);
private:
    QTimer * timer;
public slots:
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // SNAKE_H
