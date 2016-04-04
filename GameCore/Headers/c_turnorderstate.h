#ifndef C_TURNORDERSTATE_H
#define C_TURNORDERSTATE_H

#include "i_state.h"
#include "c_gamedata.h"

class C_TurnOrderState: public I_State{
public:
    C_TurnOrderState();
    ~C_TurnOrderState();

    // IState
    void Start();
    void Enter();
    void Exit();
};

#endif // C_TURNORDERSTATE_H
