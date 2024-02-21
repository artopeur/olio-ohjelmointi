#include "network.h"

network::network() {
    qDebug() << "network constructor";
    // Got lost here. Questions and more questions.
    //connect(reply, &QNetworkReply::finished, this, SLOT(getAllBooksSlot(QNetworkReply*)));

    qDebug()<<url;
    //emit AllBooks();
}

network::~network() {
    qDebug() <<"network destructor";
}

QByteArray network::getResponse() const
{
    return response;
}

void network::getAsiakas(QString asiakasId)
{
    qDebug();
    QByteArray webToken = "asdb938sdk84/2";
    QString site_url="http://localhost:3000/book/" + asiakasId + "/";
    qDebug() << "RESTAPIDLL::getAsiakas = " + site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "Application/Json");
    QByteArray token = "Bearer " + webToken;
    request.setRawHeader(QByteArray("Authorization"), (webToken));

    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(asiakasGetSlot(QNetworkReply*)));
    getManager->get(request);

    //qDebug()<<reply->readAll();
    qDebug()<<token;
}

void network::getAllBooks(QString site_url)
{
    qDebug();
    qDebug()<<"In getAllBooks - network: ";
    qDebug()<<site_url;
    emit AllBooks();
    getAllManager = new QNetworkAccessManager(this);
    connect(getAllManager, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(getAllBooksSlot(QNetworkReply*)));

/*

    QNetworkRequest *request;
    getManager->get(request);
    qDebug()<<reply->readAll();

    //QByteArray webToken = "asdb938sdk84/2";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "Application/Json");

    //QByteArray token = "Bearer " + webToken;
    //request.setRawHeader(QByteArray("Authorization"), (token));
    connect(getManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAllBooksSlot(QNetworkReply*)));
    //getManager->get(request);
    emit AllBooks();
*/
}
void network::asiakasGetSlot(QNetworkReply *reply)
{
    qDebug();
    qDebug()<<"In asiakasGetSlot: ";


    //QByteArray response_data=reply->readAll();
    //qDebug()<<response_data;
}

void network::getAllBooksSlot(QNetworkReply *reply)
{
    qDebug();
    qDebug()<<"In getAllBooksSlot: ";
    qDebug()<<reply;
    //qDebug()<<reply;
    //emit AllBooks();
    //QByteArray response_data = reply->readAll();
}
