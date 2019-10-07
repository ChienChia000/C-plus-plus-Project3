#include "page_draw_card.h"

#include"scenemanager.h"

#include<stdlib.h>  //rand
#include<QBrush>
#include<QImage>
#include<QImage>

extern Scenemanager* scenemanager;

Page_draw_card::Page_draw_card(QWidget *parent)
{
    flag=0;
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/page_draw_card.png")));

    //add music
//    music_home = new QMediaPlayer();
//    music_home->setMedia(QUrl("qrc:/music/"));
//    music_home->play();

    money = new Money();
    addItem(money);

    flash_money_mark = new Flash_button(3);
    addItem(flash_money_mark);
    timer_flash_money = new QTimer();
    connect(timer_flash_money,SIGNAL(timeout()),flash_money_mark,SLOT(change()));
    timer_flash_money->start(100);

    minion_back = new Minion(2);
    addItem(minion_back);

    music_coin = new QMediaPlayer();
    music_coin->setMedia(QUrl("qrc:/music/coin.mp3"));
}
void Page_draw_card::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(flag==0)
        {
            if(scenemanager->money >= minion_back->get_minion_money())
            {
                music_coin->play();
                //minus money (-200$)
                money->money_increase(-200);
                money->setPlainText(QString::number(scenemanager->money));

                //show the card
                delete minion_back;
                int draw;
                srand(time(NULL));
                draw = rand()%20 + 1;
                minion_draw = new Minion(1,draw);
                addItem(minion_draw);
                flag = 1;

                //add the card in deck_player_all and deck_player_left
                scenemanager->player_card_total_num = scenemanager->player_card_total_num +1;
                scenemanager->deck_player_all[scenemanager->player_card_total_num] = draw;
                scenemanager->player_deck_left_flag = scenemanager->player_deck_left_flag +1;
                scenemanager->deck_player_left[scenemanager->player_deck_left_flag] = draw;

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
        else if(flag==1)
        {
            delete minion_draw;
            minion_back = new Minion(2);
            addItem(minion_back);
            flag = 0;
        }

    }
    else if(event->key() == Qt::Key_Escape)
    {
        clear();

        //scenemanager->changescene();
        delete this;
        scenemanager->changescene(1);
    }
}
