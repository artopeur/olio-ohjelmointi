#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class network : public QObject
{
    Q_OBJECT
public:
    network();
    ~network();

    QString url="http://localhost:3000/book";
    int port=3000;
    QByteArray response;
    QByteArray token;
    QNetworkReply *reply;
    QNetworkAccessManager* manager;

    QByteArray getResponse() const;

    void Login(QString login_url);
    void sendRequest(QString site_url, QByteArray* token);
    void deleteRequest(QString site_url);


private slots:
    void loginSlot(QNetworkReply* reply);
    void readData(QNetworkReply* reply);



signals:
    void LoginSignal();
    void getData();



private:
};

#endif // NETWORK_H
