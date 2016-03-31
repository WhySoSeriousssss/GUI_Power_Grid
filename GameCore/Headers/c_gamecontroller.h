#ifndef C_GAMECONTROLLER_H
#define C_GAMECONTROLLER_H

#include "statemachine.h"

#include "base.h"

// MAT: Hold all the game data here
class C_GameController : StateMachine {
public:
    C_GameController();
    ~C_GameController();

    void AddState(string name, I_State* pState);
    void LoadState(string name);
    void NextPhase();

private:
//	vector<I_State *> m_States;
//	vector<I_State *>::iterator m_Phase;

    std::unordered_map<string, I_State*> m_States;
};

#endif // C_GAMECONTROLLER_H
