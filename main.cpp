#include "g_gamewindow.h"
#include "g_statingdialog.h"
#include "g_welcomedialog.h"

#include "c_menudata.h"
#include "c_gamedata.h"

#include "c_buyresourcesstate.h"
#include "c_buypowerplantstate.h"
#include "c_bureaucracystate.h"
#include "c_buildstate.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g_GameWindow w;
    G_WelcomeDialog wd;

    C_BuyPowerPlantState state;
    C_BuyResourcesState state1;
    C_BuildState state2;
    C_BureaucracyState state3;

    wd.exec();
    if (wd.GetMenuOption() == MENU_NEW_GAME) {

        pGameData->Initialize();

        w.show();

        state2.Start();
        /*
        state.Enter();
        state.Start();

        state1.Enter();
        state1.Start();

        state3.Enter();
        state3.Start();
        */


    }


    return a.exec();
}
