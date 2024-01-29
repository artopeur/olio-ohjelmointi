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
    int numberOfGuesses = 0;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void makeRandom();
private slots:

    void StartButton_clicked();
    void text_guess_textChanged();

    void Button0_clicked();
    void Button1_clicked();
    void Button2_clicked();
    void Button3_clicked();
    void Button4_clicked();
    void Button5_clicked();
    void Button6_clicked();
    void Button7_clicked();
    void Button8_clicked();
    void Button9_clicked();

    void pushButtonCheck_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
