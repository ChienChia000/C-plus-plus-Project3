#ifndef PAGE_WELCOME_H
#define PAGE_WELCOME_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

#include"button_welcome.h"

class Page_welcome : public QGraphicsScene
{
public:
    Page_welcome(QWidget* parent=0);

    void keyPressEvent(QKeyEvent * event);
    Button_welcome* button_welcome;
    QMediaPlayer* music_welcome;
};

#endif // PAGE_WELCOME_H
