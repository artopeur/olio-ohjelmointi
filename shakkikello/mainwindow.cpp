#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(100);
    ui->progressBar_2->setMaximum(100);
    ui->progressBar->setValue(100);
    ui->progressBar_2->setValue(100);
    updateProgressBar();
    connect(ui->startGameButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(ui->gameMode1,SIGNAL(clicked(bool)),this,SLOT(playValue()));
    connect(ui->gameMode2,SIGNAL(clicked(bool)),this,SLOT(playValue()));
    connect(ui->switchPlayerButton, SIGNAL(clicked(bool)),this,SLOT(switchPlayer()));
    connect(ui->switchPlayerButton2, SIGNAL(clicked(bool)), this, SLOT(switchPlayer()));
    connect(ui->stopGameButton, SIGNAL(clicked(bool)), this, SLOT(stopGame()));

    pQTimer = new QTimer();
    //connect(pQTimer, SIGNAL(destroyed(QObject*)), this, SLOT(updateProgressBar()));
    connect(pQTimer, SIGNAL(timeout()),this,SLOT(timerRun()));

}

MainWindow::~MainWindow()
{

    delete ui;
    qDebug()<<"ui deleted";
    delete pQTimer;
    qDebug() << "timer deleted";
}

void MainWindow::timeout()
{
    if(currentPlayer == 1) {
        setGameInfoText("Player 2 won, timeout.",2);
        pQTimer->stop();
        currentPlayer = 0;
    }
    else if(currentPlayer == 2){
        setGameInfoText("Player 1 won, timout.",2);
        pQTimer->stop();
        currentPlayer = 0;
    }
    else {
        setGameInfoText("Game has stopped",4);
    }
    //stopGame();
}

void MainWindow::updateProgressBar()
{
    ui->progressBar->setValue(player1Time);
    ui->progressBar_2->setValue(player2Time);
}
void MainWindow::setGameInfoText(QString text, short size)
{
    QFont font;
    ui->label->font();

    switch(size) {
    case 1:
        font.setPointSize(10);
        break;
    case 2:
        font.setPointSize(20);
        break;
    case 3:
        font.setPointSize(30);
        break;
    case 4:
        font.setPointSize(40);
        break;
    default:
        font.setPointSize(10);
        break;
    }


    ui->label->setFont(font);
    ui->label->setText(text);
}

void MainWindow::startGame() {
    setGameInfoText("Game ongoing",4);
    //pQTimer->startTimer(1000);
    pQTimer->start(1000);

}
void MainWindow::stopGame() {
    pQTimer->stop();
    currentPlayer=0;
    //player1Time = 0;
    //player2Time = 0;
    //gameTime = 0;
    setGameInfoText("Gave Over. Select time, press start.",2);
}
void MainWindow::playValue()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name= button->objectName();
    qDebug() << "Button name: " << name;

    if(name == "gameMode1" && currentPlayer == 0) {
        setGameInfoText("Button gameMode1 clicked : 120 seconds",2);
        //test time faster
        gameTime=6;
        //gameTime=2*60;
        player1Time=gameTime;
        player2Time=gameTime;
        ui->progressBar->setMaximum(gameTime);
        ui->progressBar_2->setMaximum(gameTime);
    }
    else if(name == "gameMode2" && currentPlayer == 0){
        setGameInfoText("Button gameMode2 clicked : 5 minutes", 2);
        gameTime=5*60;
        player1Time=gameTime;
        player2Time=gameTime;
        ui->progressBar->setMaximum(gameTime);
        ui->progressBar_2->setMaximum(gameTime);
    }

}

void MainWindow::timerRun()
{
    qDebug() << "timeout";
    qDebug() << "Player 1: " << player1Time;
    qDebug() << "Player 2: " << player2Time;

    if(player2Time>0 && currentPlayer==2) {
        player2Time--;
    }
    else if(player1Time>0 && currentPlayer==1) {
        player1Time--;
    }
    else {
        if(currentPlayer == 2) {
            // player 1 won
            timeout();
        }
        else if(currentPlayer == 1) {
            // player 2 won
            timeout();
        }
        else {
            //not started yet
        }
        //stopGame();
    }


    updateProgressBar();

}

void MainWindow::switchPlayer()
{

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name= button->objectName();
    qDebug() << "Button name: " << name;

    if(name == "switchPlayerButton") {
        qDebug()<<"player 1";
        currentPlayer = 2;
    }
    else if(name == "switchPlayerButton2") {
        qDebug()<<"player 2";
        currentPlayer = 1;
    }

    qDebug()<<"switch: " + name;
}
