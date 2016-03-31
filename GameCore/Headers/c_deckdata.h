#ifndef C_DECKDATA_H
#define C_DECKDATA_H

#include "base.h"
#include "c_carddata.h"
#include "i_subject.h"

class C_DeckData : public I_Subject {
public:
    C_DeckData();
    ~C_DeckData();

    void SetDeck(std::vector<C_CardData> deck1, std::vector<C_CardData> deck2, std::vector<C_CardData> deck3, std::vector<C_CardData> deck4);

    C_CardData* PlayerBuysCard(int index);
    void FillInMarket();

    C_CardData* FindCardInHold(int number);

    std::vector<C_CardData> GetMarket();

//    void Serialize(pugi::xml_node &parent);

private:
    std::vector<C_CardData> m_vInDeck;
    std::vector<C_CardData> m_vInMarket;
    std::vector<C_CardData> m_vInHold;
    std::vector<C_CardData> m_vDiscarded;
};

#endif // C_DECKDATA_H
