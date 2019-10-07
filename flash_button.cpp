#include "flash_button.h"

#include"scenemanager.h"
#include<QGraphicsScene>

extern Scenemanager* scenemanager;

Flash_button::Flash_button(int type, QGraphicsItem *parent):QObject(), QGraphicsPixmapItem()
{
    button_num = type;
    flag=0;
    //set the icon position
    if(type == 0)
    {
        setPos(62,178);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_buy_card_left.png"));
        timer_flash_button = new QTimer(this);
        connect(timer_flash_button,SIGNAL(timeout()),this,SLOT(change()));
        timer_flash_button->start(200);
    }
    else if(type == 1)
    {
        setPos(890,178);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_buy_card_right.png"));
        timer_flash_button = new QTimer(this);
        connect(timer_flash_button,SIGNAL(timeout()),this,SLOT(change()));
        timer_flash_button->start(200);
    }
    else if(type == 2)
    {
        setPos(1004,534);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_buy_card_money_1.png"));
    }
    else if(type == 3)
    {
        setPos(976,498);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_buy_card_money_1.png"));
    }
    else if(type == 4)
    {
        setPos(289,433);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_manage_minion_left.png"));
        timer_flash_button = new QTimer(this);
        connect(timer_flash_button,SIGNAL(timeout()),this,SLOT(change()));
        timer_flash_button->start(200);
    }
    else if(type == 5)
    {
        setPos(822,432);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_manage_minion_right.png"));
        timer_flash_button = new QTimer(this);
        connect(timer_flash_button,SIGNAL(timeout()),this,SLOT(change()));
        timer_flash_button->start(200);
    }
    else if(type ==6)//choose hero
    {
        setPos(47,52);
        //draw the icon
        setPixmap(QPixmap(":/picture/button_manage_minion_hero.png"));
    }


}
void Flash_button::change()
{
    //change to flash the button
    if(button_num == 0 || button_num == 1 || button_num == 4 || button_num ==5 )
    {
        delete this;
        return;
    }
    else if(button_num == 2 || button_num == 3)
    {
        if(flag == 0)
        {
            flag = 1;
            setPixmap(QPixmap(":/picture/button_buy_card_money_2.png"));
        }
        else if(flag == 1)
        {
            flag = 0;
            setPixmap(QPixmap(":/picture/button_buy_card_money_1.png"));
        }
    }
}
