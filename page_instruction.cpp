#include "page_instruction.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>
#include<QTimer>

extern Scenemanager* scenemanager;

Page_instruction::Page_instruction()
{
    flag = 0;
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_instruction_1.png")));

    //add background music
    music_instruction = new QMediaPlayer();
    music_instruction->setMedia(QUrl("qrc:/music/home.mp3"));
    music_instruction->play();

}
void Page_instruction::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        music_instruction->stop();
        clear();
        scenemanager->changescene(1);
    }
    if(event->key() == Qt::Key_Right)
    {
        setBackgroundBrush(QBrush(QImage(":/picture/page_instruction_2.png")));
    }
    if(event->key() == Qt::Key_Left)
    {
        setBackgroundBrush(QBrush(QImage(":/picture/page_instruction_1.png")));
    }
}
