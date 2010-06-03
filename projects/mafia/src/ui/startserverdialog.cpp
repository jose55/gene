/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "startserverdialog.h"
#include "ui_startserverdialog.h"

StartServerDialog::StartServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartServerDialog)
{
    ui->setupUi(this);
}

StartServerDialog::~StartServerDialog()
{
    delete ui;
}

void StartServerDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
