#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "playwindow.hpp"
#include <QFrame>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/startWindow.jpg");
    ui->pictureLabel->setPixmap(pix);
    ui->pictureLabel->setFixedSize(480,360);
    ui->pictureLabel->lower();
    this->setFixedSize(480,400);
    this->statusBar()->setSizeGripEnabled(false);

    ui->questionButton->setToolTip("Game Rule");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
   QApplication::quit();
}

void MainWindow::on_playButton_clicked()
{
    playwindow = new PlayWindow(this);
    playwindow->show();
    this->hide();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_questionButton_clicked()
{
    QMessageBox *msg = new QMessageBox;
    msg->setWindowTitle("Game Rule");
    msg->setIcon(QMessageBox::Information);
    msg->setText("Blackjack is a comparing card game between a player and dealer. The player or the dealer wins by having a score of 21 or by having the higher score that is less than 21.\
                 \nPlayer:\n1) optional hit or stand\n2) an ace as 1 point or 11 points\n3) Scoring higher than 21 results in a loss\
                   Dealer:\n1) must hit until the cards total 17 or more points\n2) an ace as 1 point or 11 points\n3) Scoring higher than 21 results in a loss");

    QPalette palette;
    palette.setColor(QPalette::Background, Qt::white);
    msg->setPalette(palette);

    msg->setWindowModality(Qt::NonModal);
    msg->show();
    QCoreApplication::processEvents();

}
