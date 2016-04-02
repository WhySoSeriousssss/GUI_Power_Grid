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

/*
    while (bidderList.size() != 0) {
        G_BiddingDialog biddingDlg;

        biddingWds->SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());

        biddersThisRound.clear();

        std::cout << "Please type in the index(From 1 to 4, 0 represents abandon):\n";


        if (biddingWds->GetEnter() == 2) {
            std::cout << "Player " << bidderList.front()->GetName() << " abandoned bidding!\n";
            bidderList.erase(bidderList.begin());
            round++;
            continue;
        }
        else {
            index = biddingWds->GetCardNum();
            biddingPrice = biddingWds->GetPrice();
            biddingDlg.SetInitialDisplay(bidderList.front()->GetName(), index, biddingPrice);
            biddingDlg.exec();
            biddersThisRound.push_back(bidderList.front());
        }


        for (int i = 1; i < bidderList.size(); i++) {
            biddingDlg.SetDisplay(bidderList[i]->GetName(), bidderList[i]->GetMoney(), biddingPrice);

            if (biddingDlg.GetAbandon() == true) {
                std::cout << "Player " << bidderList[i]->GetName() << " abandoned bidding!\n";
            }
            else {
                biddingPrice = temp;
                biddersThisRound.push_back(bidderList[i]);
            }
        }

        while (biddersThisRound.size() > 1) {
            for (int i = 0; i < biddersThisRound.size(); i++) {
                std::cout << "Player " << bidderList[i]->GetName() << "'s turn to bid.\n";
                std::cout << "Please type in your bidding price:\n";
                int temp;
                std::cin >> temp;
                if (temp == 0) {
                    std::cout << "Player " << bidderList[i]->GetName() << " abandoned bidding!\n";
                    biddersThisRound.erase(biddersThisRound.begin() + i);
                }
                else {
                    biddingPrice = temp;
                }
            }

        }

        std::cout << "Player " << biddersThisRound[0]->GetName() << " bought plant card finally!\n\n";
        biddersThisRound[0]->ConsumeMoney(biddingPrice);
        biddersThisRound[0]->BuyCard(pGameData->deck.PlayerBuysCard(index - 1));
        for (int i = 0; i < bidderList.size(); i++) {
            if (bidderList[i] == biddersThisRound[0]) {
                bidderList.erase(bidderList.begin() + i);
                break;
            }
        }
        round++;
        */


//	m_pOwner->NextPhase();
}

void C_BuyPowerPlantState::Enter() {
    std::cout << "Entering Buy Power Plant State\n";
    biddingWds->Initialize(&pGameData->deck);
}

void C_BuyPowerPlantState::Exit() {
    std::cout << "Exiting Buy Power Plant State\n";
}

