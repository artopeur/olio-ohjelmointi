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
    net->getLogin(loginurl);
    connect(net, SIGNAL(AllBooks()), this, SLOT(getAllBooksSlot()));

    //net->getAllBooks(url);


    // doesn't work
    //network::getAsiakas("1");

    // should be the right one.
    //net->getAsiakas("1");

}

void MainWindow::getAllBooksSlot()
{
    qDebug();
    qDebug()<<"In getAllBooksSlot-main:  SIGNAL AllBooks() was received.";
    QByteArray response = net->getResponse();
    qDebug()<<"The response= "<<response;
}
