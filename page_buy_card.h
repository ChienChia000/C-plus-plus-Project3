#ifndef PAGE_BUY_CARD_H
#define PAGE_BUY_CARD_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>
#include<QTimer>

#include"money.h"
#include"price_minion.h"
#include"flash_button.h"
#include"minion.h"

class Page_buy_card : public QGraphicsScene
{
public:
    Page_buy_card(QWidget* parent=0);

    void keyPressEvent(QKeyEvent * event);
    //Button_home_choose* button_home_choose;
    QMediaPlayer* music_buy_card;

    Flash_button* flash_button;
    Flash_button* flash_money_mark;

    QTimer* timer_flash_money;

    Minion* minion;

    Money* money;
    Price_minion* price_minion;

    QMediaPlayer* music_coin;
private:
    int choose_num;
};

#endif // PAGE_BUY_CARD_H
