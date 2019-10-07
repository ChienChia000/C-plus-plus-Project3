#ifndef PAGE_RESULT_H
#define PAGE_RESULT_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

#include"text.h"

class Page_result : public QGraphicsScene
{
public:
    Page_result();

    void keyPressEvent(QKeyEvent * event);
    QMediaPlayer* music_result;

    Text* money_prize;
};

#endif // PAGE_RESULT_H
