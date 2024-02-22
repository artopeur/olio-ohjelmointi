#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"ui contructor";

    // connects for slots
    connect(ui->btnConnect, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));

}

MainWindow::~MainWindow()
{
    qDebug()<<"ui destructor";
    delete ui;      // delete ui
    delete net;     // delete network
}

void MainWindow::buttonPressed()
{
    // get all data?
    net = new network;
    qDebug()<<"Made network constructor";
    net->Login(loginurl);
    connect(net, SIGNAL(LoginSignal()), this, SLOT(getLoginSlot()));
}

void MainWindow::getAllBooksSlot()
{
    qDebug();
    qDebug()<<"In getAllBooksSlot-main:  SIGNAL AllBooks() was received.";
    QByteArray response = net->getResponse();
    qDebug()<<"The response= "<<response;
    ui->txt_data->setText(response);
}

void MainWindow::getLoginSlot() {
    qDebug();
    qDebug()<<"In getLoginSlot-main:  SIGNAL Login() was received.";
    loginToken = net->getResponse();
    qDebug()<<"The response= "<<loginToken;
    // change to say connected when connection established and failed if was failed connection.
    // will need to define unauthorized access too.
    ui->txt_data->setText(loginToken);

}
