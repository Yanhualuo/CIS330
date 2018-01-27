#ifndef BIRD_HPP
#define BIRD_HPP

#include <QTimer>
#include <qmath.h>
#include "gameelement.hpp"

class Bird : public GameElement
{
    Q_OBJECT
private:
    int lastFrame;
    int currentFrame;
    float speedY;
    float increaseY;
    float speedX;
    int angle;
    QTimer timer;

    void loadFrame();

public:
    explicit Bird(QObject *parent = 0);
    void init();
    void logic();
    void draw(QPainter *);
    void birdUp();

signals:

public slots:
    void updateFrame();
};

#endif // BIRD_HPP
