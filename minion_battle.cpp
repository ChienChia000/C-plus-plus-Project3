#include "minion_battle.h"

#include<stdlib.h>  //rand()

#include<iostream>
using namespace std;

#include"scenemanager.h"

extern Scenemanager* scenemanager;
                                                                                             //hero 1:player hero 2:enemy hero
Minion_battle::Minion_battle(int minion_type, int minion_who, int minion_number, int hero)   //minion_who 1:player 2:enemy
{
    minion_who_am_I=minion_who;
    who=minion_type;
    who_hero = hero;
    minion_num = minion_number;
    //set tower
    if(minion_type == 1)
    {
        minion_HP = 100000;
        minion_attack = 10;
        minion_atk_range = 100;
        if(minion_who == 1)
        {
            tower.load(":/picture/tower_player.png");
            setPixmap(tower);
            setPos(0,220);
            minion_attack_x = 118;
            minion_attack_y = 362;
        }
        else if(minion_who == 2)
        {
            tower.load(":/picture/tower_enemy.png");
            setPixmap(tower);
            setPos(1160,220);
            minion_attack_x = 1160;
            minion_attack_y = 362;
        }
        minion_HP_text = new Text(3,this,minion_HP);
        minion_HP_text->setPos(5,-30);
    }
    //set player_deck
    else if(minion_type == 2)
    {
        if(minion_number == 1)
        {
            minion_card.load(":/picture/card_minion_1.png");
            minion_mana = 1;
        }
        else if(minion_number == 2)
        {
            minion_card.load(":/picture/card_minion_2.png");
            minion_mana = 2;
        }
        else if(minion_number == 3)
        {
            minion_card.load(":/picture/card_minion_3.png");
            minion_mana = 2;
        }
        else if(minion_number == 4)
        {
            minion_card.load(":/picture/card_minion_4.png");
            minion_mana = 3;
        }
        else if(minion_number == 5)
        {
            minion_card.load(":/picture/card_minion_5.png");
            minion_mana = 3;
        }
        else if(minion_number == 6)
        {
            minion_card.load(":/picture/card_minion_6.png");
            minion_mana = 3;
        }
        else if(minion_number == 7)
        {
            minion_card.load(":/picture/card_minion_7.png");
            minion_mana = 4;
        }
        else if(minion_number == 8)
        {
            minion_card.load(":/picture/card_minion_8.png");
            minion_mana = 5;
        }
        else if(minion_number == 9)
        {
            minion_card.load(":/picture/card_minion_9.png");
            minion_mana = 5;
        }
        else if(minion_number == 10)
        {
            minion_card.load(":/picture/card_minion_10.png");
            minion_mana = 5;
        }
        else if(minion_number == 11)
        {
            minion_card.load(":/picture/card_minion_11.png");
            minion_mana = 5;
        }
        else if(minion_number == 12)
        {
            minion_card.load(":/picture/card_minion_12.png");
            minion_mana = 7;
        }
        else if(minion_number == 13)
        {
            minion_card.load(":/picture/card_minion_13.png");
            minion_mana = 7;
        }
        else if(minion_number == 14)
        {
            minion_card.load(":/picture/card_minion_14.png");
            minion_mana = 7;
        }
        else if(minion_number == 15)
        {
            minion_card.load(":/picture/card_minion_15.png");
            minion_mana = 7;
        }
        else if(minion_number == 16)
        {
            minion_card.load(":/picture/card_minion_16.png");
            minion_mana = 9;
        }
        else if(minion_number == 17)
        {
            minion_card.load(":/picture/card_minion_17.png");
            minion_mana = 9;
        }
        else if(minion_number == 18)
        {
            minion_card.load(":/picture/card_minion_18.png");
            minion_mana = 9;
        }
        else if(minion_number == 19)
        {
            minion_card.load(":/picture/card_minion_19.png");
            minion_mana = 9;
        }
        else if(minion_number == 20)
        {
            minion_card.load(":/picture/card_minion_20.png");
            minion_mana = 10;
        }
        minion_card = minion_card.scaled(100,128);
        setPixmap(minion_card);
    }
    //set minion(soldiers)
    else if(minion_type == 3)
    {
        if(minion_number == 1)
        {
            minion.load(":/picture/minion1.png");
            minion_HP = 2000;
            minion_attack = 1;
            minion_atk_range = 20;
            minion_speed = 13;
            minion_mana = 1;
        }
        else if(minion_number == 2)
        {
            minion.load(":/picture/minion2.png");
            minion_HP = 4000;
            minion_attack = 3;
            minion_atk_range = 30;
            minion_speed = 13;
            minion_mana = 2;
        }
        else if(minion_number == 3)
        {
            minion.load(":/picture/minion3.png");
            minion_HP = 25000;
            minion_attack = 1;
            minion_atk_range = 20;
            minion_speed = 20;
            minion_mana = 2;
        }
        else if(minion_number == 4)
        {
            minion.load(":/picture/minion4.png");
            minion_HP = 4500;
            minion_attack = 8;
            minion_atk_range = 30;
            minion_speed = 11;
            minion_mana = 3;
        }
        else if(minion_number == 5)
        {
            minion.load(":/picture/minion5.png");
            minion_HP = 1000;
            minion_attack = 4;
            minion_atk_range = 200;
            minion_speed = 6;
            minion_mana = 3;
        }
        else if(minion_number == 6)
        {
            minion.load(":/picture/minion6.png");
            minion_HP = 4500;
            minion_attack = 8;
            minion_atk_range = 50;
            minion_speed = 11;
            minion_mana = 3;
        }
        else if(minion_number == 7)
        {
            minion.load(":/picture/minion7.png");
            minion_HP = 7000;
            minion_attack = 10;
            minion_atk_range = 10;
            minion_speed = 5;
            minion_mana = 4;
        }
        else if(minion_number == 8)
        {
            minion.load(":/picture/minion8.png");
            minion_HP = 8500;
            minion_attack = 9;
            minion_atk_range = 35;
            minion_speed = 8;
            minion_mana = 5;
        }
        else if(minion_number == 9)
        {
            minion.load(":/picture/minion9.png");
            minion_HP = 6000;
            minion_attack = 6;
            minion_atk_range = 35;
            minion_speed = 4;
            minion_mana = 5;
        }
        else if(minion_number == 10)
        {
            minion.load(":/picture/minion10.png");
            minion_HP = 8500;
            minion_attack = 20;
            minion_atk_range = 80;
            minion_speed = 15;
            minion_mana = 5;
        }
        else if(minion_number == 11)
        {
            minion.load(":/picture/minion11.png");
            minion_HP = 5500;
            minion_attack = 7;
            minion_atk_range = 55;
            minion_speed = 8;
            minion_mana = 5;
        }
        else if(minion_number == 12)
        {
            minion.load(":/picture/minion12.png");
            minion_HP = 7000;
            minion_attack = 9;
            minion_atk_range = 10;
            minion_speed = 1;
            minion_mana = 7;
        }
        else if(minion_number == 13)
        {
            minion.load(":/picture/minion13.png");
            minion_HP = 6500;
            minion_attack = 5;
            minion_atk_range = 6;
            minion_speed = 14;
            minion_mana = 7;
        }
        else if(minion_number == 14)
        {
            minion.load(":/picture/minion14.png");
            minion_HP = 8000;
            minion_attack = 13;
            minion_atk_range = 220;
            minion_speed = 11;
            minion_mana = 7;
        }
        else if(minion_number == 15)
        {
            minion.load(":/picture/minion15.png");
            minion_HP = 9000;
            minion_attack = 15;
            minion_atk_range = 250;
            minion_speed = 30;
            minion_mana = 7;
        }
        else if(minion_number == 16)
        {
            minion.load(":/picture/minion16.png");
            minion_HP = 9000;
            minion_attack = 9;
            minion_atk_range = 25;
            minion_speed = 10;
            minion_mana = 9;
        }
        else if(minion_number == 17)
        {
            minion.load(":/picture/minion17.png");
            minion_HP = 9500;
            minion_attack = 10;
            minion_atk_range = 20;
            minion_speed = 15;
            minion_mana = 9;
        }
        else if(minion_number == 18)
        {
            minion.load(":/picture/minion18.png");
            minion_HP = 10000;
            minion_attack = 4;
            minion_atk_range = 50;
            minion_speed = 3;
            minion_mana = 9;
        }
        else if(minion_number == 19)
        {
            minion.load(":/picture/minion19.png");
            minion_HP = 15000;
            minion_attack = 10;
            minion_atk_range = 7;
            minion_speed = 5;
            minion_mana = 9;
        }
        else if(minion_number == 20)
        {
            minion.load(":/picture/minion20.png");
            minion_HP = 5000;
            minion_attack = -2;
            minion_atk_range = 30;
            minion_speed = 15;
            minion_mana = 10;
        }
        if(minion_who == 1) //player
        {
            if(hero == 1)   //player hero
            {
                soldier=soldier.fromImage(minion);
                soldier=soldier.scaled(120,154);
                minion_attack_x = 60;
                minion_attack_y = 115;
                minion_speed = 31-minion_speed;
            }
            else if( hero ==0 ) //ordinary soldier
            {
                soldier=soldier.fromImage(minion);
                soldier=soldier.scaled(80,103);
                minion_attack_x = 40;
                minion_attack_y = 77;
            }
        }
        else if(minion_who == 2)    //enemy
        {
            if(hero == 2)   //enemy hero
            {
                minion=minion.mirrored(true,false);
                soldier=soldier.fromImage(minion);
                soldier=soldier.scaled(120,154);
                minion_attack_x = 60;
                minion_attack_y = 115;
            }
            else if( hero ==0 ) //ordinary soldier
            {
                minion=minion.mirrored(true,false);
                soldier=soldier.fromImage(minion);
                soldier=soldier.scaled(80,103);
                minion_attack_x = 40;
                minion_attack_y = 77;
            }
        }
        setPixmap(soldier);
        if(hero!=1)
        {
            timer_minion_move = new QTimer();
            connect(timer_minion_move,SIGNAL(timeout()),this,SLOT(minion_move()));
            //start the timer
            timer_minion_move->start(minion_speed);
        }
        //set minion_HP
        if(hero == 0)
        {
            minion_HP_text = new Text(2,this,minion_HP);
            minion_HP_text->setPos(10,0);
        }
        else if (hero == 1 || hero == 2)
        {
            minion_HP_text = new Text(2,this,minion_HP);
            minion_HP_text->setPos(28,5);
        }

    }
}

void Minion_battle::minion_move()
{
    //search enemy
    if(minion_who_am_I == 1)
    {
        int stop_flag=0;
        if(minion_num == 20)
        {
            foreach(Minion_battle* minion,scenemanager->page_battle_scene->list_player)
            {
                if(minion != this)
                {
                    if( (this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)*(this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)+(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y)*(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y) <= minion_atk_range*minion_atk_range )
                    {
                        stop_flag=1;
                        minion->minion_decrease_HP(minion_attack);
                    }
                }
            }
        }
        else
        {
            foreach(Minion_battle* minion,scenemanager->page_battle_scene->list_enemy)
            {
                if( (this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)*(this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)+(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y)*(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y) <= minion_atk_range*minion_atk_range )
                {
                    stop_flag=1;
                    minion->minion_decrease_HP(minion_attack);
                }
            }
            //attack tower
            if( (this->x()+minion_attack_x-scenemanager->page_battle_scene->tower_enemy->minion_attack_x)*(this->x()+minion_attack_x-scenemanager->page_battle_scene->tower_enemy->minion_attack_x)+(this->y()+minion_attack_y-scenemanager->page_battle_scene->tower_enemy->minion_attack_y)*(this->y()+minion_attack_y-scenemanager->page_battle_scene->tower_enemy->minion_attack_y) <= minion_atk_range*minion_atk_range )
            {
                //cout<<"attack tower\n";
                stop_flag=1;
                scenemanager->page_battle_scene->tower_enemy->minion_decrease_HP(minion_attack);
            }
        }
        if(stop_flag == 0)
        {
            //move the minion
            if(pos().x()<1280)
            {
                if(move_type == 1)    //move up
                {
                    if(this->x()+79<=330)
                    {
                        setPos(x()+1,y()-1);
                    }
                    else if(this->x()+79<=1041)
                    {
                        setPos(x()+1,y());
                    }
                    else if(this->x()+79<=1177)
                    {
                        setPos(x()+1,y()+1);
                    }
                    else if(this->x()+79<=1200)
                    {
                        setPos(x()+1,y());
                    }
                }
                else if(move_type == 2)   //move down
                {
                    if(this->x()+79<=317)
                    {
                        setPos(x()+1,y()+1);
                    }
                    else if(this->x()+79<=1055)
                    {
                        setPos(x()+1,y());
                    }
                    else if(this->x()+79<=1177)
                    {
                        setPos(x()+1,y()-1);
                    }
                    else if(this->x()+79<=1200)
                    {
                        setPos(x()+1,y());
                    }
                }
            }
        }
    }
    else if(minion_who_am_I == 2)
    {
        int stop_flag=0;
        if(minion_num == 20)
        {
            foreach(Minion_battle* minion,scenemanager->page_battle_scene->list_enemy)
            {
                if(minion != this)
                {
                    if( (this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)*(this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)+(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y)*(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y) <= minion_atk_range*minion_atk_range )
                    {
                        stop_flag=1;
                        minion->minion_decrease_HP(minion_attack);
                    }
                }
            }
        }
        else
        {
            foreach(Minion_battle* minion,scenemanager->page_battle_scene->list_player)
            {
                if( (this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)*(this->x()+minion_attack_x-minion->x()-minion->minion_attack_x)+(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y)*(this->y()+minion_attack_y-minion->y()-minion->minion_attack_y) <= minion_atk_range*minion_atk_range )
                {
                    stop_flag=1;
                    minion->minion_decrease_HP(minion_attack);
                }
            }
            //attack tower
            if( (this->x()+minion_attack_x-scenemanager->page_battle_scene->tower_player->minion_attack_x)*(this->x()+minion_attack_x-scenemanager->page_battle_scene->tower_player->minion_attack_x)+(this->y()+minion_attack_y-scenemanager->page_battle_scene->tower_player->minion_attack_y)*(this->y()+minion_attack_y-scenemanager->page_battle_scene->tower_player->minion_attack_y) <= minion_atk_range*minion_atk_range )
            {
                stop_flag=1;
                scenemanager->page_battle_scene->tower_player->minion_decrease_HP(minion_attack);
            }
        }
        if(stop_flag == 0)
        {
            //move the minion
            if(pos().x()>0)
            {
                if(move_type == 1)    //move up
                {
                    if(this->x()+79>=1043)
                    {
                        setPos(x()-1,y()-1);
                    }
                    else if(this->x()+79>=332)
                    {
                        setPos(x()-1,y());
                    }
                    else if(this->x()+79>=195)
                    {
                        setPos(x()-1,y()+1);
                    }
                    else if(this->x()+79>=172)
                    {
                        setPos(x()-1,y());
                    }
                }
                else if(move_type == 2)   //move down
                {
                    if(this->x()+79>=1057)
                    {
                        setPos(x()-1,y()+1);
                    }
                    else if(this->x()+79>=319)
                    {
                        setPos(x()-1,y());
                    }
                    else if(this->x()+79>=195)
                    {
                        setPos(x()-1,y()-1);
                    }
                    else if(this->x()+79>=172)
                    {
                        setPos(x()-1,y());
                    }
                }
            }
        }
    }

}
void Minion_battle::minion_decrease_HP(int decrease_number)
{
    minion_HP=minion_HP-decrease_number;
    minion_HP_text->setPlainText(QString::number(minion_HP));
    if(minion_HP<=0)
    {
        if(who == 3)
        {
            if(minion_who_am_I == 1)
            {
                scenemanager->page_battle_scene->list_player.removeOne(this);
                scenemanager->page_battle_scene->removeItem(this);
                if(who_hero == 1)   //lose
                {
                    //delete this;
                }
                else if(who_hero ==0)
                {
                    delete this;
                    return;
                }
            }
            else if(minion_who_am_I == 2)
            {
                scenemanager->page_battle_scene->list_enemy.removeOne(this);
                scenemanager->page_battle_scene->removeItem(this);
                delete this;
                return;
            }
        }
        else if(who == 1)   //tower
        {
            delete this;
            if(minion_who_am_I == 1)    //lose
            {
                scenemanager->page_battle_scene->clear();
                scenemanager->page_battle_scene->music_battle_scene->stop();
                delete scenemanager->page_battle_scene;
                scenemanager->battle_result = 2;
                scenemanager->changescene(7);
            }
            else if(minion_who_am_I == 2)   //win
            {
                scenemanager->page_battle_scene->clear();
                scenemanager->page_battle_scene->music_battle_scene->stop();
                delete scenemanager->page_battle_scene;
                scenemanager->battle_result = 1;
                if(scenemanager->battle_now == scenemanager->battle_state)
                    scenemanager->battle_state = scenemanager->battle_state +1;
                scenemanager->changescene(7);
            }
        }
    }
}

void Minion_battle::increase_mana()
{
    scenemanager->page_battle_scene->mana->mana_increase();
}
int Minion_battle::get_minion_HP()
{
    return minion_HP;
}
int Minion_battle::get_minion_attack_x()
{
    return minion_attack_x;
}
int Minion_battle::get_minion_attack_y()
{
    return minion_attack_y;
}
int Minion_battle::get_minion_mana()
{
    return minion_mana;
}
void Minion_battle::spawn()
{
        //create an random enemy
        spawn_enemy_type = rand()%enemy_total + 1;
        Minion_battle* enemy = new Minion_battle(3,2,spawn_enemy_type,0);
        enemy_move_type = rand()%2 + 1;
        if(enemy_move_type == 1)
            enemy->setPos(1099,279);
        else if(enemy_move_type == 2)
            enemy->setPos(1099,292);
        scenemanager->page_battle_scene->addItem(enemy);
        scenemanager->page_battle_scene->list_enemy.push_back(enemy);
        enemy->move_type = enemy_move_type;
}
