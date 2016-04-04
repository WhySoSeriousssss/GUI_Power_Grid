#include "c_statemachine.h"

C_StateMachine::C_StateMachine() {

}

C_StateMachine::~C_StateMachine() {

}

/*
void C_StateMachine::Initialize() {
    states.push_back(new C_TurnOrderState);
    states.push_back(new C_BuyPowerPlantState);
    states.push_back(new C_BuyResourcesState);
    states.push_back(new C_BuildState);
    states.push_back(new C_BureaucracyState);

    currentState = states.front();
}
*/

void C_StateMachine::Start() {
    currentState->Enter();
    currentState->Start();
    currentState->Exit();

    states.erase(states.begin());
    currentState = states.front();
}
