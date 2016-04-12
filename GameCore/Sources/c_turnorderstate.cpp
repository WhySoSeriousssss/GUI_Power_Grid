#include "c_turnorderstate.h"

C_TurnOrderState::C_TurnOrderState() {

}

C_TurnOrderState::~C_TurnOrderState() {
    // MAT: Vectors handle there own memory management so whatever.
}

void C_TurnOrderState::Start() {
    std::cout << "Start Turn Order State\n";
}

void C_TurnOrderState::Enter() {
    std::cout << "Entering Turn Order State\n";
    pGameData->market.ResetResources();
//    std::sort(pGameData->playerList.begin(), pGameData->playerList.end(), CompareFunction);
}

void C_TurnOrderState::Exit() {
    std::cout << "Exiting Turn Order State\n\n";
}

bool CompareFunction(const C_PlayerData &p1, const C_PlayerData &p2) {
    if (p1.GetHouse().size() > p2.GetHouse().size()) {
        return true;
    }
    else if (p1.GetHouse().size() == p1.GetHouse().size()) {
        if (p1.GetCard().size() > p2.GetCard().size()) {
            return true;
        }
    }

    return false;
}
