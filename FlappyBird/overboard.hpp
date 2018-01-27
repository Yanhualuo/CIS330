#ifndef OVERBOARD_HPP
#define OVERBOARD_HPP

#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "gameelement.hpp"

enum Medal{PLATINICMEDAL = 12,
           GOLDMEDAL = 13,
           SILVERMEDAL = 14,
           COPPERMEDAL = 15,
          NONE = 0};

class OverBoard : public GameElement
{
    Q_OBJECT
private:
    int score;
    int highestScore;
    Medal medal;
    bool scoreLabelArrived;
    QRectF scoreLabelRect;
    QRectF overTextRect;
    void loadFrame();
    int getHighestScore();
public:
    explicit OverBoard(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
    void setScore(int);

signals:
    void buttonVisible(bool,bool,bool);
public slots:
};

#endif // OVERBOARD_HPP
