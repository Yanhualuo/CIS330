#ifndef TITLEBOARD_HPP
#define TITLEBOARD_HPP

#include <QTimer>
#include"gameelement.hpp"

class TitleBoard : public GameElement
{
    Q_OBJECT
private:
    QTimer timer;
    int lastFrame;
    int currentFrame;
    void loadFrame();

public:
    explicit TitleBoard(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();

signals:

public slots:
    void updateFrame();

};

#endif // TITLEBOARD_HPP
