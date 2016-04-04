#include "g_gamewindow.h"
#include "g_statingdialog.h"
#include "g_welcomedialog.h"

#include "c_menudata.h"
#include "c_gamedata.h"

#include "c_buyresourcesstate.h"
#include "c_buypowerplantstate.h"
#include "c_bureaucracystate.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g_GameWindow w;
    G_WelcomeDialog wd;

    C_BuyPowerPlantState state;
    C_BuyResourcesState state1;
    C_BureaucracyState state2;

    wd.exec();
    if (wd.GetMenuOption() == MENU_NEW_GAME) {

        pGameData->Initialize();
        w.show();

        state.Enter();
        state.Start();

        state1.Enter();
        state1.Start();

        state2.Enter();
        state2.Start();


    }


    return a.exec();
}
