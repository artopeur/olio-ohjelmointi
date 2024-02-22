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
    connect(ui->btnGetAllBooks, SIGNAL(clicked(bool)), this, SLOT(getAllBooks()));

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
    net = new network();
    qDebug()<<"Made network constructor";
    net->Login(loginurl);
    connect(net, SIGNAL(LoginSignal()), this, SLOT(getLoginSlot()));

}

void MainWindow::getAllBooksSlot()
{
    qDebug();
    qDebug()<<"In getAllBooksSlot-main:  SIGNAL readData() was received.";
    QByteArray dataInput=net->getResponse();
    qDebug()<<"The response= "<<dataInput;

    ui->txt_data->setText(dataInput);
    qDebug();


    QJsonDocument json_doc = QJsonDocument::fromJson(dataInput);
    QJsonArray json_array = json_doc.array();
    QString book;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       book+=QString::number(json_obj["id_book"].toInt())+", "+json_obj["name"].toString()+", "+json_obj["author"].toString() + "\r";
    }
    qDebug()<<book;
    ui->txt_data->setText(book);
}

void MainWindow::getLoginSlot() {
    qDebug();
    qDebug()<<"In getLoginSlot-main:  SIGNAL Login() was received.";
    loginToken = net->getResponse();
    qDebug()<<"The response= "<<loginToken;
    bearer = "Bearer " + (loginToken);
    qDebug()<<"Bearer: "<<bearer;
    // change to say connected when connection established and failed if was failed connection.
    // will need to define unauthorized access too.
    ui->txt_data->setText(loginToken);


}

void MainWindow::getAllBooks()
{
    net = new network;
    connect(net, SIGNAL(getData()),this,SLOT(getAllBooksSlot()));
    net->sendRequest(url, &bearer);
    qDebug()<<"Request sent";

}
