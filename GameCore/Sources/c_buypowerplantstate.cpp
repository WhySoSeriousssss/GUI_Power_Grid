#include "c_gamecontroller.h"
#include "C_BuyPowerPlantState.h"
#include <QEventLoop>

C_BuyPowerPlantState::C_BuyPowerPlantState() :
    marketDlg(new G_PlantMarketDialog){

}

C_BuyPowerPlantState::~C_BuyPowerPlantState() {

}

void C_BuyPowerPlantState::Start() {
    std::cout << "Start Buy Power Plant State.\n\n";

    marketDlg->Start();
    marketDlg->exec();

//	m_pOwner->NextPhase();
}

void C_BuyPowerPlantState::Enter() {
    std::cout << "Entering Buy Power Plant State\n";
    marketDlg->Initialize(&pGameData->deck);
}

void C_BuyPowerPlantState::Exit() {
    std::cout << "Exiting Buy Power Plant State\n";
}

