#include "page_result.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>
#include<QTimer>

extern Scenemanager* scenemanager;

Page_result::Page_result()
{
    if(scenemanager->battle_result == 1)
    {
        setSceneRect(0,0,1280,720);
        setBackgroundBrush(QBrush(QImage(":/picture/page_result_win.png")));
        scenemanager->money = scenemanager->money + scenemanager->battle_prize;
        money_prize = new Text(4,0,scenemanager->battle_prize);
        addItem(money_prize);
        money_prize->setPos(160,160);
    }
    else if(scenemanager->battle_result == 2)
    {
        setSceneRect(0,0,1280,720);
        setBackgroundBrush(QBrush(QImage(":/picture/page_result_lose.png")));
    }
    //add background music
    music_result = new QMediaPlayer();
    music_result->setMedia(QUrl("qrc:/music/result.mp3"));
    music_result->play();

}
void Page_result::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        music_result->stop();
        clear();
        scenemanager->changescene(1);
    }
}
