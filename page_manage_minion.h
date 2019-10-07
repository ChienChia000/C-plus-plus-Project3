#ifndef PAGE_MANAGE_MINION_H
#define PAGE_MANAGE_MINION_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>
#include<QTimer>

#include"money.h"
#include"flash_button.h"
#include"minion.h"

class Page_manage_minion : public QGraphicsScene
{
public:
    Page_manage_minion();

    void keyPressEvent(QKeyEvent * event);

    QMediaPlayer* music_manage_minion;

    Flash_button* flash_button;
    Flash_button* flash_hero_mark;

    Minion* minion_deck_left;

    Minion* minion_hero;
    Minion* minion_1;
    Minion* minion_2;
    Minion* minion_3;
    Minion* minion_4;

    Money* money;

private:
    int choose_num;
    int choose_hero_num;
    int flag;
};

#endif // PAGE_MANAGE_MINION_H
