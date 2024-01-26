#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // yhdistetään slottiin setTextSlot.
    // signaali (ui->pushbuttonista -> tähän (slot setTextSlot())?
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(setTextSlot()));

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(setButtonActive()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// setTextSlot() määritys
void MainWindow::setTextSlot()
{
    ui->lineEdit->setText("Testi");
    ui->pushButton->setDisabled(1);
    ui->pushButton->setVisible(0);
}

void MainWindow::setButtonActive()
{
    ui->pushButton->setVisible(1);
    ui->pushButton->setDisabled(0);
}
