#include <QApplication>
#include<QIcon>

#include"scenemanager.h"

Scenemanager* scenemanager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    scenemanager = new Scenemanager();
    scenemanager->setWindowTitle("Battle");
    //scenemanager->setWindowIcon(QIcon(""));
    scenemanager->show();

    return a.exec();
}
