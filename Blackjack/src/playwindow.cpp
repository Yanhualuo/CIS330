#include "playwindow.hpp"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <QList>
#include <map>
#include<iostream>
#include<ctime>
#include <sys/stat.h>
#include <list>
#include <unistd.h>
#include <string>


PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/blackjack_tables.jpg");
    ui->tableLabel->setPixmap(pix);
    ui->tableLabel->lower();
    ui->standButton->setEnabled(false);
    ui->hitButton->setText("Start");
    this->statusBar()->setSizeGripEnabled(false);
    this->setFixedSize(800,500);
    ui->standButton->setToolTip("Stand: Player take no more(stand pat) cards.");
    loadList();
    loadPic();
}

QImage face[53];
QImage img[6];
static int playerScore = 0;
static int dealerScore = 0;
static bool b=false;
static int first=0;
int dealerWinsCount = 0;
int playerWinsCount = 0;
int holdingCardCount = 1;
int holdingCardCountDealer= 1;
int totalCardUsed = 0;
int playerDefult[2] = {};
int dealerDefult[2] = {};

void PlayWindow::loadList(){

    QString ads = ":/images/images/cards/%1.png";
    for (int i = 1; i <= 52; i++){
           QString s = ads.arg(i);
        face[i] = QImage(s);
    }
    face[0] = QImage(":/images/images/cardBack.png");
}

void PlayWindow::loadPic(){
    QString pic = ":/images/images/%1.png";
    char pip[6] = {'w','l','d','b','n','s'};
    for (int i = 0; i < 7; i++){
        QString s = pic.arg(pip[i]);
        img[i] = QImage(s);
    }
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::showCardPlayer(int holdingCardCount,int number){
    if (holdingCardCount == 1){
        ui->card1Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCount == 2){
        ui->card2Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCount == 3){
        ui->card3Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCount == 4){
        ui->card4Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCount == 5){
        ui->card5Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCount == 6){
        ui->card6Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCount == 7){
        ui->card7Label->setPixmap(QPixmap::fromImage(face[number]));
    }
    else{
        ui->card8Label->setPixmap(QPixmap::fromImage(face[number]));
    }
}

void PlayWindow::showCardDealer(int holdingCardCountDealer,int number){
    if (holdingCardCountDealer == 1){
        ui->card10Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCountDealer == 2){
        ui->card9Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCountDealer == 3){
        ui->card8Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCountDealer == 4){
        ui->card7Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCountDealer == 5){
        ui->card6Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCountDealer == 6){
        ui->card5Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else if (holdingCardCountDealer == 7){
        ui->card4Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
    else{
        ui->card3Label_2->setPixmap(QPixmap::fromImage(face[number]));
    }
}

void PlayWindow::on_hitButton_clicked()
{
    ++totalCardUsed;
    if(playerScore==0){
        srand(unsigned(time(0))); //change rand algorithm, get different rand number each time
        usleep(1000);
        for(int i=0;i<2;i++){
            ++totalCardUsed;
            int number = ((rand() % 208)%52)+1;//player's 1st & 2nd card

            playerDefult[i] = deckValues[number-1];

           // qDebug()<< playerDefult[0]<< endl;

            if(deckValues[number-1]==1){
                b =true;
            }
            playerScore += deckValues[number-1];

            ui->playertotalLabel->setText("Player: " + QString::number(playerScore));

            // position to place card for player

          //  position.append(card1Label);
            showCardPlayer(holdingCardCount, number);

            // increment Card Count for position
            ++holdingCardCount;
        }

        usleep(1000);
            int number=((rand() % 208)%52)+1;//dealer's first card
            dealerDefult[0] = deckValues[number-1];
            if(deckValues[number-1]==1 && dealerScore+11<22){
                dealerScore+=11;
            }else{
                dealerScore+=deckValues[number-1];
            }
            first=number; // remember the number of first card

                ui->card10Label_2->setPixmap(QPixmap::fromImage(face[0])); //set cover over dealer's 1st card
                ++holdingCardCountDealer;

                usleep(1000);
                number=((rand() % 208)%52)+1; //dealer's second card
                dealerDefult[1] = deckValues[number-1];
                if(deckValues[number-1]==1 && dealerScore+11<22){
                    dealerScore+=11;
                }else{
                    dealerScore+=deckValues[number-1];
                }

                    //position to play card for dealer
                    showCardDealer(holdingCardCountDealer, number);
                    ++holdingCardCountDealer;

        //Natural Black Jack
        if ((playerDefult[0] == 10 || playerDefult[1] == 10) && (playerDefult[0] == 1 || playerDefult[1] == 1)){
            ++playerWinsCount;
            ui->outcomeLabel->setPixmap(QPixmap::fromImage(img[0]));
            ui->playerStatusLabel->setPixmap(QPixmap::fromImage(img[4]));
            ui->standButton->setEnabled(false);
            ui->hitButton->setEnabled(false);
            ui->playagainButton->setEnabled(true);
            ui->playerlcdNumber->display(playerWinsCount);
            ui->playertotalLabel->setText("Player: " + QString::number(21));
        }
        else if ((dealerDefult[0] == 10 || dealerDefult[1] == 10) && (dealerDefult[0] == 1 || dealerDefult[1] == 1)){
            ++dealerWinsCount;
            ui->outcomeLabel->setPixmap(QPixmap::fromImage(img[1]));
            ui->dealerStatusLabel->setPixmap(QPixmap::fromImage(img[4]));
            ui->standButton->setEnabled(false);
            ui->hitButton->setEnabled(false);
            ui->playagainButton->setEnabled(true);
            ui->playerlcdNumber->display(dealerWinsCount);
            ui->dealerScoreLabel->setText("Dealer: " + QString::number(21));
            ui->card10Label_2->setPixmap(QPixmap::fromImage(face[first]));
        }
        else {
        ui->standButton->setEnabled(true);
        ui->hitButton->setText("Hit");
        ui->hitButton->setToolTip("Hit: Player take another card from the dealer.");
        }
    }
    else{
        usleep(1000);
        int number = ((rand() % 208)%52)+1;

        playerScore += deckValues[number-1];
        if(deckValues[number-1]==1){
            b =true;
        }

        ui->playertotalLabel->setText("Player: " + QString::number(playerScore));

        showCardPlayer(holdingCardCount,number);
        // increment Card Count for position
        ++holdingCardCount;


        //Natural

        // if player score bust
        if (playerScore > 21){
            ui->playerStatusLabel->setPixmap(QPixmap::fromImage(img[3]));
            ui->hitButton->setEnabled(false);

            //Generating Dealer score
            dealerTurn();
            ui->standButton->setEnabled(false);
            ui->playagainButton->setEnabled(true);
        }else{
                ui->standButton->setEnabled(true);
                ui->playagainButton->setEnabled(false);
        }
    }

}

void PlayWindow::on_standButton_clicked()
{
    // To prevent users from activating function before the function ending.
    if(b==true){
        if( playerScore+10<=21){
             playerScore+=10;
        }
    }
    this->setEnabled(false);

    ui->playerStatusLabel->setPixmap(QPixmap::fromImage(img[5]));
    ui->playagainButton->setEnabled(true);
    ui->hitButton->setEnabled(false);
    ui->standButton->setEnabled(false);

    //Generating Dealer score
    dealerTurn();

}

void PlayWindow::on_playagainButton_clicked()
{
    //Clear Labels and Variables
    playerScore = 0;
    dealerScore = 0;
    b =false;
    holdingCardCount = 1;
    holdingCardCountDealer= 1;
    first = 0;

    ui->playertotalLabel->setText("Player: " + QString::number(0));
    ui->hitButton->setText("Start");
    ui->hitButton->setEnabled(true);
    ui->playagainButton->setEnabled(false);
    ui->standButton->setEnabled(false);
    ui->outcomeLabel->clear();
    ui->dealerStatusLabel->clear();
    ui->playerStatusLabel->clear();
    ui->dealerScoreLabel->setText("Dealer: " + QString::number(0));

    // Clear Cards from player table

    ui->card1Label->clear();
    ui->card2Label->clear();
    ui->card3Label->clear();
    ui->card4Label->clear();
    ui->card5Label->clear();
    ui->card6Label->clear();
    ui->card8Label->clear();

    ui->card10Label_2->clear();
    ui->card9Label_2->clear();
    ui->card8Label_2->clear();
    ui->card7Label_2->clear();
    ui->card6Label_2->clear();
    ui->card5Label_2->clear();
    ui->card4Label_2->clear();
    ui->card3Label_2->clear();

}

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void PlayWindow::dealerTurn(){
    srand(unsigned(time(0)));
    ui->card10Label_2->clear();
    ui->card10Label_2->setPixmap(QPixmap::fromImage(face[first]));

    while (dealerScore < 17){
        ++totalCardUsed;
        usleep(1000);
        int number=((rand() % 208)%52)+1;
        if(deckValues[number-1]==1 && dealerScore+11<22){
            dealerScore+=11;
        }else{
            dealerScore+=deckValues[number-1];
        }

        showCardDealer(holdingCardCountDealer, number);

            ++holdingCardCountDealer;
    }
    ui->dealerScoreLabel->setText("Dealer: " + QString::number(dealerScore));

    //set dealer status
    if (dealerScore > 21){ // bust, >21
        ui->dealerStatusLabel->setPixmap(QPixmap::fromImage(img[3]));
    } else{
        ui->dealerStatusLabel->setPixmap(QPixmap::fromImage(img[5])); // stand <21
    }

    // both player and dealer has the same score OR both > 21
    if ((dealerScore == playerScore) || ((dealerScore > 21) && (playerScore > 21))){
        ui->outcomeLabel->setPixmap(QPixmap::fromImage(img[2]));
    }
    // both player's & dealer's score are < 21 AND Dealer's score is larger than player's
    else if (((dealerScore < 22) && (playerScore < 22) && (dealerScore > playerScore)) || ((playerScore > 21) && dealerScore < 22 )){
        ui->outcomeLabel->setPixmap(QPixmap::fromImage(img[1]));;
        ++dealerWinsCount;
    }
    // else, player wins
    else{
        ui->outcomeLabel->setPixmap(QPixmap::fromImage(img[0]));
        ++playerWinsCount;
    }
    ui->statusbar->showMessage("Player " + QString::number(playerWinsCount) + " - Gamescore - " + "Dealer " + QString::number(dealerWinsCount));
    this->setEnabled(true);

    ui->playertotalLabel->setText("Player: " + QString::number(playerScore));
    ui->playerlcdNumber->display(playerWinsCount);
    ui->dealerlcdNumber->display(dealerWinsCount);
}


