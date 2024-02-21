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
    reply=getManager->get(request);

    //qDebug()<<reply->readAll();
    qDebug()<<token;
}

void network::getAllBooks(QString site_url)
{
    qDebug();
    qDebug()<<"In getAllBooks - network: ";
    qDebug()<<site_url;

    getAllManager = new QNetworkAccessManager(this);
    connect(getAllManager, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(getAllBooksSlot(QNetworkReply*)));
    QUrl qrl(site_url);
    QNetworkRequest request(qrl);
    getAllManager->get(request);
}
void network::asiakasGetSlot(QNetworkReply *reply)
{
    qDebug();
    qDebug()<<"In asiakasGetSlot: ";
    qDebug()<<reply->readAll();

    //QByteArray response_data=reply->readAll();
    //qDebug()<<response_data;
}

void network::getAllBooksSlot(QNetworkReply *reply)
{
    qDebug();
    qDebug()<<"In getAllBooksSlot: ";
    //qDebug()<<reply->readAll();
    response=reply->readAll();
    qDebug()<<response;
    emit AllBooks();

}
void network::loginSlot(QNetworkReply *reply)
{
    qDebug()<<"LoginSlot: ";
    qDebug()<<reply->readAll();
}

QByteArray network::getLogin(QString login_url)
{
    qDebug()<<"GetLogin: ";
    qDebug()<<login_url;
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(loginSlot(QNetworkReply*)));
    QUrl qrl(login_url);
    QNetworkRequest loginRequest(qrl);
    reply = loginManager->get(loginRequest);
}
