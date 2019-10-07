#-------------------------------------------------
#
# Project created by QtCreator 2017-06-07T14:56:35
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJECT3
TEMPLATE = app


SOURCES += main.cpp \
    scenemanager.cpp \
    page_welcome.cpp \
    button_welcome.cpp \
    page_home.cpp \
    button_home_choose.cpp \
    money.cpp \
    page_battle_choose.cpp \
    button_battle_choose.cpp \
    page_draw_card.cpp \
    page_buy_card.cpp \
    flash_button.cpp \
    minion.cpp \
    price_minion.cpp \
    page_manage_minion.cpp \
    page_battle_scene.cpp \
    minion_battle.cpp \
    text.cpp \
    page_result.cpp \
    page_instruction.cpp

HEADERS  += \
    scenemanager.h \
    page_welcome.h \
    button_welcome.h \
    page_home.h \
    button_home_choose.h \
    money.h \
    page_battle_choose.h \
    button_battle_choose.h \
    page_draw_card.h \
    page_buy_card.h \
    flash_button.h \
    minion.h \
    price_minion.h \
    page_manage_minion.h \
    page_battle_scene.h \
    minion_battle.h \
    text.h \
    page_result.h \
    page_instruction.h

FORMS    += mainwindow.ui

RESOURCES += \
    resourse.qrc
