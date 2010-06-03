/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef STARTSERVERDIALOG_H
#define STARTSERVERDIALOG_H

#include <QDialog>

namespace Ui {
    class StartServerDialog;
}

class StartServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartServerDialog(QWidget *parent = 0);
    ~StartServerDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::StartServerDialog *ui;
};

#endif // STARTSERVERDIALOG_H
