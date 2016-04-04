#ifndef C_GAMEDATA_H
#define C_GAMEDATA_H

// Model
#include "c_playerdata.h"
#include "c_deckdata.h"
#include "c_resourcemarketdata.h"
//#include "C_MapData.h"
//#include "C_ResourceMarketView.h"

#include "base.h"

#include "g_playerinfoinitdialog.h"
#include "g_statingdialog.h"

enum BuyResults_e {
    BUY_INSUFFICIENT_FUNDS,
    BUY_REACH_MAXIMUM,
    BUY_NOT_ENOUGH_RESOURCE,
    BUY_SUCCEED
};

class C_GameData {
public:
    C_GameData();

    int currentRound;
    float currentTime;

    vector<C_PlayerData> playerList;

    C_DeckData deck;

    C_ResourceMarket market;
//    C_ResourceMarketView marketView;

//    C_MapData map;

    void Initialize();

    BuyResults_e PlayerAttemptsToBuyResource(int playerNum, int resourceType);

    void PlayerBuysCard(int cardIndex);

    //Junan: for testing
    void Print();
};

extern C_GameData *pGameData;

#endif // C_GAMEDATA_H
