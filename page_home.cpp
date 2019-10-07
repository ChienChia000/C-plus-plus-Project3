#include "page_home.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>
#include<QTimer>

extern Scenemanager* scenemanager;

Page_home::Page_home(QWidget* parent)
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_home.png")));

    choose_number = 1;
    button_home_choose = new Button_home_choose();
    addItem(button_home_choose);

    //add background music
    music_home = new QMediaPlayer();
    music_home->setMedia(QUrl("qrc:/music/home.mp3"));
    music_home->play();

    money = new Money();
    addItem(money);
}
void Page_home::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        if(choose_number<=5 && choose_number>1)
        {
            choose_number = choose_number - 1;
            scenemanager->page_home->button_home_choose->setPos(0,scenemanager->page_home->button_home_choose->y()-120);
        }
    }
    if(event->key() == Qt::Key_Down)
    {
        if(choose_number<5 && choose_number>=1)
        {
            choose_number = choose_number + 1;
            scenemanager->page_home->button_home_choose->setPos(0,scenemanager->page_home->button_home_choose->y()+120);
        }
    }
    if(event->key() == Qt::Key_Space)
    {
        music_home->stop();
        clear();

        //scenemanager->changescene();
        if(choose_number == 1)
        {
            delete this;
            scenemanager->changescene(2);

        }
        else if(choose_number == 2)
        {
            delete this;
            scenemanager->changescene(4);
        }
        else if(choose_number == 3)
        {
            delete this;
            scenemanager->changescene(5);
        }
        else if(choose_number == 4)
        {
            delete this;
            scenemanager->changescene(6);
        }
        else if(choose_number == 5)
        {
            delete this;
            scenemanager->changescene(8);
        }
    }
}
