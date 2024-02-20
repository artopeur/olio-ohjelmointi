#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnTest, SIGNAL(clicked(bool)), this, SLOT(btnTest_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::btnTest_clicked()
{

    url = "http://localhost:3000/login";
    checkSite(url);
}

void MainWindow::readData(QNetworkReply* reply) {
    qDebug()<<"Received signal, went to slot";
    qDebug()<<reply->readAll();
    //qDebug() << reply;
}
void MainWindow::checkSite(QString url) {
    QUrl qrl(url);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readData(QNetworkReply *)));
    QNetworkRequest request(qrl);


    reply=manager->get(request);
    //QNetworkRequest request(url);
    qDebug()<<"request sent.";
}
