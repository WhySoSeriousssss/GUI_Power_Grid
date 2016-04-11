#include "C_BureaucracyState.h"

C_BureaucracyState::C_BureaucracyState() {

}

C_BureaucracyState::~C_BureaucracyState() {
    // MAT: Vectors handle there own memory management so whatever.
}

void C_BureaucracyState::Start() {
    std::cout << "Start Bureaucracy State.\n";

    for (int i = 0; i < pGameData->playerList.size(); i++) {
        G_BureaucracyDialog dlg;
        dlg.Initialize(&pGameData->playerList[i]);
        dlg.exec();
    }
}

void C_BureaucracyState::Enter() {
    std::cout << "Entering Bureaucracy State\n";
}

void C_BureaucracyState::Exit() {
    std::cout << "Exiting Bureaucracy State\n\n";
}
