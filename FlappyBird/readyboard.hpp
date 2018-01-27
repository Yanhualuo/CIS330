#ifndef READYBOARD_HPP
#define READYBOARD_HPP

#include "gameelement.hpp"

class ReadyBoard : public GameElement
{
    Q_OBJECT
public:
    explicit ReadyBoard(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
signals:

public slots:

};

#endif // READYBOARD_HPP
