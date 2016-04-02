#ifndef C_BUYPOWERPLANTSTATE_H
#define C_BUYPOWERPLANTSTATE_H

#pragma once

// Common
#include "StateMachine.h"
#include "i_state.h"
#include "i_subject.h"

#include "c_deckdata.h"
#include "c_deckview.h"
#include "c_gamedata.h"

#include "g_biddingwindows.h"
#include "g_biddingdialog.h"

#include "base.h"

class C_BuyPowerPlantState : public I_State, I_Subject{
public:
    C_BuyPowerPlantState();
    ~C_BuyPowerPlantState();

    // IState
    void Start();
    void Enter();
    void Exit();

private:
    G_BiddingWindows* biddingWds;

};

#endif // C_BUYPOWERPLANTSTATE_H
