#ifndef BUTTON_BATTLE_CHOOSE_H
#define BUTTON_BATTLE_CHOOSE_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include<QTimer>

class Button_battle_choose : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button_battle_choose(QGraphicsItem* parent=0);
    QTimer* timer_battle_choose;
public slots:
    void change();
private:
    int button_num;
};

#endif // BUTTON_BATTLE_CHOOSE_H
