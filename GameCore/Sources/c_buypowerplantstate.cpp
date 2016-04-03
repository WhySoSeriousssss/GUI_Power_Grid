#include "c_gamecontroller.h"
#include "C_BuyPowerPlantState.h"


C_BuyPowerPlantState::C_BuyPowerPlantState() :
    biddingWds(new G_BiddingWindows){

}

C_BuyPowerPlantState::~C_BuyPowerPlantState() {
    delete biddingWds;
}

void C_BuyPowerPlantState::Start() {
    std::cout << "Start Buy Power Plant State.\n\n";

    biddingWds->Start();
    biddingWds->show();

//	m_pOwner->NextPhase();
}

void C_BuyPowerPlantState::Enter() {
    std::cout << "Entering Buy Power Plant State\n";
    biddingWds->Initialize(&pGameData->deck);
}

void C_BuyPowerPlantState::Exit() {
    std::cout << "Exiting Buy Power Plant State\n";
}

