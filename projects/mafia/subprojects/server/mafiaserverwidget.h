/************************************************
** Copyright (C) 2010 Yuri 'Ree' Borisoff
** You can freely use, copy and modify this code.
** If you have any questions, you can contact me at
** yuri.borisoff@gmail.com
*************************************************/

#ifndef MAFIASERVERWIDGET_H
#define MAFIASERVERWIDGET_H

#include <QWidget>

namespace Ui {
    class MafiaServerWidget;
}

class MafiaServerWidget : public QWidget {
    Q_OBJECT
public:
    explicit MafiaServerWidget(QWidget *parent = 0);
    ~MafiaServerWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MafiaServerWidget *ui;
};

#endif // MAFIASERVERWIDGET_H
