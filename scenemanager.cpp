#include "scenemanager.h"



Scenemanager::Scenemanager() : QGraphicsView()
{
    money = 3000;
    battle_state=1;
    battle_hard=0;
    battle_prize=0;
    player_card_total_num = 5;
    player_deck_left_flag = 0;
    for(int i=1;i<=20;i++)
        deck_card[i]=i;
    for(int i=1;i<=5;i++)
    {
        deck_player_all[i]=i;
        deck_player_battle[i]=i;
    }
    for(int i=6;i<=50;i++)
        deck_player_all[i]=0;
    for(int i=1;i<=51;i++)
        deck_player_left[i]=0;
    //battle_result = 0;
    //battle_score = 0;
    //battle_time = 0;
    //tower_left_HP = 0;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    //create the first scene
    page_welcome = new Page_welcome();
    setScene(page_welcome);

}
void Scenemanager::changescene(int num)
{
    scenenumber = num;
    if(scenenumber==1)
    {
        page_home = new Page_home();
        setScene(page_home);
    }
    if(scenenumber==2)
    {
        page_battle_choose = new Page_battle_choose();
        setScene(page_battle_choose);
    }
    if(scenenumber==3)
    {
        page_battle_scene = new Page_battle_scene(battle_hard,battle_prize);
        setScene(page_battle_scene);
    }
    if(scenenumber==4)
    {
        page_manage_minion = new Page_manage_minion();
        setScene(page_manage_minion);
    }
    if(scenenumber==5)
    {
        page_draw_card = new Page_draw_card();
        setScene(page_draw_card);
    }
    if(scenenumber==6)
    {
        page_buy_card = new Page_buy_card();
        setScene(page_buy_card);
    }
    if(scenenumber==7)
    {
        page_result = new Page_result();
        setScene(page_result);
    }
    if(scenenumber==8)
    {
        page_instruction = new Page_instruction();
        setScene(page_instruction);
    }
}
int Scenemanager::get_scenenum()
{
    return scenenumber;
}
