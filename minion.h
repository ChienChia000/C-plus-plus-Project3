#ifndef MINION_H
#define MINION_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QWidget>

class Minion : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Minion(int type=0, int minion_number=0, int hero=0);
    QPixmap minion;

public slots:
    int get_minion_money();
private:
    int minion_type;
    int class_type;

    int minion_money;
};

#endif // MINION_H
