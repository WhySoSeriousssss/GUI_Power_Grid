#include "C_BuyResourcesState.h"

C_BuyResourcesState::C_BuyResourcesState() {

}

C_BuyResourcesState::~C_BuyResourcesState() {

}

void C_BuyResourcesState::Start() {

    for (int i = (int)pGameData->playerList.size() - 1; i >= 0; i--) {
        G_BuyingResourcesDialog* buyResourcesDlg = new G_BuyingResourcesDialog();

        int coal = m_pMarket->GetCoal();
        int oil = m_pMarket->GetOil();
        int garbage = m_pMarket->GetGarbage();
        int uranium = m_pMarket->GetUranium();

        int coalPrice = m_pMarket->GetCostOfCoal();
        int oilPrice = m_pMarket->GetCostOfOil();
        int garbagePrice = m_pMarket->GetCostOfGarbage();
        int uraniumPrice = m_pMarket->GetCostOfUranium();

        buyResourcesDlg->SetResourceMarket(coal, oil, garbage, uranium, coalPrice, oilPrice, garbagePrice, uraniumPrice);
        buyResourcesDlg->SetDisplay(pGameData->playerList[i].GetName(), pGameData->playerList[i].GetMoney());
        buyResourcesDlg->exec();

        if (buyResourcesDlg->Accepted == 1) {
            int *qt = buyResourcesDlg->GetBuyingQuantities();

            for (int j = 0; j < qt[0]; j++) {
                pGameData->PlayerAttemptsToBuyResource(i, 1);
            }
            for (int j = 0; j < qt[1]; j++) {
                pGameData->PlayerAttemptsToBuyResource(i, 2);
            }
            for (int j = 0; j < qt[2]; j++) {
                pGameData->PlayerAttemptsToBuyResource(i, 3);
            }
            for (int j = 0; j < qt[3]; j++) {
                pGameData->PlayerAttemptsToBuyResource(i, 4);
            }
        }

        delete buyResourcesDlg;
    }
//	m_pOwner->NextPhase();
}

void C_BuyResourcesState::Enter() {
    std::cout << "Entering Buy Resources State\n";
    m_pMarket = &pGameData->market;
//	m_View.SetData(m_pMarket);

}

void C_BuyResourcesState::Exit() {
    std::cout << "Exiting Buy Resources State\n";
}
