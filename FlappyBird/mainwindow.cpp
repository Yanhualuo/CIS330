#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qsrand(QTime::currentTime().second());

    this->bufferPixmap = new QPixmap(288,512);
    // Set size.
    this->resize(576,1024);

    /* Init 3 buttons. */
    this->startButton = new QPushButton(this);
    this->startButton->setGeometry(QRect((20.0/288)*this->width(),
                                         (341.0/512)*this->height(),
                                         (117.0/288)*this->width(),
                                         (71.0/512)*this->height()));

    this->startButton->setStyleSheet("QPushButton{border-image:url(:/image/image/button_play.png);}"
                                 "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    connect(this->startButton,SIGNAL(clicked()),this,SLOT(startGame()));

    this->closeButton = new QPushButton(this);
    this->closeButton->setGeometry(QRect((151.0/288)*this->width(),
                                         (341.0/512)*this->height(),
                                         (117.0/288)*this->width(),
                                         (71.0/512)*this->height()));
    this->closeButton->setStyleSheet("QPushButton{border-image:url(:/image/image/button_close.png);}"
                                 "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    connect(this->closeButton,SIGNAL(clicked()),this,SLOT(closeGame()));

    this->diffiButton = new QPushButton(this);
    this->diffiButton->setGeometry(QRect((106.5/288)*this->width(),
                                         (270.0/512)*this->height(),
                                         (75.0/288)*this->width(),
                                         (48.0/512)*this->height()));
    this->diffiButton->setStyleSheet("QPushButton{border-image:url(:/image/image/button_rate.png);}"
                                 "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    connect(this->diffiButton,SIGNAL(clicked()),this,SLOT(displayDiffi()));

    this->normalButton = new QPushButton(this);
    this->normalButton->setGeometry(QRect((30.0/288)*this->width(),
                                         (241.0/512)*this->height(),
                                         (80.0/288)*this->width(),
                                         (80.0/512)*this->height()));

    this->normalButton->setStyleSheet("QPushButton{border-image:url(:/image/image/normal.png);}"
                                 "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    connect(this->normalButton,SIGNAL(clicked()),this,SLOT(normalGame()));
    this->normalButton->setVisible(false);

    this->hardButton = new QPushButton(this);
    this->hardButton->setGeometry(QRect((161.0/288)*this->width(),
                                         (241.0/512)*this->height(),
                                         (80.0/288)*this->width(),
                                         (80.0/512)*this->height()));
    this->hardButton->setStyleSheet("QPushButton{border-image:url(:/image/image/hard.png);}"
                                 "QPushButton:pressed{margin: 2px 2px 2px 2px;}");
    connect(this->hardButton,SIGNAL(clicked()),this,SLOT(hardGame()));
    this->hardButton->setVisible(false);

    /* Init all the game ments. */
    this->background = new Background();
    this->ground = new Ground();
    this->bird = new Bird();
    this->scoreboard = new ScoreBoard();
    this->readyboard = new ReadyBoard();
    this->overboard = new OverBoard();
    this->titleboard = new TitleBoard();
    this->pipe[0] = new Pipe(0);
    this->pipe[1] = new Pipe(1);
    this->pipe[2] = new Pipe(2);

    this->impactBirdRect.setRect(0,0,0.4*this->bird->getBindRect().width(),
                                 0.4*this->bird->getBindRect().height());


    /* The refresh rate : 50Hz */
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
    timer.start(20);

    /* Connect signals and slots */
    connect(this->pipe[0],SIGNAL(pipePass()),this,SLOT(getScore()));
    connect(this->pipe[1],SIGNAL(pipePass()),this,SLOT(getScore()));
    connect(this->pipe[2],SIGNAL(pipePass()),this,SLOT(getScore()));

    connect(this->overboard,SIGNAL(buttonVisible(bool,bool,bool)),this,SLOT(setButtonVisible(bool,bool,bool)));

    // Game Start.
    this->gameTitle();
}

MainWindow::~MainWindow()
{
    delete this->startButton;
    delete this->diffiButton;
    delete this->closeButton;

    delete this->background;
    delete this->ground;
    delete this->bird;
    delete this->scoreboard;
    delete this->readyboard;
    delete this->overboard;
    delete this->titleboard;
    delete this->pipe[0];
    delete this->pipe[1];
    delete this->pipe[2];
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //when the game playing, bird up
    if( this->status == GAMEPLAY && event->key()==Qt::Key_Space)
    {
        this->bird->birdUp();
    }

    //When the game is ready , start the game.
    if( this->status == GAMEREADY && event->key() == Qt::Key_Space)
    {
        this->gamePlay();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this->bufferPixmap);
    /* Draw all the ments. */
    this->background->logic();
    this->background->draw(&painter);

    this->pipe[0]->logic();
    this->pipe[0]->draw(&painter);

    this->pipe[1]->logic();
    this->pipe[1]->draw(&painter);

    this->pipe[2]->logic();
    this->pipe[2]->draw(&painter);

    this->bird->logic();
    this->bird->draw(&painter);

    this->scoreboard->logic();
    this->scoreboard->draw(&painter);

    this->readyboard->logic();
    this->readyboard->draw(&painter);

    this->titleboard->logic();
    this->titleboard->draw(&painter);

    this->ground->logic();
    this->ground->draw(&painter);

    this->overboard->logic();
    this->overboard->draw(&painter);

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*this->bufferPixmap);

    if(this->status == GAMEPLAY)
    {
        /* update the impact rectangle of bird. */
        this->impactBirdRect.moveCenter(this->bird->getBindRect().center());

        /* To test if the impact happened. */
        if(this->impactBirdRect.intersects(this->ground->getBindRect()))
        {
            this->gameOver(); //Game over
        }
        if(this->impactBirdRect.intersects(this->pipe[0]->getRect(above))
           ||this->impactBirdRect.intersects(this->pipe[0]->getRect(following))
           ||this->impactBirdRect.intersects(this->pipe[1]->getRect(above))
           ||this->impactBirdRect.intersects(this->pipe[1]->getRect(following))
           ||this->impactBirdRect.intersects(this->pipe[2]->getRect(above))
           ||this->impactBirdRect.intersects(this->pipe[2]->getRect(following)))
        {

                this->gameOver(); //Game over
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    this->startButton->setGeometry(QRect((20.0/288)*this->width(),
                                   (341.0/512)*this->height(),
                                   (117.0/288)*this->width(),
                                   (71.0/512)*this->height()));
    this->closeButton->setGeometry(QRect((151.0/288)*this->width(),
                                         (341.0/512)*this->height(),
                                         (117.0/288)*this->width(),
                                         (71.0/512)*this->height()));
    this->diffiButton->setGeometry(QRect((106.5/288)*this->width(),
                                         (270.0/512)*this->height(),
                                         (75.0/288)*this->width(),
                                         (48.0/512)*this->height()));
}

void MainWindow::gameTitle()
{
    this->background->enabledLogic = true;
    this->background->enabledDraw = true;

    this->titleboard->enabledLogic = true;
    this->titleboard->enabledDraw = true;

    this->bird->enabledLogic = false;
    this->bird->enabledDraw = false;

    this->ground->enabledLogic = true;
    this->ground->enabledDraw = true;

    this->overboard->enabledLogic = false;
    this->overboard->enabledDraw = false;

    this->pipe[0]->enabledLogic = false;
    this->pipe[0]->enabledDraw = false;
    this->pipe[1]->enabledLogic = false;
    this->pipe[1]->enabledDraw = false;
    this->pipe[2]->enabledLogic = false;
    this->pipe[2]->enabledDraw = false;
    this->readyboard->enabledLogic = false;
    this->readyboard->enabledDraw = false;

    this->scoreboard->enabledLogic = false;
    this->scoreboard->enabledDraw = false;

    this->setButtonVisible(true,true,true);
    this->status = GAMETITLE;
}

void MainWindow::gameReady()
{
    this->score = 0;

    this->background->enabledLogic = true;
    this->background->enabledDraw = true;

    this->titleboard->enabledLogic = false;
    this->titleboard->enabledDraw = false;

    this->bird->enabledLogic = false;
    this->bird->enabledDraw = true;

    this->ground->enabledLogic = true;
    this->ground->enabledDraw = true;

    this->overboard->enabledLogic = false;
    this->overboard->enabledDraw = false;

    this->pipe[0]->enabledLogic = false;
    this->pipe[0]->enabledDraw = false;
    this->pipe[1]->enabledLogic = false;
    this->pipe[1]->enabledDraw = false;
    this->pipe[2]->enabledLogic = false;
    this->pipe[2]->enabledDraw = false;

    this->readyboard->enabledLogic = true;
    this->readyboard->enabledDraw = true;

    this->scoreboard->enabledLogic = true;
    this->scoreboard->enabledDraw = true;

    this->setButtonVisible(false,false,false);
    this->status = GAMEREADY;
}

void MainWindow::gamePlay()
{
    this->background->enabledLogic = true;
    this->background->enabledDraw = true;

    this->titleboard->enabledLogic = false;
    this->titleboard->enabledDraw = false;

    this->bird->enabledLogic = true;
    this->bird->enabledDraw = true;

    this->ground->enabledLogic = true;
    this->ground->enabledDraw = true;

    this->overboard->enabledLogic = false;
    this->overboard->enabledDraw = false;

    this->pipe[0]->enabledLogic = true;
    this->pipe[0]->enabledDraw = true;
    this->pipe[1]->enabledLogic = true;
    this->pipe[1]->enabledDraw = true;
    this->pipe[2]->enabledLogic = true;
    this->pipe[2]->enabledDraw = true;

    this->readyboard->enabledLogic = false;
    this->readyboard->enabledDraw = false;

    this->scoreboard->enabledLogic = true;
    this->scoreboard->enabledDraw = true;

    this->status = GAMEPLAY;
}

void MainWindow::gameOver()
{
    this->background->enabledLogic = true;
    this->background->enabledDraw = true;

    this->titleboard->enabledLogic = false;
    this->titleboard->enabledDraw = false;

    this->bird->enabledLogic = true;
    this->bird->enabledDraw = true;

    this->ground->enabledLogic = false;
    this->ground->enabledDraw = true;

    this->overboard->setScore(this->score);
    this->overboard->enabledLogic = true;
    this->overboard->enabledDraw = true;

    this->pipe[0]->enabledLogic = false;
    this->pipe[0]->enabledDraw = true;
    this->pipe[1]->enabledLogic = false;
    this->pipe[1]->enabledDraw = true;
    this->pipe[2]->enabledLogic = false;
    this->pipe[2]->enabledDraw = true;

    this->readyboard->enabledLogic = false;
    this->readyboard->enabledDraw = false;

    this->scoreboard->enabledLogic = false;
    this->scoreboard->enabledDraw = false;

    this->status = GAMEOVER;
}

void MainWindow::startGame()
{
    /* Init all the game ments. */
    this->background->init();
    this->ground->init();
    this->bird->init();
    this->scoreboard->init();
    this->readyboard->init();
    this->overboard->init();
    this->pipe[0]->init();
    this->pipe[1]->init();
    this->pipe[2]->init();

    // Game Start.
    this->gameReady();

}

void MainWindow::closeGame()
{

    this->close();
}

void MainWindow::normalGame()
{
    pipe[0]->setDiffi(normal);
    pipe[1]->setDiffi(normal);
    pipe[2]->setDiffi(normal);
    this->normalButton->setVisible(false);
    this->hardButton->setVisible(false);
    setButtonVisible(true,true,true);
}

void MainWindow::hardGame()
{
    pipe[0]->setDiffi(hard);
    pipe[1]->setDiffi(hard);
    pipe[2]->setDiffi(hard);
    this->normalButton->setVisible(false);
    this->hardButton->setVisible(false);
    setButtonVisible(true,true,true);
}

void MainWindow::getScore()
{
    this->score += 1;
    this->scoreboard->setScore(this->score);
}

void MainWindow::displayDiffi()
{

    setButtonVisible(false,false,false);
    this->normalButton->setVisible(true);
    this->hardButton->setVisible(true);

}

void MainWindow::setButtonVisible(bool _startBtn, bool _scoreBtn, bool _rateBtn)
{
    this->startButton->setVisible(_startBtn);
    this->closeButton->setVisible(_scoreBtn);
    this->diffiButton->setVisible(_rateBtn);
}
