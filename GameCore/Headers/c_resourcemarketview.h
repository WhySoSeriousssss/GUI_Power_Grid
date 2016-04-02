#ifndef C_RESOURCEMARKETVIEW_H
#define C_RESOURCEMARKETVIEW_H

// Model
#include "c_resourcemarketdata.h"

// Common
#include "i_observer.h"

#include "base.h"

class C_ResourceMarketView : public I_Observer {
public:
    C_ResourceMarketView();
    ~C_ResourceMarketView();

    void SetData(C_ResourceMarket* pData);
    void Render();

    // IObserver
    void Update();

private:
    C_ResourceMarket* m_pData;
};

#endif // C_RESOURCEMARKETVIEW_H
