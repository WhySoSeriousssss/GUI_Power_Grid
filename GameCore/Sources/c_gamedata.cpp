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

void C_GameData::SaveGame() {
    // create save game document
    pugi::xml_document doc;
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version") = "1.0";

    // create game root
    auto root = XMLAppendChild(doc, "game");

    // serialize the resource market
    auto resources = XMLAppendChild(root, "resources");
    XMLAppendAttribute(resources, "coal", market.GetCoal());
    XMLAppendAttribute(resources, "oil", market.GetOil());
    XMLAppendAttribute(resources, "garbage", market.GetGarbage());
    XMLAppendAttribute(resources, "uranium", market.GetUranium());

    // serialize players
    auto players = XMLAppendChild(root, "player-list");
    for (int i = 0; i < playerList.size(); i++) {
        playerList[i].Serialize(players);
    }

    //serialize deck
    deck.Serialize(root);
    doc.save_file("gamesave.xml");
}

void C_GameData::LoadGame() {

    pugi::xml_document doc;
    doc.load_file("gamesave.xml");

    pugi::xml_node root = doc.child("game");

    //load resource market
    pugi::xml_node resource_node = root.child("resources");
    market.SetResources(
        XMLParseInt(resource_node.attribute("coal")),
        XMLParseInt(resource_node.attribute("oil")),
        XMLParseInt(resource_node.attribute("garbage")),
        XMLParseInt(resource_node.attribute("uranium"))
                );


    // load deck info
    std::vector<C_CardData *> inDeck;
    std::vector<C_CardData *> inMarket;
    std::vector<C_CardData *> inHold;
    std::vector<C_CardData *> inDiscarded;

    pugi::xml_node indeck_node = root.child("in-deck");
    for (pugi::xml_node deckCard = indeck_node.first_child(); deckCard; deckCard = deckCard.next_sibling()) {
        inDeck.push_back(new C_CardData(
                             XMLParseInt(deckCard.attribute("number")),
                             XMLParseInt(deckCard.attribute("cost")),
                             XMLParseInt(deckCard.attribute("payment")),
                             XMLParseInt(deckCard.attribute("powers"))
                             ));
    }

    pugi::xml_node inmarket_node = root.child("in-market");
    for (pugi::xml_node deckCard = inmarket_node.first_child(); deckCard; deckCard = deckCard.next_sibling()) {
        inMarket.push_back(new C_CardData(
                             XMLParseInt(deckCard.attribute("number")),
                             XMLParseInt(deckCard.attribute("cost")),
                             XMLParseInt(deckCard.attribute("payment")),
                             XMLParseInt(deckCard.attribute("powers"))
                             ));
    }

    pugi::xml_node inhold_node = root.child("in-hold");
    for (pugi::xml_node deckCard = inhold_node.first_child(); deckCard; deckCard = deckCard.next_sibling()) {
        inHold.push_back(new C_CardData(
                             XMLParseInt(deckCard.attribute("number")),
                             XMLParseInt(deckCard.attribute("cost")),
                             XMLParseInt(deckCard.attribute("payment")),
                             XMLParseInt(deckCard.attribute("powers"))
                             ));
    }

    pugi::xml_node indiscarded_node = root.child("in-discarded");
    for (pugi::xml_node deckCard = indiscarded_node.first_child(); deckCard; deckCard = deckCard.next_sibling()) {
        inDiscarded.push_back(new C_CardData(
                             XMLParseInt(deckCard.attribute("number")),
                             XMLParseInt(deckCard.attribute("cost")),
                             XMLParseInt(deckCard.attribute("payment")),
                             XMLParseInt(deckCard.attribute("powers"))
                             ));
    }

    deck.SetDeck(inDeck, inMarket, inHold, inDiscarded);

    // load players info
    pugi::xml_node player_node = root.child("player-list");

    for (pugi::xml_node player = player_node.first_child(); player; player = player.next_sibling()) {

        //parsing cards
        std::vector<C_CardData *> tempCards;
        pugi::xml_node cards = player.child("cards");
        for (pugi::xml_node card = cards.first_child(); card; card = card.next_sibling()) {
            tempCards.push_back(deck.FindCardInHold(XMLParseInt(card.attribute("number"))));
        }

        //parsing houses
        std::vector<C_HouseData *> tempHouses;
        pugi::xml_node houses = player.child("houses");
        for (pugi::xml_node city = houses.child("city"); city; city = city.next_sibling()) {
            tempHouses.push_back(new C_HouseData(map.GetCityByName(XMLParseString(city.attribute("name")))));
        }

        playerList.push_back(C_PlayerData(
            XMLParseString(player.attribute("name")),
            XMLParseInt(player.attribute("money")),
            XMLParseInt(player.attribute("coal")),
            XMLParseInt(player.attribute("oil")),
            XMLParseInt(player.attribute("garbage")),
            XMLParseInt(player.attribute("uranium")),
            tempCards,
            tempHouses
            ));
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
