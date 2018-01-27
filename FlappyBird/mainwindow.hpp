#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
//#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QPixmap>

#include "background.hpp"
#include "ground.hpp"
#include "bird.hpp"
#include "pipe.hpp"
#include "scoreboard.hpp"
#include "readyboard.hpp"
#include "overboard.hpp"
#include "titleboard.hpp"

/* 4 status */
enum GameStatus{GAMETITLE,
                GAMEREADY,
                GAMEPLAY,
                GAMEOVER};

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    /* Buttons on the start panel. */
    QPushButton *startButton;
    QPushButton *closeButton;
    QPushButton *diffiButton;
    QPushButton *normalButton;
    QPushButton *hardButton;

    /* ments need to draw */
    Background *background;
    Ground *ground;
    Bird *bird;
    Pipe *pipe[3];
    ScoreBoard *scoreboard;
    ReadyBoard *readyboard;
    OverBoard *overboard;
    TitleBoard *titleboard;

    int score; // Game score
    QRectF impactBirdRect; // the rectangle used to test the impact of bird.
    GameStatus status;
    QTimer timer; // Main timer, refresh the interface.

    /*Corresponding  to 4 game status. */
    void gameTitle();
    void gameReady();
    void gamePlay();
    void gameOver();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
//    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent *);
public slots:
    void getScore(); // socre increase.
    void startGame(); // The button clicked , game began.
    void closeGame();// The button clicked , game exit.
    void normalGame();// Setting normal level.
    void hardGame();// Setting hard level.
    void displayDiffi(); // Select the level.
    void setButtonVisible(bool,bool,bool); // set 3 button visible .
};

#endif // MAINWINDOW_HPP
