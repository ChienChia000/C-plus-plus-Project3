#ifndef BUTTON_HOME_CHOOSE_H
#define BUTTON_HOME_CHOOSE_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Button_home_choose : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button_home_choose(QGraphicsItem* parent=0);

};

#endif // BUTTON_HOME_CHOOSE_H
