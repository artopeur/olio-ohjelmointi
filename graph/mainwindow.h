#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QtCore>
#include <QCoreApplication>
#include <Qdebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString guess="";
    int randomNumber = 0;
    int playerGuess = 0;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void makeRandom();
private slots:

    void on_StartButton_clicked();

    void on_Button0_clicked();
    void on_text_guess_textChanged();


    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_pushButtonCheck_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
