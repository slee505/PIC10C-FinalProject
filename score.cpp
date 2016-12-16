#include "score.h"

Score::Score(QGraphicsItem *Parent)
{
    //set score to 0
    score = 0;
    //write score out as text
    setPlainText(QString::number(score));
}

void Score::increase()
{
    //increase score by 100
    score += 100;
    setPlainText(QString::number(score));
}

//getter for score value
int Score::getScore()
{
    return score;
}
