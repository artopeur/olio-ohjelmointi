#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Form2.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnSave, SIGNAL(clicked(bool)),this,SLOT(btnSave()));
    connect(ui->btnTest, SIGNAL(clicked(bool)),this,SLOT(btnTest()));
    connect(ui->btnOpenForm2, SIGNAL(clicked(bool)),this,SLOT(btnOpenForm2()));

    ui->btnOpenForm2->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnTest()
{
    x++;
    QString s = QString::number(x);
    qDebug() << "test button pressed: "<<x<<" times.";
    ui->labelResult->setText("Painiketta painettu: " + s + " kertaa");
}


void MainWindow::btnSave()
{
    fname = ui->textFname->text();
    lname = ui->textLname->text();
    ui->labelMessage->setText("Terve " + fname + " " + lname);
    qDebug()<<fname<<" "<<lname;
    ui->btnOpenForm2->setDisabled(false);
}


void MainWindow::btnOpenForm2()
{
    qDebug()<<"btnOpenForm2 klikattu";
    //QString fname = ui->textFname->text();
    form2 *objectForm2 = new form2(this);
    objectForm2->setFname(fname);
    objectForm2->setLname(lname);
    //objectForm2->open(); //Mainwodow:n ei voi kirjoitta, jos Form2 auki
    //objectForm2->exec();
    objectForm2->show(); // Mainwindow:n voi kirjoittaa, jos Form2 auki.
    ui->btnOpenForm2->setDisabled(true); // estetään painikkeen btnOpenForm2 klikkaaminen

}

