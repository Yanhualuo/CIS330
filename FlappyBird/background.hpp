#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "gameelement.hpp"

class Background : public GameElement
{
    Q_OBJECT
private:
    int currentFrame;
    void loadFrame();
public:
    explicit Background(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
};

#endif // BACKGROUND_HPP
