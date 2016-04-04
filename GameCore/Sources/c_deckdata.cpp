#include "c_deckdata.h"
#include <QDir>
#include <QApplication>

C_DeckData::C_DeckData() {

    pugi::xml_document doc;
    doc.load_file("deck.xml");

    pugi::xml_node cardTemp = doc.child("deck");

    //put all cards in the AllCards Vector
    for (pugi::xml_node card = cardTemp.first_child(); card; card = card.next_sibling()) {
        m_vAllCards.push_back(C_CardData(
            XMLParseInt(card.attribute("number")),
            XMLParseInt(card.attribute("cost")),
            XMLParseInt(card.attribute("payment")),
            XMLParseInt(card.attribute("powers"))
            ));
    }

    //put the first 8 cards into the market
    for (int i = 0; i < 8; i++) {
        m_vInMarket.push_back(&m_vAllCards[i]);
    }

    //put the remaining cards in the deck
    for (int i = 8; i < m_vAllCards.size(); i++) {
        m_vInDeck.push_back(&m_vAllCards[i]);
    }

    //shuffle the deck except card 13, so that card 13 is still on the top of the deck
    std::random_shuffle(m_vInDeck.begin() + 1, m_vInDeck.end());

    //remove last 8 cards and put them in the discarded deck
    for (int i = 0; i < 8; i++) {
        m_vDiscarded.push_back(m_vInDeck.back());
        m_vInDeck.pop_back();
    }

}


void C_DeckData::SetDeck(std::vector<C_CardData*> deck1, std::vector<C_CardData*> deck2, std::vector<C_CardData*> deck3, std::vector<C_CardData*> deck4) {
    m_vInDeck = deck1;
    m_vInMarket = deck2;
    m_vInHold = deck3;
    m_vDiscarded = deck4;
}


C_DeckData::~C_DeckData() {

}

// Junan: It is called when a player buys the card with specific number from the market.
//        Basically, it is devided in 2 parts: First, it removes the corresponding card
//        from the market vector. Second, it removes the first card from the deck vector,
//        and insert it into the right position of the market vector.
C_CardData* C_DeckData::PlayerBuysCard(int index) {

    //put this card in the inHold Vector
    m_vInHold.push_back(m_vInMarket[index]);

    //erase that card from market
    m_vInMarket.erase(m_vInMarket.begin() + index);

    C_CardData* newCard = m_vInDeck[0];
    m_vInDeck.erase(m_vInDeck.begin());

    int pos = 0;
    for (int i = 0; i < m_vInMarket.size(); i++) {
        if (m_vInMarket[i]->GetNumber() < newCard->GetNumber())
            pos++;
        else
            break;
    }
    m_vInMarket.insert(m_vInMarket.begin() + pos, newCard);

    Notify();
    return m_vInHold.back();
}


// Junan: It is called when no player buys a card in the Auction phase.
//        Then the market will remove the smallest card and fill in with another card from the
//        top of the deck.
//        It has 2 parts: first, it removes the smallest card from the market vector, and put
//        it into the discarded vector. Second, it it removes the first card from the deck vector,
//        and insert it into the right position of the market vector.
void C_DeckData::FillInMarket() {
    m_vDiscarded.push_back(m_vInMarket[0]);
    m_vInMarket.erase(m_vInMarket.begin());

    C_CardData* card = m_vInDeck[0];
    m_vInDeck.erase(m_vInDeck.begin());
    int pos = 0;
    for (int i = 0; i < m_vInMarket.size(); i++) {
        if (m_vInMarket[i]->GetNumber() < card->GetNumber())
            pos++;
        else
            break;
    }
    m_vInMarket.insert(m_vInMarket.begin() + pos, card);

    Notify();
}

//Junan: this function is for loading pattern.
C_CardData* C_DeckData::FindCardInHold(int number) {
    for (int i = 0; i < m_vInHold.size(); i++) {
        if (m_vInHold[i]->GetNumber() == number)
            return m_vInHold[i];
    }

}


std::vector<C_CardData*>* C_DeckData::GetMarket() {
    return &m_vInMarket;
}

void C_DeckData::Serialize(pugi::xml_node &parent) {
    auto inDeck = XMLAppendChild(parent, "in-deck");
    for (int i = 0; i < m_vInDeck.size(); i++) {
        auto card = XMLAppendChild(inDeck, "card");
        XMLAppendAttribute(card, "number", m_vInDeck[i]->GetNumber());
        XMLAppendAttribute(card, "cost", m_vInDeck[i]->GetCost());
        XMLAppendAttribute(card, "payment", m_vInDeck[i]->GetResources());
        XMLAppendAttribute(card, "powers", m_vInDeck[i]->GetCitiesPowered());
    }

    auto inMarket = XMLAppendChild(parent, "in-market");
    for (int i = 0; i < m_vInMarket.size(); i++) {
        auto card = XMLAppendChild(inMarket, "card");
        XMLAppendAttribute(card, "number", m_vInMarket[i]->GetNumber());
        XMLAppendAttribute(card, "cost", m_vInMarket[i]->GetCost());
        XMLAppendAttribute(card, "payment", m_vInMarket[i]->GetResources());
        XMLAppendAttribute(card, "powers", m_vInMarket[i]->GetCitiesPowered());
    }

    auto inHold = XMLAppendChild(parent, "in-hold");
    for (int i = 0; i < m_vInHold.size(); i++) {
        auto card = XMLAppendChild(inHold, "card");
        XMLAppendAttribute(card, "number", m_vInHold[i]->GetNumber());
        XMLAppendAttribute(card, "cost", m_vInHold[i]->GetCost());
        XMLAppendAttribute(card, "payment", m_vInHold[i]->GetResources());
        XMLAppendAttribute(card, "powers", m_vInHold[i]->GetCitiesPowered());
    }

    auto inDiscarded = XMLAppendChild(parent, "in-discarded");
    for (int i = 0; i < m_vDiscarded.size(); i++) {
        auto card = XMLAppendChild(inDiscarded, "card");
        XMLAppendAttribute(card, "number", m_vDiscarded[i]->GetNumber());
        XMLAppendAttribute(card, "cost", m_vDiscarded[i]->GetCost());
        XMLAppendAttribute(card, "payment", m_vDiscarded[i]->GetResources());
        XMLAppendAttribute(card, "powers", m_vDiscarded[i]->GetCitiesPowered());
    }
}

