#ifndef TEXT_H
#define TEXT_H

#include<QGraphicsTextItem>

class Text : public QGraphicsTextItem
{
public:
    Text(int type=0, QGraphicsItem* parent=0, int initial_HP=0);

    void mana_increase();
    void mana_decrease(int decrease_num);
    int get_mana();
private:
    int mana;
};

#endif // TEXT_H
