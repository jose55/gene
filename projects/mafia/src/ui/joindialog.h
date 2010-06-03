/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef JOINDIALOG_H
#define JOINDIALOG_H

#include <QDialog>

namespace Ui {
    class JoinDialog;
}

class JoinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit JoinDialog(QWidget *parent = 0);
    ~JoinDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::JoinDialog *ui;
};

#endif // JOINDIALOG_H
