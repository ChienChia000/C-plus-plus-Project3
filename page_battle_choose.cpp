#include "page_battle_choose.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QTimer>

extern Scenemanager* scenemanager;

Page_battle_choose::Page_battle_choose()
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_battle_choose.png")));

    battle_choose_number = 1;
    button_battle_choose = new Button_battle_choose();
    addItem(button_battle_choose);

    //add background music
    music_battle_choose = new QMediaPlayer();
    music_battle_choose->setMedia(QUrl("qrc:/music/home.mp3"));
    music_battle_choose->play();

}
void Page_battle_choose::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(battle_choose_number<=5 && battle_choose_number>1)
        {
            battle_choose_number = battle_choose_number - 1;
            scenemanager->page_battle_choose->button_battle_choose->setPos(scenemanager->page_battle_choose->button_battle_choose->x()-252,147);
            scenemanager->page_battle_choose->button_battle_choose->setPixmap(QPixmap(":/picture/button_choose_stage.png"));
        }
    }
    if(event->key() == Qt::Key_Right)
    {
        if(battle_choose_number<scenemanager->battle_state && battle_choose_number>=1)
        {
            battle_choose_number = battle_choose_number + 1;
            scenemanager->page_battle_choose->button_battle_choose->setPos(scenemanager->page_battle_choose->button_battle_choose->x()+252,147);
            scenemanager->page_battle_choose->button_battle_choose->setPixmap(QPixmap(":/picture/button_choose_stage.png"));
        }
    }
    if(event->key() == Qt::Key_Space)
    {
        music_battle_choose->stop();
        clear();

        //scenemanager->changescene();
        if(battle_choose_number == 1)
        {
            scenemanager->battle_hard = 1;
            scenemanager->battle_prize = 2000;
            scenemanager->battle_now = 1;
            delete this;
            scenemanager->changescene(3);

        }
        else if(battle_choose_number == 2)
        {
            scenemanager->battle_hard = 2;
            scenemanager->battle_prize = 5000;
            scenemanager->battle_now = 2;
            delete this;
            scenemanager->changescene(3);
        }
        else if(battle_choose_number == 3)
        {
            scenemanager->battle_hard = 3;
            scenemanager->battle_prize = 10000;
            scenemanager->battle_now = 3;
            delete this;
            scenemanager->changescene(3);
        }
        else if(battle_choose_number == 4)
        {
            scenemanager->battle_hard = 4;
            scenemanager->battle_prize = 20000;
            scenemanager->battle_now = 4;
            delete this;
            scenemanager->changescene(3);
        }
        else if(battle_choose_number == 5)
        {
            scenemanager->battle_hard = 10;
            scenemanager->battle_prize = 100000;
            scenemanager->battle_now = 5;
            delete this;
            scenemanager->changescene(3);
        }
    }
    if(event->key() == Qt::Key_Escape)
    {
        music_battle_choose->stop();
        clear();
        delete this;
        scenemanager->changescene(1);
    }
}
