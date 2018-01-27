#ifndef PIPE_HPP
#define PIPE_HPP

#include "gameelement.hpp"

enum PipeType{above=0,
              following=1};

enum Diffi{normal = 150,
           hard = 100};

class Pipe : public GameElement
{
    Q_OBJECT
private:
    int diffi = 100;
    int currentFrame;
    double speedX;
    int startPosition;
    QRectF pipeRect[2];
    bool pipePassEmited;

    void loadFrame();
public:
    explicit Pipe(int pos,QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
    void setDiffi(int level);
    QRectF &getRect(PipeType);
signals:
    void pipePass();

};

#endif // PIPE_HPP
