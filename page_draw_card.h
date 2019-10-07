#ifndef PAGE_DRAW_CARD_H
#define PAGE_DRAW_CARD_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QTimer>
#include<QMediaPlayer>

#include"money.h"
#include"flash_button.h"
#include"minion.h"

class Page_draw_card : public QGraphicsScene
{
public:
    Page_draw_card(QWidget* parent=0);

    void keyPressEvent(QKeyEvent * event);
    //Button_home_choose* button_home_choose;
    QMediaPlayer* music_draw_card;

    QTimer* timer_flash_money;

    Money* money;
    Flash_button* flash_money_mark;

    Minion* minion_back;
    Minion* minion_draw;

    QMediaPlayer* music_coin;
private:
    int flag;
};

#endif // PAGE_DRAW_CARD_H
