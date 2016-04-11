#ifndef C_GAMELOG_PHASE_H
#define C_GAMELOG_PHASE_H

#include "c_gamelog.h"
#include "c_gamelog_player.h"

#include "i_observer.h"
#include "i_dialog.h"

class C_GameLog_Phase : public C_GameLog_Player {

public:
    C_GameLog_Phase() {

    }

    ~C_GameLog_Phase() {

    }

    void Initialize(I_Dialog *dlg) {
        this->dlg = dlg;
        dlg->Attach(this);
    }

    void Update() {
        log = dlg->GetPhaseLog();
        std::cout << "Phase Log: " << GetLog() << std::endl;
    }

    std::string GetLog() {
        return C_GameLog_Decorator::GetLog() + log;
    }

private:
    I_Dialog *dlg;
    std::string log;
};

#endif // C_GAMELOG_PHASE_H
