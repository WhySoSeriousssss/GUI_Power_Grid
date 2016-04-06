#ifndef C_BUILDSTATE_H
#define C_BUILDSTATE_H

#include "i_state.h"

#include "c_gamedata.h"

#include "g_buildingdialog.h"

class C_BuildState: public I_State {

public:
    C_BuildState();
    ~C_BuildState();

    // IState
    void Start();
    void Enter();
    void Exit();

private:
    G_BuildingDialog buildingDlg;

};

#endif // C_BUILDSTATE_H
