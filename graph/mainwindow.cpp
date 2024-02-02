#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <QLineEdit>
#include <QCoreApplication>
#include <Qdebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Button0, SIGNAL(clicked(bool)), this, SLOT(Button0_clicked()));
    connect(ui->Button1, SIGNAL(clicked(bool)), this, SLOT(Button1_clicked()));
    connect(ui->Button2, SIGNAL(clicked(bool)), this, SLOT(Button2_clicked()));
    connect(ui->Button3, SIGNAL(clicked(bool)), this, SLOT(Button3_clicked()));
    connect(ui->Button4, SIGNAL(clicked(bool)), this, SLOT(Button4_clicked()));
    connect(ui->Button5, SIGNAL(clicked(bool)), this, SLOT(Button5_clicked()));
    connect(ui->Button6, SIGNAL(clicked(bool)), this, SLOT(Button6_clicked()));
    connect(ui->Button7, SIGNAL(clicked(bool)), this, SLOT(Button7_clicked()));
    connect(ui->Button8, SIGNAL(clicked(bool)), this, SLOT(Button8_clicked()));
    connect(ui->Button9, SIGNAL(clicked(bool)), this, SLOT(Button9_clicked()));
    connect(ui->StartButton, SIGNAL(clicked(bool)), this, SLOT(StartButton_clicked()));
    connect(ui->text_guess, SIGNAL(textChanged()), this, SLOT(text_guess_textChanged()));
    connect(ui->pushButtonCheck, SIGNAL(clicked(bool)), this, SLOT(pushButtonCheck_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeRandom() {
    srand(time(0));
    randomNumber=(rand() % 20) + 1;
    QString strText = "The random value is: ";
    ui->myTextBoxTest->setText(strText);
}

void MainWindow::StartButton_clicked()
{
    QString strText="Aloitetaan peli.\n";
    makeRandom();
    numberOfGuesses=0;
    ui->myTextBoxTest->setText(strText);
    ui->pushButtonCheck->setDisabled(1);
}


void MainWindow::Button0_clicked()
{

    guess=ui->text_guess->toPlainText();

    guess=guess+'0';
    playerGuess = playerGuess+0;
    ui->text_guess->setText(guess);
}


void MainWindow::text_guess_textChanged()
{
    ui->pushButtonCheck->setDisabled(0);
}

void MainWindow::Button1_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'1';
    ui->text_guess->setText(guess);
    qDebug() << "Button 1" << guess;
}


void MainWindow::Button2_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'2';
    ui->text_guess->setText(guess);
}


void MainWindow::Button3_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'3';
    ui->text_guess->setText(guess);
}


void MainWindow::Button4_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'4';
    ui->text_guess->setText(guess);
}


void MainWindow::Button5_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'5';
    ui->text_guess->setText(guess);
}


void MainWindow::Button6_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'6';
    ui->text_guess->setText(guess);
}


void MainWindow::Button7_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'7';
    ui->text_guess->setText(guess);
}


void MainWindow::Button8_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'8';
    ui->text_guess->setText(guess);
}


void MainWindow::Button9_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'9';
    ui->text_guess->setText(guess);
}


void MainWindow::pushButtonCheck_clicked()
{
    QString text="";
    ui->myTextBoxTest->setText("");
    numberOfGuesses++;
    bool conversionCheck = false;
    playerGuess = guess.toInt(&conversionCheck);

    if(conversionCheck && playerGuess == randomNumber) {
        //text="Value was correct\nThe value was";
        //ui->myTextBoxTest->setText(text);
        text=QStringLiteral("Value was correct\nThe value was %1 and number of Guesses was %2").arg(randomNumber).arg(numberOfGuesses);
        ui->myTextBoxTest->setText(text);

        // toimis myös..
        //QVariant("3").toInt();


    }
    else if(conversionCheck && playerGuess < randomNumber){
        text= "Value is larger.";
    }
    else if(conversionCheck) {
        text = "value is lower";
    }
    else {
        text = "Conversion failed.";
    }
    ui->myTextBoxTest->setText(text);
    ui->text_guess->setText("");

    ui->pushButtonCheck->setDisabled(1);
}

