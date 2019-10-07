#include "price_minion.h"

#include<QFont>

#include"scenemanager.h"

extern Scenemanager* scenemanager;

Price_minion::Price_minion(int flag) : QGraphicsTextItem()
{
    //draw the text
    if(flag == 1)
        setPlainText(QString::number(200));    //1000
    else
        setPlainText(QString::number(scenemanager->page_buy_card->minion->get_minion_money()));
    setDefaultTextColor(Qt::yellow);
    setPos(x()+1030,y()+565);
    setFont(QFont("main",30));
}
