#ifndef PAGE_BATTLE_CHOOSE_H
#define PAGE_BATTLE_CHOOSE_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

#include"button_battle_choose.h"


class Page_battle_choose : public QGraphicsScene
{
public:
    Page_battle_choose();

    void keyPressEvent(QKeyEvent * event);
    Button_battle_choose* button_battle_choose;
    QMediaPlayer* music_battle_choose;

private:
    int battle_choose_number;
};

#endif // PAGE_BATTLE_CHOOSE_H
