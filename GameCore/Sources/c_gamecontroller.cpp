#include "c_gamecontroller.h"

// States
//#include "C_TurnOrderState.h"
//#include "C_BuyPowerPlantState.h"
//#include "c_buyresourcesstate.h"
//#include "C_BuildState.h"
//#include "C_BureaucracyState.h"

// Model
#include "c_gamedata.h"

C_GameController::C_GameController() {
    //m_States.push_back(new C_TurnOrderState);
    //m_States.push_back(new C_BuyPowerPlantState);
    //m_States.push_back(new C_BuyResourcesState);
    //m_States.push_back(new C_BuildState);
    //m_States.push_back(new C_BureaucracyState);

    //for (auto it = m_States.begin(); it != m_States.end(); it++) {
    //	(*it)->Initialize(this);
    //}

    //m_Phase = m_States.begin();
    //ChangeState(*m_Phase);
}

C_GameController::~C_GameController() {
    //while (!m_States.empty()) {
    //	delete m_States.back();
    //	m_States.pop_back();
    //}

    for (auto it = m_States.begin(); it != m_States.end(); ++it) {
        delete (it->second);
    }
}

void C_GameController::NextPhase() {
    // MAT: I dont like it, but runtime seems to like it
    //if (m_Phase != m_States.end()) {
    //	m_Phase++;

    //	if (m_Phase == m_States.end()) {
    //		std::cout << "That's a complete round!\n\n";
    //		m_Phase = m_States.begin();
    //		pGameData->currentRound++;
    //	}

    //	ChangeState(*m_Phase);
    //}
}

void C_GameController::AddState(string name, I_State* pState) {
    pState->Initialize(this);
    m_States.insert({ name, pState });
}

void C_GameController::LoadState(string name) {
    auto pState = m_States.find(name);

    if (pState == m_States.end()) {
        std::cout << "!!! ERROR: State not found" << std::endl;
    } else {
        ChangeState(pState->second);
    }
}
