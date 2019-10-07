#include "page_battle_scene.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>

//#include<iostream>
//using namespace std;

extern Scenemanager* scenemanager;

Page_battle_scene::Page_battle_scene(int hard, int prize)
{
    choose_flag=0;

    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_battle_base.png")));

    //add background music
    music_battle_scene = new QMediaPlayer();
    music_battle_scene->setMedia(QUrl("qrc:/music/battle_1.mp3"));
    music_battle_scene->play();

    //set towers
    tower_player = new Minion_battle(1,1);
    tower_enemy = new Minion_battle(1,2);
    addItem(tower_player);
    addItem(tower_enemy);

    //set hero
    player_hero = new Minion_battle(3,1,scenemanager->deck_player_battle[1],1);
    player_hero->setPos(100,260);
    addItem(player_hero);
    list_player.push_back(player_hero);
    //set deck_player_battle
    player_deck_1 = new Minion_battle(2,0,scenemanager->deck_player_battle[2]);
    player_deck_2 = new Minion_battle(2,0,scenemanager->deck_player_battle[3]);
    player_deck_3 = new Minion_battle(2,0,scenemanager->deck_player_battle[4]);
    player_deck_4 = new Minion_battle(2,0,scenemanager->deck_player_battle[5]);
    player_deck_1->setPos(0,590);
    player_deck_2->setPos(100,590);
    player_deck_3->setPos(200,590);
    player_deck_4->setPos(300,590);
    addItem(player_deck_1);
    addItem(player_deck_2);
    addItem(player_deck_3);
    addItem(player_deck_4);

    //set mana
    mana = new Text(1);
    addItem(mana);
    timer_mana = new QTimer();
    timer_mana->start(1000);
    connect(timer_mana,SIGNAL(timeout()),tower_player,SLOT(increase_mana()));

    //spawn enemy
    if(hard == 1)
    {
        tower_enemy->enemy_total = 5;
        timer_spawn_enemy = new QTimer();
        connect(timer_spawn_enemy,SIGNAL(timeout()),tower_enemy,SLOT(spawn()));
        timer_spawn_enemy->start(6500);
    }
    else if(hard == 2)
    {
        tower_enemy->enemy_total = 7;
        timer_spawn_enemy = new QTimer();
        connect(timer_spawn_enemy,SIGNAL(timeout()),tower_enemy,SLOT(spawn()));
        timer_spawn_enemy->start(4000);
    }
    else if(hard == 3)
    {
        tower_enemy->enemy_total = 11;
        timer_spawn_enemy = new QTimer();
        connect(timer_spawn_enemy,SIGNAL(timeout()),tower_enemy,SLOT(spawn()));
        timer_spawn_enemy->start(3000);
    }
    else if(hard == 4)
    {
        tower_enemy->enemy_total = 15;
        timer_spawn_enemy = new QTimer();
        connect(timer_spawn_enemy,SIGNAL(timeout()),tower_enemy,SLOT(spawn()));
        timer_spawn_enemy->start(1500);
    }
    else if(hard == 5)
    {
        tower_enemy->enemy_total = 19;
        timer_spawn_enemy = new QTimer();
        connect(timer_spawn_enemy,SIGNAL(timeout()),tower_enemy,SLOT(spawn()));
        timer_spawn_enemy->start(1000);
    }

}
void Page_battle_scene::keyPressEvent(QKeyEvent *event)
{
    //hero movement
    if(event->key() == Qt::Key_Up)
    {
        if( player_hero->y()>=20 && player_hero->y()+ 153 <=720 )
        {
                player_hero->setPos(player_hero->x(),player_hero->y()-player_hero->minion_speed);
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if( player_hero->y()>=0 && player_hero->y()+ 153 <=650 )
        {
            player_hero->setPos(player_hero->x(),player_hero->y()+player_hero->minion_speed);
        }
    }
    else if(event->key() == Qt::Key_Left)
    {
        if( player_hero->x()>1 && player_hero->x()+ 119 <=1280 )
        {
            player_hero->setPos(player_hero->x()-player_hero->minion_speed,player_hero->y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if( player_hero->x()>=0 && player_hero->x()+ 119 <1279 )
        {
            player_hero->setPos(player_hero->x()+player_hero->minion_speed,player_hero->y());
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        foreach(Minion_battle* minion,list_enemy)
        {
            if( (player_hero->x()+player_hero->minion_attack_x-minion->x()-minion->minion_attack_x)*(player_hero->x()+player_hero->minion_attack_x-minion->x()-minion->minion_attack_x)+(player_hero->y()+player_hero->minion_attack_y-minion->y()-minion->minion_attack_y)*(player_hero->y()+player_hero->minion_attack_y-minion->y()-minion->minion_attack_y) <= player_hero->minion_atk_range*player_hero->minion_atk_range )
            {
                minion->minion_decrease_HP(player_hero->minion_attack);
            }
        }
        //attack tower
        if( abs(player_hero->x()+player_hero->minion_attack_x-scenemanager->page_battle_scene->tower_enemy->minion_attack_x) <= player_hero->minion_atk_range )
        {
            tower_enemy->minion_decrease_HP(player_hero->minion_attack);
        }
    }

    //other minion movement
    else if(event->key() == Qt::Key_Z)
    {
        if(mana->get_mana()>=player_deck_1->minion_mana)
            choose_flag=1;
    }
    else if(event->key() == Qt::Key_X)
    {
        if(mana->get_mana()>=player_deck_2->minion_mana)
            choose_flag =2;
    }
    else if(event->key() == Qt::Key_C)
    {
        if(mana->get_mana()>=player_deck_3->minion_mana)
            choose_flag =3;
    }
    else if(event->key() == Qt::Key_V)
    {
        if(mana->get_mana()>=player_deck_4->minion_mana)
            choose_flag =4;
    }
    //choose place (up or down)
    else if(choose_flag == 1)
    {
        Minion_battle* minion;
        minion = new Minion_battle(3,1,scenemanager->deck_player_battle[2],0);
        if(event->key() == Qt::Key_A)
        {
            minion->setPos(115,280);
            minion->move_type=1;
        }
        else if(event->key() == Qt::Key_S)
        {
            minion->setPos(115,290);
            minion->move_type=2;
        }
        addItem(minion);
        //minus mana
        mana -> mana_decrease(player_deck_1->minion_mana);
        choose_flag = 0;
        list_player.push_back(minion);

    }
    else if(choose_flag == 2)
    {
        Minion_battle* minion;
        minion = new Minion_battle(3,1,scenemanager->deck_player_battle[3],0);
        if(event->key() == Qt::Key_A)
        {
            minion->setPos(115,280);
            minion->move_type=1;
        }
        else if(event->key() == Qt::Key_S)
        {
            minion->setPos(115,290);
            minion->move_type=2;
        }
        addItem(minion);
        //minus mana
        mana -> mana_decrease(player_deck_2->minion_mana);
        choose_flag = 0;
        list_player.push_back(minion);
    }
    else if(choose_flag == 3)
    {
        Minion_battle* minion;
        minion = new Minion_battle(3,1,scenemanager->deck_player_battle[4],0);
        if(event->key() == Qt::Key_A)
        {
            minion->setPos(115,280);
            minion->move_type=1;
        }
        else if(event->key() == Qt::Key_S)
        {
            minion->setPos(115,290);
            minion->move_type=2;
        }
        addItem(minion);
        //minus mana
        mana -> mana_decrease(player_deck_3->minion_mana);
        choose_flag = 0;
        list_player.push_back(minion);
    }
    else if(choose_flag == 4)
    {
        Minion_battle* minion;
        minion = new Minion_battle(3,1,scenemanager->deck_player_battle[5],0);
        if(event->key() == Qt::Key_A)
        {
            minion->setPos(115,280);
            minion->move_type=1;
        }
        else if(event->key() == Qt::Key_S)
        {
            minion->setPos(115,290);
            minion->move_type=2;
        }
        addItem(minion);
        //minus mana
        mana -> mana_decrease(player_deck_4->minion_mana);
        choose_flag = 0;
        list_player.push_back(minion);
    }
}
