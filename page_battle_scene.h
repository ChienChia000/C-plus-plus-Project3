#ifndef PAGE_BATTLE_SCENE_H
#define PAGE_BATTLE_SCENE_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>
#include<QVector>
#include<QTimer>

#include"minion_battle.h"
#include"text.h"

class Page_battle_scene : public QGraphicsScene
{
public:
    Page_battle_scene(int hard=0, int prize=0);

    void keyPressEvent(QKeyEvent * event);
    QMediaPlayer* music_battle_scene;

    Minion_battle* tower_player;
    Minion_battle* tower_enemy;

    Minion_battle* player_hero;
    Minion_battle* player_deck_1;
    Minion_battle* player_deck_2;
    Minion_battle* player_deck_3;
    Minion_battle* player_deck_4;

    Text* mana;

    QTimer* timer_mana;
    QTimer* timer_spawn_enemy;

    QVector<Minion_battle*> list_player;
    QVector<Minion_battle*> list_enemy;

    int choose_flag;


};

#endif // PAGE_BATTLE_SCENE_H
