#include "pipe.hpp"
#include <iostream>
using namespace std;

Pipe::Pipe(int pos,QObject *parent) :
    GameElement(parent)
{
    this->startPosition = pos;
    this->loadFrame();
    this->init();
}

void Pipe::init()
{
    this->currentFrame = 0;
    this->pipePassEmited = false;
    this->pipeRect[above].setRect(576 + this->startPosition*175.6,  -271.0 + qrand()%200,   52.0,   321.0);
    this->pipeRect[following].setRect(576 + this->startPosition*175.6,  this->pipeRect[above].bottom() + diffi,     52.0,   321.0);
    this->speedX = 2.5;
}

void Pipe::logic()
{
    if(!this->enabledLogic)
        return;

    this->pipeRect[above].translate(-this->speedX,0);
    this->pipeRect[following].translate(-this->speedX,0);

    if(this->pipeRect[above].right() < 0)
    {
        this->pipeRect[above].moveTo(474.0,-271.0 + qrand()%200);
        this->pipeRect[following].moveTo(474.0,this->pipeRect[above].bottom() + diffi);
        this->pipePassEmited = false;
    }

    if(this->pipeRect[above].left() < 72 && this->pipePassEmited == false)
    {
        emit pipePass();
        this->pipePassEmited = true;
    }
}

void Pipe::setDiffi(int level)
{
    this->diffi = level;
}

void Pipe::draw(QPainter *painter)
{
    painter->drawPixmap(this->pipeRect[above].x(),
                        this->pipeRect[above].y(),
                        this->pipeRect[above].width(),
                        this->pipeRect[above].height(),
                        this->pixmapList[0]);
    painter->drawPixmap(this->pipeRect[following].x(),
                        this->pipeRect[following].y(),
                        this->pipeRect[following].width(),
                        this->pipeRect[following].height(),
                        this->pixmapList[1]);
}

void Pipe::loadFrame()
{
    this->clearAllFrame();
    this->addFrame(QPixmap(":/image/image/pipe_down.png"));
    this->addFrame(QPixmap(":/image/image/pipe_up.png"));
}

QRectF& Pipe::getRect(PipeType type)
{
        return this->pipeRect[type];
}
