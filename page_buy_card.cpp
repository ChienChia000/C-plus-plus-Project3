#include "page_buy_card.h"

#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>

extern Scenemanager* scenemanager;

Page_buy_card::Page_buy_card(QWidget *parent)
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_buy_card.png")));

    choose_num=1;

    //add music
//    music_buy = new QMediaPlayer();
//    music_buy->setMedia(QUrl("qrc:/music/"));
//    music_buy->play();

    money = new Money();
    addItem(money);

    flash_money_mark = new Flash_button(2);
    addItem(flash_money_mark);
    timer_flash_money = new QTimer();
    connect(timer_flash_money,SIGNAL(timeout()),flash_money_mark,SLOT(change()));
    timer_flash_money->start(100);

    minion = new Minion(1,choose_num);
    addItem(minion);
    price_minion = new Price_minion(1);
    addItem(price_minion);

    music_coin = new QMediaPlayer();
    music_coin->setMedia(QUrl("qrc:/music/coin.mp3"));
}
void Page_buy_card::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        //minus money (-price_minion $)
        if(scenemanager->money >= minion->get_minion_money())
        {
            music_coin->play();
            money->money_increase(-(minion->get_minion_money()));
            money->setPlainText(QString::number(scenemanager->money));

            //add the card to the deck_player_all and deck_player_left
            scenemanager->player_card_total_num = scenemanager->player_card_total_num +1;
            scenemanager->deck_player_all[scenemanager->player_card_total_num] = choose_num;
            scenemanager->player_deck_left_flag = scenemanager->player_deck_left_flag +1;
            scenemanager->deck_player_left[scenemanager->player_deck_left_flag] = choose_num;

            //sort the deck_player_all
            int temp=0;
            for(int i=1;i<=scenemanager->player_card_total_num;++i)
            {
                for(int j=i+1;j<=scenemanager->player_card_total_num;j++)
                {
                    if(scenemanager->deck_player_all[i] >= scenemanager->deck_player_all[j])
                    {
                        temp = scenemanager->deck_player_all[i];
                        scenemanager->deck_player_all[i]=scenemanager->deck_player_all[j];
                        scenemanager->deck_player_all[j]=temp;
                    }
                }
            }//end for
            //sort the deck_player_left
            temp=0;
            for(int i=1;i<=scenemanager->player_deck_left_flag;++i)
            {
                for(int j=i+1;j<=scenemanager->player_deck_left_flag;j++)
                {
                    if(scenemanager->deck_player_left[i] >= scenemanager->deck_player_left[j])
                    {
                        temp = scenemanager->deck_player_left[i];
                        scenemanager->deck_player_left[i]=scenemanager->deck_player_left[j];
                        scenemanager->deck_player_left[j]=temp;
                    }
                }
            }//end for
        }
    }
    else if(event->key() == Qt::Key_Escape)
    {
        clear();
        delete this;
        scenemanager->changescene(1);
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(choose_num>1 && choose_num<=20)
        {
            choose_num=choose_num-1;
            delete minion;
            delete price_minion;

            flash_button = new Flash_button(0);
            addItem(flash_button);

            minion = new Minion(1,choose_num);
            addItem(minion);
            price_minion = new Price_minion();
            addItem(price_minion);
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(choose_num>=1 && choose_num<20)
        {
            choose_num=choose_num+1;
            delete minion;
            delete price_minion;

            flash_button = new Flash_button(1);
            addItem(flash_button);

            minion = new Minion(1,choose_num);
            addItem(minion);
            price_minion = new Price_minion();
            addItem(price_minion);
        }
    }
}
