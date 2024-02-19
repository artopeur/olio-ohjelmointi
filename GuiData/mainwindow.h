#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "form2.h"
#include <QMainWindow>

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

private slots:
    void btnSave_clicked();
    void btnOpenForm2_clicked();
    void slotLnameShow();

private:
    QString fname;
    Form2 *objectForm2;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
