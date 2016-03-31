#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#pragma once

#include "i_state.h"
#include "base.h"

// MAT: I decided I want to use references
// I just haven't got around to changing to the code :)

class StateMachine {
public:
    StateMachine() :
        m_pCurrentState(nullptr),
        m_bInTransition(false) {
    }

    virtual ~StateMachine() {

    }

    void ChangeState(I_State* value) {
        Transition(value);
        value->Start();
    }

    I_State* GetCurrentState() {
        return m_pCurrentState;
    }

    const I_State* GetCurrentState() const {
        return m_pCurrentState;
    }

private:
    void Transition(I_State* pState) {
        if (pState == nullptr) {
            return;
        }

        if (m_pCurrentState == pState || m_bInTransition) {
            return;
        }

        m_bInTransition = true;

        if (m_pCurrentState != nullptr) {
            m_pCurrentState->Exit();
        }

        m_pCurrentState = pState;
        m_pCurrentState->Enter();

        m_bInTransition = false;
    }

    I_State* m_pCurrentState;
    bool m_bInTransition;
};

#endif // STATEMACHINE_H
