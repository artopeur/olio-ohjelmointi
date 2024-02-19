#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Form2)
{
    ui->setupUi(this);

    connect(ui->btnSave, SIGNAL(clicked(bool)), this, SLOT(btnSave_clicked()));
}

Form2::~Form2()
{
    delete ui;
}

void Form2::setNameFromMainwindow(const QString &newNameFromMainwindow)
{
    nameFromMainwindow = newNameFromMainwindow;
    ui->labelFname->setText(nameFromMainwindow);
}

void Form2::btnSave_clicked()
{
    lname=ui->textLname->text();
    emit lnameIsSet();
    qDebug()<<lname;
    //this->close();
}

void Form2::closeEvent(QCloseEvent *e)
{
    qDebug()<<e;
    if(ui->textLname->text() == "") {
        emit lnameIsSet();
    }
    else {
        lname=ui->textLname->text();
        emit lnameIsSet();
    }

}

QString Form2::getLname() const
{
    return lname;
}

