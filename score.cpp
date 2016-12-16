#include "score.h"

Score::Score(QGraphicsItem *Parent)
{
    score = 0;
    setPlainText(QString::number(score));
}

void Score::increase()
{
    score += 100;
    setPlainText(QString::number(score));
}

int Score::getScore()
{
    return score;
}
