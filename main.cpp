#include "g_gamewindow.h"
#include "g_statingdialog.h"
#include "g_welcomedialog.h"

#include "c_menudata.h"
#include "c_gamedata.h"
#include "statemachine.h"

#include "c_turnorderstate.h"
#include "c_buyresourcesstate.h"
#include "c_buypowerplantstate.h"
#include "c_buildstate.h"
#include "c_bureaucracystate.h"
#include "c_gamelog_phase.h"
#include "c_gamelog_player.h"

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

    StateMachine states;

    wd.exec();

    if (wd.GetMenuOption() == MENU_NEW_GAME) {

        pGameData->Initialize();

        w.show();

        states.ChangeState(&state);
        states.ChangeState(&state1);
        states.ChangeState(&state2);
        states.ChangeState(&state3);

        pGameData->SaveGame();
    }

    else {
        pGameData->LoadGame();

        w.show();

        states.ChangeState(&state);
        states.ChangeState(&state1);
        states.ChangeState(&state2);
        states.ChangeState(&state3);
    }
    return a.exec();
}
