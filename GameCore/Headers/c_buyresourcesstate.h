#ifndef C_BUYRESOURCESSTATE_H
#define C_BUYRESOURCESSTATE_H

#include "g_buyingresourcesdialog.h"

#include "i_state.h"
#include "i_subject.h"

#include "c_gamedata.h"

#include "base.h"

class C_BuyResourcesState : public I_State, I_Subject {
public:
    C_BuyResourcesState();
    ~C_BuyResourcesState();

    // IState
    void Start();
    void Enter();
    void Exit();

private:
//	CMarketView m_View;
    C_ResourceMarket* m_pMarket;
};

#endif // C_BUYRESOURCESSTATE_H
