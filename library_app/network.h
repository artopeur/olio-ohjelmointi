#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>

class network : public QObject
{
    Q_OBJECT
public:
    network();
    ~network();

    QString url="http://localhost:3000/book";
    int port=3000;
    QByteArray response;
    //QNetworkReply *reply =;
    QNetworkAccessManager* getManager;
    QNetworkAccessManager* getAllManager;

    void getAsiakas(QString asiakasId);
    void getAllBooks(QString site_url);

    QByteArray getResponse() const;

private slots:
    void asiakasGetSlot(QNetworkReply* reply);
    void getAllBooksSlot(QNetworkReply* reply);
signals:
    void getData();
    void AllBooks();


private:
};

#endif // NETWORK_H
