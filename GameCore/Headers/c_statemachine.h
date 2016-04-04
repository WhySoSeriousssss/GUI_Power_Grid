#ifndef C_STATEMACHINE_H
#define C_STATEMACHINE_H

#include "c_bureaucracystate.h"
#include "c_buypowerplantstate.h"
#include "c_buyresourcesstate.h"
#include "c_buildstate.h"
#include "c_turnorderstate.h"

#include "i_state.h"

class C_StateMachine {
public:
    C_StateMachine();
    ~C_StateMachine();

//    void Initialize();
    void Start();

private:
    std::vector<I_State*> states;
    I_State* currentState;
};

#endif // C_STATEMACHINE_H
