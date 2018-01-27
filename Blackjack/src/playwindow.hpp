#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H
#include <QDebug>
#include <QMainWindow>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();
    int deckValues[52] = {1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10};

public slots:

    void loadList();

    void dealerTurn();
private slots:
    void on_hitButton_clicked();

    void on_standButton_clicked();

    void on_playagainButton_clicked();

    void on_actionQuit_triggered();

    void showCardPlayer(int holdingCardCount, int number);

    void showCardDealer(int holdingCardCountDealer,int number);

    void loadPic();

private:
    Ui::PlayWindow *ui;

protected:
};



#endif // PLAYWINDOW_H
