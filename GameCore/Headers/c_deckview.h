#ifndef C_DECKVIEW_H
#define C_DECKVIEW_H

#include "i_observer.h"
#include "c_carddata.h"
#include "c_deckdata.h"
#include "base.h"


class C_DeckView : public I_Observer {
public:
    C_DeckView();
    ~C_DeckView();

    void Initialize(C_DeckData *pData);

    void Update();

    void Print();
private:
    std::vector<C_CardData> m_vPowerPlantMarket;
    C_DeckData* m_pDeck;
};

#endif // C_DECKVIEW_H
