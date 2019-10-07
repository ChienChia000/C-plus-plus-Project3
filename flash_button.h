#ifndef FLASH_BUTTON_H
#define FLASH_BUTTON_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include<QTimer>

class Flash_button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Flash_button(int type=0, QGraphicsItem* parent=0);

    QTimer* timer_flash_button;
public slots:
    void change();
private:
    int button_num;
    int flag;
};

#endif // FLASH_BUTTON_H
