/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *tableLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playagainButton;
    QPushButton *hitButton;
    QPushButton *standButton;
    QLabel *playertotalLabel;
    QLabel *youLabel;
    QLabel *dealerLabel;
    QLabel *dealerScoreLabel;
    QLabel *playerStatusLabel;
    QLabel *dealerStatusLabel;
    QLabel *outcomeLabel;
    QWidget *gridLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *card1Label;
    QLabel *card2Label;
    QLabel *card3Label;
    QLabel *card4Label;
    QLabel *card5Label;
    QLabel *card6Label;
    QLabel *card7Label;
    QLabel *card8Label;
    QLabel *card9Label;
    QLabel *card10Label;
    QWidget *gridLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *card1Label_2;
    QLabel *card2Label_2;
    QLabel *card3Label_2;
    QLabel *card4Label_2;
    QLabel *card5Label_2;
    QLabel *card6Label_2;
    QLabel *card7Label_2;
    QLabel *card8Label_2;
    QLabel *card10Label_2;
    QLabel *card9Label_2;
    QLabel *playerTotalScore;
    QLabel *dealerTotalScore;
    QLCDNumber *playerlcdNumber;
    QLCDNumber *dealerlcdNumber;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName(QStringLiteral("PlayWindow"));
        PlayWindow->resize(800, 500);
        PlayWindow->setBaseSize(QSize(800, 500));
        PlayWindow->setAutoFillBackground(false);
        actionQuit = new QAction(PlayWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(PlayWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableLabel = new QLabel(centralwidget);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        tableLabel->setGeometry(QRect(0, -1, 791, 491));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableLabel->sizePolicy().hasHeightForWidth());
        tableLabel->setSizePolicy(sizePolicy);
        tableLabel->setBaseSize(QSize(800, 500));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 370, 401, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        playagainButton = new QPushButton(layoutWidget);
        playagainButton->setObjectName(QStringLiteral("playagainButton"));
        playagainButton->setEnabled(false);
        playagainButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(playagainButton);

        hitButton = new QPushButton(layoutWidget);
        hitButton->setObjectName(QStringLiteral("hitButton"));

        horizontalLayout->addWidget(hitButton);

        standButton = new QPushButton(layoutWidget);
        standButton->setObjectName(QStringLiteral("standButton"));

        horizontalLayout->addWidget(standButton);

        playertotalLabel = new QLabel(centralwidget);
        playertotalLabel->setObjectName(QStringLiteral("playertotalLabel"));
        playertotalLabel->setGeometry(QRect(10, 10, 121, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        playertotalLabel->setPalette(palette);
        youLabel = new QLabel(centralwidget);
        youLabel->setObjectName(QStringLiteral("youLabel"));
        youLabel->setGeometry(QRect(110, 90, 61, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        youLabel->setPalette(palette1);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        youLabel->setFont(font);
        dealerLabel = new QLabel(centralwidget);
        dealerLabel->setObjectName(QStringLiteral("dealerLabel"));
        dealerLabel->setGeometry(QRect(600, 90, 161, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        dealerLabel->setPalette(palette2);
        dealerLabel->setFont(font);
        dealerScoreLabel = new QLabel(centralwidget);
        dealerScoreLabel->setObjectName(QStringLiteral("dealerScoreLabel"));
        dealerScoreLabel->setGeometry(QRect(686, 10, 111, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        dealerScoreLabel->setPalette(palette3);
        playerStatusLabel = new QLabel(centralwidget);
        playerStatusLabel->setObjectName(QStringLiteral("playerStatusLabel"));
        playerStatusLabel->setGeometry(QRect(20, 260, 221, 111));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playerStatusLabel->sizePolicy().hasHeightForWidth());
        playerStatusLabel->setSizePolicy(sizePolicy1);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        playerStatusLabel->setPalette(palette4);
        playerStatusLabel->setAlignment(Qt::AlignCenter);
        dealerStatusLabel = new QLabel(centralwidget);
        dealerStatusLabel->setObjectName(QStringLiteral("dealerStatusLabel"));
        dealerStatusLabel->setGeometry(QRect(540, 260, 211, 111));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dealerStatusLabel->sizePolicy().hasHeightForWidth());
        dealerStatusLabel->setSizePolicy(sizePolicy2);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        dealerStatusLabel->setPalette(palette5);
        QFont font1;
        font1.setPointSize(36);
        dealerStatusLabel->setFont(font1);
        dealerStatusLabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        outcomeLabel = new QLabel(centralwidget);
        outcomeLabel->setObjectName(QStringLiteral("outcomeLabel"));
        outcomeLabel->setGeometry(QRect(270, 260, 281, 121));
        QPalette palette6;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        outcomeLabel->setPalette(palette6);
        outcomeLabel->setFont(font);
        outcomeLabel->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 150, 381, 101));
        horizontalLayout_2 = new QHBoxLayout(gridLayoutWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        card1Label = new QLabel(gridLayoutWidget);
        card1Label->setObjectName(QStringLiteral("card1Label"));

        horizontalLayout_2->addWidget(card1Label);

        card2Label = new QLabel(gridLayoutWidget);
        card2Label->setObjectName(QStringLiteral("card2Label"));

        horizontalLayout_2->addWidget(card2Label);

        card3Label = new QLabel(gridLayoutWidget);
        card3Label->setObjectName(QStringLiteral("card3Label"));

        horizontalLayout_2->addWidget(card3Label);

        card4Label = new QLabel(gridLayoutWidget);
        card4Label->setObjectName(QStringLiteral("card4Label"));

        horizontalLayout_2->addWidget(card4Label);

        card5Label = new QLabel(gridLayoutWidget);
        card5Label->setObjectName(QStringLiteral("card5Label"));

        horizontalLayout_2->addWidget(card5Label);

        card6Label = new QLabel(gridLayoutWidget);
        card6Label->setObjectName(QStringLiteral("card6Label"));

        horizontalLayout_2->addWidget(card6Label);

        card7Label = new QLabel(gridLayoutWidget);
        card7Label->setObjectName(QStringLiteral("card7Label"));

        horizontalLayout_2->addWidget(card7Label);

        card8Label = new QLabel(gridLayoutWidget);
        card8Label->setObjectName(QStringLiteral("card8Label"));

        horizontalLayout_2->addWidget(card8Label);

        card9Label = new QLabel(gridLayoutWidget);
        card9Label->setObjectName(QStringLiteral("card9Label"));

        horizontalLayout_2->addWidget(card9Label);

        card10Label = new QLabel(gridLayoutWidget);
        card10Label->setObjectName(QStringLiteral("card10Label"));

        horizontalLayout_2->addWidget(card10Label);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(400, 150, 381, 101));
        horizontalLayout_3 = new QHBoxLayout(gridLayoutWidget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        card1Label_2 = new QLabel(gridLayoutWidget_2);
        card1Label_2->setObjectName(QStringLiteral("card1Label_2"));

        horizontalLayout_3->addWidget(card1Label_2);

        card2Label_2 = new QLabel(gridLayoutWidget_2);
        card2Label_2->setObjectName(QStringLiteral("card2Label_2"));

        horizontalLayout_3->addWidget(card2Label_2);

        card3Label_2 = new QLabel(gridLayoutWidget_2);
        card3Label_2->setObjectName(QStringLiteral("card3Label_2"));

        horizontalLayout_3->addWidget(card3Label_2);

        card4Label_2 = new QLabel(gridLayoutWidget_2);
        card4Label_2->setObjectName(QStringLiteral("card4Label_2"));

        horizontalLayout_3->addWidget(card4Label_2);

        card5Label_2 = new QLabel(gridLayoutWidget_2);
        card5Label_2->setObjectName(QStringLiteral("card5Label_2"));

        horizontalLayout_3->addWidget(card5Label_2);

        card6Label_2 = new QLabel(gridLayoutWidget_2);
        card6Label_2->setObjectName(QStringLiteral("card6Label_2"));

        horizontalLayout_3->addWidget(card6Label_2);

        card7Label_2 = new QLabel(gridLayoutWidget_2);
        card7Label_2->setObjectName(QStringLiteral("card7Label_2"));

        horizontalLayout_3->addWidget(card7Label_2);

        card8Label_2 = new QLabel(gridLayoutWidget_2);
        card8Label_2->setObjectName(QStringLiteral("card8Label_2"));

        horizontalLayout_3->addWidget(card8Label_2);

        card10Label_2 = new QLabel(gridLayoutWidget_2);
        card10Label_2->setObjectName(QStringLiteral("card10Label_2"));

        horizontalLayout_3->addWidget(card10Label_2);

        card9Label_2 = new QLabel(gridLayoutWidget_2);
        card9Label_2->setObjectName(QStringLiteral("card9Label_2"));

        horizontalLayout_3->addWidget(card9Label_2);

        playerTotalScore = new QLabel(centralwidget);
        playerTotalScore->setObjectName(QStringLiteral("playerTotalScore"));
        playerTotalScore->setGeometry(QRect(310, 50, 41, 16));
        dealerTotalScore = new QLabel(centralwidget);
        dealerTotalScore->setObjectName(QStringLiteral("dealerTotalScore"));
        dealerTotalScore->setGeometry(QRect(420, 50, 41, 16));
        playerlcdNumber = new QLCDNumber(centralwidget);
        playerlcdNumber->setObjectName(QStringLiteral("playerlcdNumber"));
        playerlcdNumber->setGeometry(QRect(300, 80, 61, 31));
        dealerlcdNumber = new QLCDNumber(centralwidget);
        dealerlcdNumber->setObjectName(QStringLiteral("dealerlcdNumber"));
        dealerlcdNumber->setGeometry(QRect(410, 80, 61, 31));
        PlayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuQuit = new QMenu(menubar);
        menuQuit->setObjectName(QStringLiteral("menuQuit"));
        PlayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PlayWindow->setStatusBar(statusbar);

        menubar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionQuit);

        retranslateUi(PlayWindow);

        QMetaObject::connectSlotsByName(PlayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayWindow)
    {
        PlayWindow->setWindowTitle(QApplication::translate("PlayWindow", "BlackJack C++ Made by Dominic Heal", 0));
        actionQuit->setText(QApplication::translate("PlayWindow", "Quit", 0));
        tableLabel->setText(QString());
        playagainButton->setText(QApplication::translate("PlayWindow", "New Game", 0));
        hitButton->setText(QApplication::translate("PlayWindow", "Hit", 0));
        standButton->setText(QApplication::translate("PlayWindow", "Stand", 0));
        playertotalLabel->setText(QApplication::translate("PlayWindow", "Player: 0", 0));
        youLabel->setText(QApplication::translate("PlayWindow", "You", 0));
        dealerLabel->setText(QApplication::translate("PlayWindow", "Dealer", 0));
        dealerScoreLabel->setText(QApplication::translate("PlayWindow", "Dealer:", 0));
        playerStatusLabel->setText(QString());
        dealerStatusLabel->setText(QString());
        outcomeLabel->setText(QString());
        card1Label->setText(QString());
        card2Label->setText(QString());
        card3Label->setText(QString());
        card4Label->setText(QString());
        card5Label->setText(QString());
        card6Label->setText(QString());
        card7Label->setText(QString());
        card8Label->setText(QString());
        card9Label->setText(QString());
        card10Label->setText(QString());
        card1Label_2->setText(QString());
        card2Label_2->setText(QString());
        card3Label_2->setText(QString());
        card4Label_2->setText(QString());
        card5Label_2->setText(QString());
        card6Label_2->setText(QString());
        card7Label_2->setText(QString());
        card8Label_2->setText(QString());
        card10Label_2->setText(QString());
        card9Label_2->setText(QString());
        playerTotalScore->setText(QApplication::translate("PlayWindow", "Player", 0));
        dealerTotalScore->setText(QApplication::translate("PlayWindow", "Dealer", 0));
        menuQuit->setTitle(QApplication::translate("PlayWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
