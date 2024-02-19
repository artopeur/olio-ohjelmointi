#include "form2.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectForm2 = new Form2(this);

    connect(ui->btnSave,SIGNAL(clicked(bool)), this, SLOT(btnSave_clicked()));
    connect(ui->btnOpenForm2, SIGNAL(clicked(bool)), this, SLOT(btnOpenForm2_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnSave_clicked()
{

    fname=ui->textFName->text();
    ui->labelResult->setText("Terve " + fname);
}


void MainWindow::btnOpenForm2_clicked()
{

    connect(objectForm2, SIGNAL(lnameIsSet()),this, SLOT(slotLnameShow()));
    objectForm2->setNameFromMainwindow(fname);
    //objectForm2->show();
    objectForm2->open();
}

void MainWindow::slotLnameShow()
{
    QString lastname=objectForm2->getLname();
    ui->labelLname->setText(lastname);
}

