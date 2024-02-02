#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N0,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->N1, SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->N2, SIGNAL(clicked(bool)), this, SLOT(numberClickedHandler()));
    connect(ui->N3, SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->N4, SIGNAL(clicked(bool)), this, SLOT(numberClickedHandler()));
    connect(ui->N5, SIGNAL(clicked(bool)), this,SLOT(numberClickedHandler()));
    connect(ui->N6, SIGNAL(clicked(bool)),this, SLOT(numberClickedHandler()));
    connect(ui->N7, SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->N8, SIGNAL(clicked(bool)), this, SLOT(numberClickedHandler()));
    connect(ui->N9, SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));

    connect(ui->add, SIGNAL(clicked(bool)),this,SLOT(addSubMulDivClickHandler()));
    connect(ui->mul, SIGNAL(clicked(bool)), this, SLOT(addSubMulDivClickHandler()));
    connect(ui->div, SIGNAL(clicked(bool)),this, SLOT(addSubMulDivClickHandler()));
    connect(ui->sub, SIGNAL(clicked(bool)),this, SLOT(addSubMulDivClickHandler()));

    connect(ui->clear, SIGNAL(clicked(bool)), this, SLOT(clearAndEnterClickHandler()));
    connect(ui->enter, SIGNAL(clicked(bool)),this,SLOT(clearAndEnterClickHandler()));

    connect(ui->num1, SIGNAL(textChanged(QString)), this, SLOT(numberOneChanged()));
    connect(ui->num2, SIGNAL(textChanged(QString)), this, SLOT(numberTwoChanged()));

    state = 1;
}

MainWindow::~MainWindow()
{
    delete ui;


}
void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name= button->objectName();
    qDebug() << "Button name: " << name;
    QStringList a ;
    a = name.split(QString(),Qt::SkipEmptyParts);
    /*
    qDebug() << "Split: " << a.length();
    qDebug() << "a = " << a;
    qDebug() << a[1];
    //*/

    if(state == 1) {
        number1 = number1+a[1];
        float n1=number1.toFloat();
        qDebug() <<"state 1: "<< n1;
        ui->num1->setText(number1);
    }
    else if (state == 2)  {
        number2 = number2+a[1];
        float n2=number2.toFloat();
        qDebug() <<"state 2: "<< n2;
        ui->num2->setText(number2);
    }
    else {
        ResetLineEdits();
        number1 = a[1];
        state = 1;
        ui->num1->setText(number1);
    }

}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name= button->objectName();
    qDebug() << "Button name: " << name;

    if(name=="clear") {
        operand = 0;
        state = 1;
        ResetLineEdits();
    }
    else {
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();


        qDebug()<<"operand =" <<operand;
        switch(operand) {
        case 0:
            qDebug() <<operand << " = +";
            result=n1+n2;
            break;
        case 1:
            qDebug() <<operand << " = -";
            result=n1-n2;
            break;
        case 2:
            qDebug() <<operand << " = *";
            result=n1*n2;
            break;
        case 3:
            qDebug() <<operand << " = /";
            result=n1/n2;
            break;
        }

        ui->result->setText(QString::number(result));
        //ResetLineEdits();
        state = 3;
        operand=4;
    }

}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name= button->objectName();
    qDebug() << "Button name: " << name;

    if(name == "add") {
        operand = 0;
    }
    else if (name == "sub") {
        operand = 1;
    }
    else if (name == "mul") {
        operand = 2;
    }
    else {
        operand = 3;
    }

    state = 2;
    qDebug()<<"Operand is: " <<operand;
}

void MainWindow::ResetLineEdits()
{
    number1 = "";
    number2 = "";
    ui->num1->setText(number1);
    ui->num2->setText(number2);
    result=0;
    ui->result->setText(QString::number(result));
}

void MainWindow::numberOneChanged()
{
    state=1;
    number1 = ui->num1->text();
    qDebug() << "Number 1 :" << number1;

}

void MainWindow::numberTwoChanged()
{
    state=2;
    number2 = ui->num2->text();
    qDebug() << "Number 2 :" <<number2;

}
