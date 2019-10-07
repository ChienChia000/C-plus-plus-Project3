#include "page_welcome.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>
#include<QTimer>

extern Scenemanager* scenemanager;

Page_welcome::Page_welcome(QWidget* parent)
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_welcome.png")));

    button_welcome = new Button_welcome();
    addItem(button_welcome);

    //add background music
    music_welcome = new QMediaPlayer();
    music_welcome->setMedia(QUrl("qrc:/music/welcome.mp3"));
    music_welcome->play();
}

void Page_welcome::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        music_welcome->stop();
        clear();
        scenemanager->changescene(1);
    }
}
