#include "button_welcome.h"

#include"page_welcome.h"
#include"scenemanager.h"
#include<QGraphicsScene>
#include<QTimer>

extern Scenemanager* scenemanager;

Button_welcome::Button_welcome(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem()
{
    welcome_num=0;
    //set the icon position
    setPos(0,0);
    //draw the icon
    setPixmap(QPixmap(":/picture/page_welcome_1.png"));

    QTimer* timer_button = new QTimer(this);
    connect(timer_button,SIGNAL(timeout()),this,SLOT(change()));
    timer_button->start(800);
}
void Button_welcome::change()
{
    //change to show button
    if(welcome_num == 0)
    {
        setPixmap(QPixmap(":/picture/page_welcome.png"));
        welcome_num = 1;
    }
    else if(welcome_num == 1)
    {
        setPixmap(QPixmap(":/picture/page_welcome_1.png"));
        welcome_num = 0;
    }
}
