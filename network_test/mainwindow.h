#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString url;
    void checkSite(QString url);

private slots:
    void btnTest_clicked();
    void readData(QNetworkReply*);

private:
    Ui::MainWindow *ui;

signals:
    void finished();
};
#endif // MAINWINDOW_H
