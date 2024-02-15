#include "form2.h"
#include "ui_form2.h"

form2::form2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::form2)
{
    ui->setupUi(this);
}

form2::~form2()
{
    qDebug()<<"Form2 olio tuhottiin";
    delete ui;
}

void form2::setFname(QString fn)
{
    qDebug()<<"Fname asetettu";
    qDebug()<<"fname="+fn;
    ui->labelFname->setText(fn);
}

void form2::setLname(QString ln)
{
    ui->labelLname->setText(ln);
}
