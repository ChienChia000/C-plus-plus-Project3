#include "minion.h"

#include"scenemanager.h"

#include<QTimer>
#include<QGraphicsScene>
#include<QVector>
#include<QtMath>
#include<QList>

#include<QFont>
#include<QGraphicsTextItem>

extern Scenemanager* scenemanager;

Minion::Minion(int type, int minion_number, int hero):QObject(), QGraphicsPixmapItem()
{
    //set the type
    class_type = type;
    minion_type = minion_number;
    minion_money=0;

    //set minion picture
    if(minion_type == 1)
        minion.load(":/picture/card_minion_1.png");
    else if(minion_type == 2)
        minion.load(":/picture/card_minion_2.png");
    else if(minion_type == 3)
        minion.load(":/picture/card_minion_3.png");
    else if(minion_type == 4)
        minion.load(":/picture/card_minion_4.png");
    else if(minion_type == 5)
        minion.load(":/picture/card_minion_5.png");
    else if(minion_type == 6)
        minion.load(":/picture/card_minion_6.png");
    else if(minion_type == 7)
        minion.load(":/picture/card_minion_7.png");
    else if(minion_type == 8)
        minion.load(":/picture/card_minion_8.png");
    else if(minion_type == 9)
        minion.load(":/picture/card_minion_9.png");
    else if(minion_type == 10)
        minion.load(":/picture/card_minion_10.png");
    else if(minion_type == 11)
        minion.load(":/picture/card_minion_11.png");
    else if(minion_type == 12)
        minion.load(":/picture/card_minion_12.png");
    else if(minion_type == 13)
        minion.load(":/picture/card_minion_13.png");
    else if(minion_type == 14)
        minion.load(":/picture/card_minion_14.png");
    else if(minion_type == 15)
        minion.load(":/picture/card_minion_15.png");
    else if(minion_type == 16)
        minion.load(":/picture/card_minion_16.png");
    else if(minion_type == 17)
        minion.load(":/picture/card_minion_17.png");
    else if(minion_type == 18)
        minion.load(":/picture/card_minion_18.png");
    else if(minion_type == 19)
        minion.load(":/picture/card_minion_19.png");
    else if(minion_type == 20)
        minion.load(":/picture/card_minion_20.png");

    if(class_type==1)
    {
        //this is for page_buy_card
        setPos(442,98);
        minion = minion.scaled(400,515);
        setPixmap(minion);
        if(minion_type == 1)
            minion_money=200;
        else if(minion_type == 2)
            minion_money=200;
        else if(minion_type == 3)
            minion_money=200;
        else if(minion_type == 4)
            minion_money=200;
        else if(minion_type == 5)
            minion_money=200;
        else if(minion_type == 6)
            minion_money=1500;
        else if(minion_type == 7)
            minion_money=1500;
        else if(minion_type == 8)
            minion_money=2000;
        else if(minion_type == 9)
            minion_money=2000;
        else if(minion_type == 10)
            minion_money=2000;
        else if(minion_type == 11)
            minion_money=2000;
        else if(minion_type == 12)
            minion_money=5000;
        else if(minion_type == 13)
            minion_money=5000;
        else if(minion_type == 14)
            minion_money=5000;
        else if(minion_type == 15)
            minion_money=5000;
        else if(minion_type == 16)
            minion_money=50000;
        else if(minion_type == 17)
            minion_money=50000;
        else if(minion_type == 18)
            minion_money=50000;
        else if(minion_type == 19)
            minion_money=50000;
        else if(minion_type == 20)
            minion_money=100000;
    }
    else if(class_type==2)
    {
        //this is for draw card
        setPos(442,98);
        QPixmap card_back(":/picture/card_original_back.png");
        card_back = card_back.scaled(400,515);
        setPixmap(card_back);
        minion_money=200;
    }
    else if(class_type==3)
    {
        //this is for page_manage_minion
        setPos(553,420);
        minion = minion.scaled(180,231);
        setPixmap(minion);
    }
    else if(class_type==4)
    {
        //this is for hero
        if(hero==1)
        {
            setPos(66,73);
            minion=minion.scaled(250,322);
            setPixmap(minion);
        }
        else if(hero ==2)
        {
            setPos(352,136);
            minion=minion.scaled(200,257);
            setPixmap(minion);
        }
        else if(hero ==3)
        {
            setPos(588,136);
            minion=minion.scaled(200,257);
            setPixmap(minion);
        }
        else if(hero ==4)
        {
            setPos(824,136);
            minion=minion.scaled(200,257);
            setPixmap(minion);
        }
        else if(hero ==5)
        {
            setPos(1060,136);
            minion=minion.scaled(200,257);
            setPixmap(minion);
        }
    }
}

int Minion::get_minion_money()
{
    return minion_money;
}
