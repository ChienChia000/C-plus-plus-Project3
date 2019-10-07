#ifndef BUTTON_WELCOME_H
#define BUTTON_WELCOME_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Button_welcome : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button_welcome(QGraphicsItem* parent=0);
public slots:
    void change();
private:
    int welcome_num;
};

#endif // BUTTON_WELCOME_H
