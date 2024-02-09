#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void timeout();
private:
    Ui::MainWindow *ui;
    short player1Time = 0;
    short player2Time = 0;
    short currentPlayer = 0;
    short gameTime = 0;

    //QObject *pQTimer;
    QTimer * pQTimer;

    void updateProgressBar();
    void setGameInfoText(QString, short);

private slots:
    void startGame();
    void stopGame();
    void playValue();
    void timerRun();
    void switchPlayer();
};
#endif // MAINWINDOW_H
