#include "C_BuyResourcesState.h"

C_BuyResourcesState::C_BuyResourcesState() {

}

C_BuyResourcesState::~C_BuyResourcesState() {

}

void C_BuyResourcesState::Start() {
    std::cout << "Start Buy Resources State.\n";

    for (int i = (int)pGameData->playerList.size() - 1; i >= 0; i--) {
        G_BuyingResourcesDialog* buyResourcesDlg = new G_BuyingResourcesDialog();

        buyResourcesDlg->Initialize(&pGameData->playerList[i], &pGameData->market);
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
}

void C_BuyResourcesState::Enter() {
    std::cout << "Entering Buy Resources State\n";
    m_pMarket = &pGameData->market;
//	m_View.SetData(m_pMarket);

}

void C_BuyResourcesState::Exit() {
    std::cout << "Exiting Buy Resources State\n\n";
}
