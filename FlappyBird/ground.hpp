#ifndef GROUND_HPP
#define GROUND_HPP

#include "gameelement.hpp"

class Ground : public GameElement
{
    Q_OBJECT
private:
    int currentFrame;
    double positionX;
    float speedX;
public:
    explicit Ground(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
};

#endif // GROUND_HPP
