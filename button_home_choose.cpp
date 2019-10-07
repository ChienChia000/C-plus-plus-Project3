#include "button_home_choose.h"

#include"page_welcome.h"
#include"scenemanager.h"
#include<QGraphicsScene>
#include<QTimer>

extern Scenemanager* scenemanager;

Button_home_choose::Button_home_choose(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem()
{
    //set the icon position
    setPos(0,80);
    //draw the icon
    setPixmap(QPixmap(":/picture/button_home_choose.png"));
}

