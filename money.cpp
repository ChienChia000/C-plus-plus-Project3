#include "money.h"

#include<QFont>

#include"scenemanager.h"

extern Scenemanager* scenemanager;

Money::Money() : QGraphicsTextItem()
{
    //draw the text
    setPlainText(QString::number(scenemanager->money));    //1000
    setDefaultTextColor(Qt::yellow);
    setPos(x()+1030,y()+665);
    setFont(QFont("main",30));
}
void Money::money_increase(int add_money)
{
    scenemanager->money = scenemanager->money + add_money;
    if(scenemanager->get_scenenum() == 1)
    {
        setPlainText(QString::number(scenemanager->money));
    }
}

