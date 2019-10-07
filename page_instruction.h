#ifndef PAGE_INSTRUCTION_H
#define PAGE_INSTRUCTION_H


#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

class Page_instruction : public QGraphicsScene
{
public:
    Page_instruction();

    void keyPressEvent(QKeyEvent * event);
    QMediaPlayer* music_instruction;

private:
    int flag;
};

#endif // PAGE_INSTRUCTION_H
