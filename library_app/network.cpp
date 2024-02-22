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

void network::Login(QString login_url)
{
    //body
    QJsonObject jsonObj;
    jsonObj.insert("password", "pass01");
    jsonObj.insert("username","user01");

    // degub jsonObj
    qDebug()<<"JSON: "<<jsonObj;


    qDebug()<<"GetLogin: ";
    qDebug()<<login_url;
    //manager
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this,SLOT(loginSlot(QNetworkReply*)));
    QUrl qrl(login_url);
   //request
    QNetworkRequest Request(qrl);
    // headers
    Request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // send the request
    //reply = manager->get(Request);
    qDebug()<<"Json object network: "<<jsonObj;
    qDebug()<<"JsonDocument: "<< QJsonDocument(jsonObj).toJson();

    reply = manager->post(Request, QJsonDocument(jsonObj).toJson());

}

void network::sendRequest(QString site_url, QByteArray* token)
{
    qDebug()<<site_url<<" : "<<token;
}

void network::deleteRequest(QString site_url)
{
    qDebug()<<site_url<<" : "<<token;
}

void network::loginSlot(QNetworkReply *reply)
{
    response=reply->readAll();
    //qDebug()<<reply->readAll();
    emit LoginSignal();
}

void network::readData(QNetworkReply *reply)
{
    qDebug()<<reply->readAll();
}




//========================================================================//
// vanhat koodit, poistettu käytöstä..====================================//
/*
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
*/
