#ifndef PAGE_HOME_H
#define PAGE_HOME_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

#include"button_home_choose.h"
#include"money.h"

class Page_home : public QGraphicsScene
{
public:
    Page_home(QWidget* parent=0);

    void keyPressEvent(QKeyEvent * event);
    Button_home_choose* button_home_choose;
    QMediaPlayer* music_home;

    Money* money;

private:
    int choose_number;
};

#endif // PAGE_HOME_H
