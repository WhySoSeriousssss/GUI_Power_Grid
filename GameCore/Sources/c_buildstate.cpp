#include "c_buildstate.h"

C_BuildState::C_BuildState() {

}

C_BuildState::~C_BuildState() {
}

void C_BuildState::Start() {
    std::cout << "Start Building State\n";

    for (int i = (int)pGameData->playerList.size() - 1; i >= 0; i--) {
        buildingDlg.Initialize(&pGameData->map, &pGameData->playerList[i]);
        buildingDlg.exec();

    }
//	m_pOwner->NextPhase();
}

void C_BuildState::Enter() {
    std::cout << "Entering Building State\n";
}

void C_BuildState::Exit() {
    std::cout << "Exiting Building State\n";
}
