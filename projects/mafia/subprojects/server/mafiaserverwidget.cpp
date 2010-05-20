/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#include "mafiaserverwidget.h"
#include "ui_mafiaserverwidget.h"

MafiaServerWidget::MafiaServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MafiaServerWidget)
{
    ui->setupUi(this);
}

MafiaServerWidget::~MafiaServerWidget()
{
    delete ui;
}

void MafiaServerWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
