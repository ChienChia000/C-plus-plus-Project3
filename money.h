#ifndef MONEY_H
#define MONEY_H

#include<QGraphicsTextItem>

class Money : public QGraphicsTextItem
{
public:
    Money();
    void money_increase(int add_money);
    int get_money();
};

#endif // MONEY_H
