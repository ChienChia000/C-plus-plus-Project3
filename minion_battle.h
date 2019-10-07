#ifndef MINION_BATTLE_H
#define MINION_BATTLE_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QImage>
#include<QTimer>
#include<QWidget>
#include<math.h>

#include"text.h"

class Minion_battle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Minion_battle(int minion_type=0, int minion_who=0, int minion_number=0, int hero=0);

    QImage minion;

    QPixmap soldier;
    QPixmap tower;
    QPixmap minion_card;

    QTimer* timer_minion_move;

    Text* minion_HP_text;

    int minion_beging_pos;
    int minion_end_pos;
    int minion_type;
    int class_type;

    int minion_attack_x;
    int minion_attack_y;

    int minion_attack;
    int minion_HP;
    int minion_atk_range;
    int minion_speed;
    int minion_mana;
    int move_type;

    int who;
    int minion_who_am_I;
    int who_hero;
    int minion_num;

    int spawn_enemy_type;
    int enemy_move_type;
    int enemy_total;

public slots:
    void minion_move();
    void minion_decrease_HP(int decrease_number=0);
    int get_minion_HP();
    int get_minion_attack_x();
    int get_minion_attack_y();
    int get_minion_mana();
    void increase_mana();

    void spawn();
};

#endif // MINION_BATTLE_H
