#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T18:23:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_power_grid
TEMPLATE = app

INCLUDEPATH += GameCore/HEADERS/
INCLUDEPATH += GameCore/include/

SOURCES += main.cpp\
        g_gamewindow.cpp \
    g_welcomedialog.cpp \
    g_statingdialog.cpp \
    g_playerinfoinitdialog.cpp \
    GameCore/Sources/c_menudata.cpp \
    GameCore/Sources/c_gamedata.cpp \
    GameCore/Sources/c_playerdata.cpp \
    GameCore/Sources/c_housedata.cpp \
    GameCore/Sources/c_citydata.cpp \
    GameCore/Sources/c_carddata.cpp \
    GameCore/Sources/c_deckdata.cpp \
    GameCore/Sources/c_resourcemarketdata.cpp \
    GameCore/Sources/c_mapdata.cpp \
    g_buyingresourcesdialog.cpp \
    GameCore/Sources/c_buyresourcesstate.cpp \
    GameCore/Sources/c_gamecontroller.cpp \
    g_biddingwindows.cpp \
    GameCore/Sources/c_resourcemarketview.cpp \
    GameCore/Sources/c_buypowerplantstate.cpp \
    GameCore/include/pugixml.cpp \
    GameCore/util.cpp \
    g_biddingdialog.cpp \
    g_bureaucracydialog.cpp \
    GameCore/Sources/c_bureaucracystate.cpp

HEADERS  += g_gamewindow.h \
    g_welcomedialog.h \
    g_statingdialog.h \
    g_playerinfoinitdialog.h \
    GameCore/Headers/c_menudata.h \
    GameCore/Headers/c_gamedata.h \
    GameCore/Headers/c_playerdata.h \
    GameCore/Headers/base.h \
    GameCore/Headers/i_observer.h \
    GameCore/Headers/i_subject.h \
    GameCore/Headers/c_housedata.h \
    GameCore/Headers/c_citydata.h \
    GameCore/Headers/c_carddata.h \
    GameCore/Headers/c_deckdata.h \
    GameCore/Headers/c_resourcemarketdata.h \
    GameCore/Headers/shareddef.h \
    GameCore/Headers/c_mapdata.h \
    g_buyingresourcesdialog.h \
    GameCore/Headers/c_buyresourcesstate.h \
    GameCore/Headers/i_state.h \
    GameCore/Headers/statemachine.h \
    GameCore/Headers/c_gamecontroller.h \
    g_biddingwindows.h \
    GameCore/Headers/c_resourcemarketview.h \
    GameCore/Headers/c_buypowerplantstate.h \
    GameCore/include/pugiconfig.hpp \
    GameCore/include/pugixml.hpp \
    GameCore/Headers/util.h \
    g_biddingdialog.h \
    g_bureaucracydialog.h \
    GameCore/Headers/c_bureaucracystate.h

FORMS    += g_gamewindow.ui \
    g_welcomedialog.ui \
    g_statingdialog.ui \
    g_playerinfoinitdialog.ui \
    g_buyingresourcesdialog.ui \
    g_biddingwindows.ui \
    g_biddingdialog.ui \
    g_bureaucracydialog.ui
