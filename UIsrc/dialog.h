#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "new_window.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public:
    new_window *new_win;

private:
    Ui::Dialog *ui;

private slots:
    void readFile();
    void open();
    void addone();
    void deleteone();
};

#endif // DIALOG_H
