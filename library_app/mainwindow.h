#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"



//#include <QNetwork.h>

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

    // create network from dynamic memory
    network* net;
    QString loginurl="http://localhost/login";
    QString url = "http://localhost/book";

private slots:
    void buttonPressed();

private slots:
    void getAllBooksSlot();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
