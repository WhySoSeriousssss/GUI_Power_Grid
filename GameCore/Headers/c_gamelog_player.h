#ifndef C_GAMELOG_PLAYER_H
#define C_GAMELOG_PLAYER_H

#include "c_gamelog.h"
#include "c_gamelog_decorator.h"

#include "i_observer.h"
#include "i_dialog.h"

class C_GameLog_Player : public C_GameLog_Decorator {
public:
    C_GameLog_Player() {

    }

    ~C_GameLog_Player() {

    }

    void Initialize(I_Dialog *dlg) {
        this->dlg = dlg;
        dlg->Attach(this);
    }

    void Update() {
        log = dlg->GetPlayerLog();
        std::cout << "Player Log: " << GetLog() << std::endl;
    }

    std::string GetLog() {
        return C_GameLog_Decorator::GetLog() + log;
    }

private:
    I_Dialog *dlg;
    std::string log;
};

#endif // C_GAMELOG_PLAYER_H
