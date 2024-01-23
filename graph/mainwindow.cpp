#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QLineEdit>
#include <QCoreApplication>
#include <Qdebug>
#include <ctime>
#include <cstdlib>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::on_StartButton_clicked()
{
    QString strText="Aloitetaan peli.\n";
    makeRandom();
    ui->myTextBoxTest->setText(strText);
}


void MainWindow::on_Button0_clicked()
{

    guess=ui->text_guess->toPlainText();

    guess=guess+'0';
    playerGuess = playerGuess+0;
    ui->text_guess->setText(guess);
}


void MainWindow::on_text_guess_textChanged()
{

}

void MainWindow::on_Button1_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'1';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button2_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'2';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button3_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'3';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button4_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'4';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button5_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'5';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button6_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'6';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button7_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'7';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button8_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'8';
    ui->text_guess->setText(guess);
}


void MainWindow::on_Button9_clicked()
{
    guess=ui->text_guess->toPlainText();

    guess=guess+'9';
    ui->text_guess->setText(guess);
}


void MainWindow::on_pushButtonCheck_clicked()
{
    QString text="";
    ui->myTextBoxTest->setText("");
    bool conversionCheck = false;
    playerGuess = guess.toInt(&conversionCheck);

    if(conversionCheck && playerGuess == randomNumber) {
        text="Value was correct";
        ui->myTextBoxTest->setText(text);
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
}

