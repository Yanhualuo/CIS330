#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "gameelement.hpp"

class ScoreBoard : public GameElement
{
    Q_OBJECT
private:
    int score;
    int tempUnit;
    int tempDecade;
    int tempHundred;
    void loadFrame();

public:
    explicit ScoreBoard(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
    void setScore(int);

signals:

public slots:

};

#endif // SCOREBOARD_HPP
