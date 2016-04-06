#include "c_gamedata.h"

static C_GameData _gameData;
C_GameData *pGameData = &_gameData;

C_GameData::C_GameData() :
    currentRound(0),
    currentTime(0.0f) {
    map.LoadMap("map_canada.xml");
}

void C_GameData::Print() {
    std::cout << "There are " << playerList.size() << " players:\n";
    for (int i = 0; i < playerList.size(); i++)
        std::cout << i + 1 << ". " << playerList[i].GetName() << "\n";
}

void C_GameData::Initialize() {
    G_StatingDialog startDlg;
    startDlg.exec();
    int playerNum = startDlg.GetNumberOfPlayers();

    for (int i = 0; i < playerNum; i++) {
        G_PlayerInfoInitDialog* playerDlg = new G_PlayerInfoInitDialog();
        playerDlg->exec();

        if (playerDlg->Accepted == 1) {
            std::string pName = playerDlg->GetPlayerName();
            C_PlayerData p(pName);
            playerList.push_back(p);
        }

        delete playerDlg;
    }


}


BuyResults_e C_GameData::PlayerAttemptsToBuyResource(int playerNum, int resourceType) {
    switch (resourceType)
    {
        //coal
    case 1:
        if (market.GetCoal() == 0) {
            return BUY_NOT_ENOUGH_RESOURCE;
        }

        else {
            if (playerList[playerNum].GetMoney() < market.GetCostOfCoal()) {
                return BUY_INSUFFICIENT_FUNDS;
            }
            else {
                if (playerList[playerNum].GetMaxCoal() <= playerList[playerNum].GetCoal())
                    return BUY_REACH_MAXIMUM;

                market.SellCoal();
                playerList[playerNum].BuyCoal();
                playerList[playerNum].ConsumeMoney(market.GetCostOfCoal());
                return BUY_SUCCEED;
            }
        }
        //oil
    case 2:
        if (market.GetOil() == 0) {
            return BUY_NOT_ENOUGH_RESOURCE;
        }

        else {
            if (playerList[playerNum].GetMoney() < market.GetCostOfOil()) {
                    return BUY_INSUFFICIENT_FUNDS;
            }
            else {
                if (playerList[playerNum].GetMaxOil() <= playerList[playerNum].GetOil())
                    return BUY_REACH_MAXIMUM;
                market.SellOil();
                playerList[playerNum].BuyOil();
                playerList[playerNum].ConsumeMoney(market.GetCostOfOil());
                return BUY_SUCCEED;
            }
        }
        //garbage
    case 3:
        if (market.GetGarbage() == 0) {
            return BUY_NOT_ENOUGH_RESOURCE;
        }

        else {
            if (playerList[playerNum].GetMoney() < market.GetCostOfGarbage()) {
                    return BUY_INSUFFICIENT_FUNDS;
            }
            else {
                if (playerList[playerNum].GetMaxGarbage() <= playerList[playerNum].GetGarbage())
                    return BUY_REACH_MAXIMUM;

                market.SellGarbage();
                playerList[playerNum].BuyGarbage();
                playerList[playerNum].ConsumeMoney(market.GetCostOfGarbage());
                return BUY_SUCCEED;
            }
        }
        //Uranium
    case 4:
        if (market.GetUranium() == 0) {
            return BUY_NOT_ENOUGH_RESOURCE;
        }

        else {
            if (playerList[playerNum].GetMoney() < market.GetCostOfUranium()) {
                return BUY_INSUFFICIENT_FUNDS;
            }
            else {
                if (playerList[playerNum].GetMaxUranium() <= playerList[playerNum].GetUranium())
                    return BUY_REACH_MAXIMUM;

                market.SellUranium();
                playerList[playerNum].BuyUranium();
                playerList[playerNum].ConsumeMoney(market.GetCostOfUranium());
                return BUY_SUCCEED;
            }
        }
    default:
        break;
    }
}
