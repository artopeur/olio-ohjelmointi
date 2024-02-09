#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->startGameButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(ui->gameMode1,SIGNAL(clicked(bool)),this,SLOT(playValue()));
    connect(ui->gameMode2,SIGNAL(clicked(bool)),this,SLOT(playValue()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
        setGameInfoText("Game has stopped",4);
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
}

void MainWindow::playValue()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name= button->objectName();
    qDebug() << "Button name: " << name;

    if(name == "gameMode1") {
        setGameInfoText("Button gameMode1 clicked : 120 seconds",2);

    }
    else {
        setGameInfoText("Button gameMode2 clicked : 5 minutes", 2);

    }
}
