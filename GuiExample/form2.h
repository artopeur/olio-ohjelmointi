#ifndef FORM2_H
#define FORM2_H

#include <QDialog>

namespace Ui {
class form2;
}

class form2 : public QDialog
{
    Q_OBJECT

public:
    explicit form2(QWidget *parent = nullptr);
    ~form2();
    void setFname(QString fn);
    void setLname(QString ln);

private:
    Ui::form2 *ui;
};

#endif // FORM2_H
