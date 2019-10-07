#include "page_manage_minion.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>

extern Scenemanager* scenemanager;

Page_manage_minion::Page_manage_minion()
{
    flag =0;
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_manage_minion.png")));

    money = new Money();
    addItem(money);

    choose_num=1;
    choose_hero_num=1;

    minion_deck_left = new Minion(3,scenemanager->deck_player_left[choose_num]);
    addItem(minion_deck_left);

    //set hero

    minion_hero = new Minion(4,scenemanager->deck_player_battle[1],1);
    addItem(minion_hero);
    //set other battle minion
    minion_1 = new Minion(4,scenemanager->deck_player_battle[2],2);
    addItem(minion_1);
    minion_2 = new Minion(4,scenemanager->deck_player_battle[3],3);
    addItem(minion_2);
    minion_3 = new Minion(4,scenemanager->deck_player_battle[4],4);
    addItem(minion_3);
    minion_4 = new Minion(4,scenemanager->deck_player_battle[5],5);
    addItem(minion_4);


}
void Page_manage_minion::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(flag==0)
        {
            if(scenemanager->player_deck_left_flag>=0)
            {
                flag=1;
                choose_hero_num=1;
                flash_hero_mark = new Flash_button(6);
                addItem(flash_hero_mark);
            }
        }
        else if(flag==1)
        {
            flag=0;
            delete flash_hero_mark;
            int temp=0;
            temp=scenemanager->deck_player_battle[choose_hero_num];
            scenemanager->deck_player_battle[choose_hero_num]=scenemanager->deck_player_left[choose_num];
            scenemanager->deck_player_left[choose_num]=temp;

            //sort the deck_player_left
            temp=0;
            for(int i=1;i<=scenemanager->player_deck_left_flag;++i)
            {
                for(int j=i+1;j<=scenemanager->player_deck_left_flag;j++)
                {
                    if(scenemanager->deck_player_left[i] >= scenemanager->deck_player_left[j])
                    {
                        temp = scenemanager->deck_player_left[i];
                        scenemanager->deck_player_left[i]=scenemanager->deck_player_left[j];
                        scenemanager->deck_player_left[j]=temp;
                    }
                }
            }//end for

            //show the exchange cards
            if(choose_hero_num==1)
            {
                delete minion_hero;
                minion_hero = new Minion(4,scenemanager->deck_player_battle[choose_hero_num],1);
                addItem(minion_hero);
            }
            else if(choose_hero_num==2)
            {
                delete minion_1;
                minion_1 = new Minion(4,scenemanager->deck_player_battle[choose_hero_num],2);
                addItem(minion_1);
            }
            else if(choose_hero_num==3)
            {
                delete minion_2;
                minion_2 = new Minion(4,scenemanager->deck_player_battle[choose_hero_num],3);
                addItem(minion_2);
            }
            else if(choose_hero_num==4)
            {
                delete minion_3;
                minion_3 = new Minion(4,scenemanager->deck_player_battle[choose_hero_num],4);
                addItem(minion_3);
            }
            else if(choose_hero_num==5)
            {
                delete minion_4;
                minion_4 = new Minion(4,scenemanager->deck_player_battle[choose_hero_num],5);
                addItem(minion_4);
            }
            choose_num=1;
            delete minion_deck_left;
            minion_deck_left = new Minion(3,scenemanager->deck_player_left[choose_num]);
            addItem(minion_deck_left);
        }
    }
    else if(event->key() == Qt::Key_Escape)
    {
        int leave=0;
        for(int i=1;i<=5;i++)
        {
            if(scenemanager->deck_player_battle[i] == 0)
            {
                leave=1;
                break;
            }
        }
        if(leave == 0)
        {
            clear();
            delete this;
            scenemanager->changescene(1);
        }
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(flag==0)
        {
            if(choose_num>1 && choose_num<=scenemanager->player_deck_left_flag)
            {
                choose_num=choose_num-1;
                delete minion_deck_left;

                flash_button = new Flash_button(4);
                addItem(flash_button);

                minion_deck_left = new Minion(3,scenemanager->deck_player_left[choose_num]);
                addItem(minion_deck_left);
            }
        }
        else if(flag==1)
        {
            if(choose_hero_num>1 && choose_hero_num<=5)
            {
                choose_hero_num = choose_hero_num - 1;
                if(choose_hero_num == 1)
                {
                    flash_hero_mark->setPixmap(QPixmap(":/picture/button_manage_minion_hero.png"));
                    flash_hero_mark->setPos(47,52);
                }
                else if(choose_hero_num<=5 && choose_hero_num>=2)
                {
                    flash_hero_mark->setPixmap(QPixmap(":/picture/button_manage_minion.png"));
                    flash_hero_mark->setPos(flash_hero_mark->x()-236,107);
                }
            }
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(flag==0)
        {
            if(choose_num>=1 && choose_num<scenemanager->player_deck_left_flag)
            {
                choose_num=choose_num+1;
                delete minion_deck_left;

                flash_button = new Flash_button(5);
                addItem(flash_button);

                minion_deck_left = new Minion(3,scenemanager->deck_player_left[choose_num]);
                addItem(minion_deck_left);
            }
        }
        else if(flag==1)
        {
            if(choose_hero_num>=1 && choose_hero_num<5)
            {
                choose_hero_num = choose_hero_num + 1;
                if(choose_hero_num == 1)
                {
                    flash_hero_mark->setPixmap(QPixmap(":/picture/button_manage_minion_hero.png"));
                    flash_hero_mark->setPos(47,52);
                }
                else if(choose_hero_num == 2)
                {
                    flash_hero_mark->setPixmap(QPixmap(":/picture/button_manage_minion.png"));
                    flash_hero_mark->setPos(flash_hero_mark->x()+269,107);
                }
                else if(choose_hero_num<=5 && choose_hero_num>=3)
                {
                    flash_hero_mark->setPixmap(QPixmap(":/picture/button_manage_minion.png"));
                    flash_hero_mark->setPos(flash_hero_mark->x()+236,107);
                }
            }
        }
    }
}
