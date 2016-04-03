#ifndef C_BUREAUCRACYSTATE_H
#define C_BUREAUCRACYSTATE_H

#include "I_State.h"
#include "I_Subject.h"

#include "C_GameData.h"

#include "g_bureaucracydialog.h"

#include "base.h"

class C_BureaucracyState : public I_State, I_Subject {
public:
    C_BureaucracyState();
    ~C_BureaucracyState();

    // IState
    void Start();
    void Enter();
    void Exit();

};

#endif // C_BUREAUCRACYSTATE_H
