#include "text.h"

#include<QFont>

#include"scenemanager.h"

extern Scenemanager* scenemanager;

Text::Text(int type, QGraphicsItem* parent, int initial_HP) : QGraphicsTextItem(parent)
{
    if(type == 1)   //set mana
    {
        //initial the mana to 20
        mana = 20;
        //draw the text
        setPlainText(QString("MANA : ")+QString::number(mana));    //MANA: 20 $
        setDefaultTextColor(Qt::yellow);
        setPos(x()+993,y()-5);
        setFont(QFont("main",40));
    }
    else if(type ==2)   //set minion_HP
    {
        //draw the text
        setPlainText(QString::number(initial_HP));    //HP: 3000
        setDefaultTextColor(Qt::red);
        setFont(QFont("main",20));
    }
    else if(type ==3)   //set tower_HP
    {
        //draw the text
        setPlainText(QString::number(initial_HP));    //HP: 3000
        setDefaultTextColor(Qt::red);
        setFont(QFont("main",20));
    }
    else if(type == 4)
    {
        //draw the text
        setPlainText(QString("$ + ")+QString::number(scenemanager->battle_prize));    //HP: 3000
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("main",80));
    }

}
void Text::mana_increase()
{
    if(mana<20)
    {
//        if(scenemanager->game->time_battle->get_time_battle()<=60)
//        {
//            mana=mana+2;
//            if(mana>10)
//                mana=10;
//            setPlainText(QString("MANA : ")+QString::number(mana));
//        }
//        else
//        {
            mana++;
            if(mana>20)
                mana=10;
            setPlainText(QString("MANA : ")+QString::number(mana));
//        }
    }
//    if(scenemanager->game->time_battle->get_time_battle()<=30)
//    {
//        mana+=2;
//        setPlainText(QString("MANA : ")+QString::number(mana));
//    }
}

void Text::mana_decrease(int decrease_num)
{
    mana = mana -decrease_num;
    setPlainText(QString("MANA : ")+QString::number(mana));
}

int Text::get_mana()
{
    return mana;
}
