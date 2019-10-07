#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include<QGraphicsView>
#include<QKeyEvent>

#include"page_welcome.h"
#include"page_home.h"
#include"page_battle_choose.h"
#include"page_draw_card.h"
#include"page_buy_card.h"
#include"page_manage_minion.h"
#include"page_battle_scene.h"
#include"page_result.h"
#include"page_instruction.h"

class Scenemanager : public QGraphicsView
{
public:
    Scenemanager();

    Page_welcome* page_welcome;
    Page_home* page_home;
    Page_battle_choose* page_battle_choose;
    Page_draw_card* page_draw_card;
    Page_buy_card* page_buy_card;
    Page_manage_minion* page_manage_minion;
    Page_battle_scene* page_battle_scene;
    Page_result* page_result;
    Page_instruction* page_instruction;

    void changescene(int num=0);
    int get_scenenum();

    int money;

    int deck_player_all[51];
    int deck_player_left[51];
    int deck_player_battle[21];
    int deck_card[21];
    int player_card_total_num;
    int player_deck_left_flag;

    int battle_state;
    int battle_score;
    int battle_time;
    int tower_left_HP;
    int battle_result;  //0:tie 1:win 2:lose

    int battle_hard;
    int battle_prize;
    int battle_now;

private:
    int scenenumber;
};

#endif // SCENEMANAGER_H
