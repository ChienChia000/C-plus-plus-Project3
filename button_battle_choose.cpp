#include "button_battle_choose.h"

#include"scenemanager.h"
#include<QGraphicsScene>

extern Scenemanager* scenemanager;

Button_battle_choose::Button_battle_choose(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem()
{
    button_num = 0;
    //set the icon position
    setPos(62,147);
    //draw the icon
    setPixmap(QPixmap(":/picture/button_choose_stage.png"));

    timer_battle_choose = new QTimer(this);
    connect(timer_battle_choose,SIGNAL(timeout()),this,SLOT(change()));
    timer_battle_choose->start(800);
}
void Button_battle_choose::change()
{
    //change to flash the button
    if(button_num == 0)
    {
        setPixmap(QPixmap(":/picture/button_choose_stage_1.png"));
        button_num = 1;
    }
    else if(button_num == 1)
    {
        setPixmap(QPixmap(":/picture/button_choose_stage.png"));
        button_num = 0;
    }
}
