#ifndef C_CARDDATA_H
#define C_CARDDATA_H

#include "base.h"

class C_CardData {
public:
    C_CardData();
    C_CardData(int number, int cost, int resources, int poweres);
    ~C_CardData();

    int GetNumber();
    const int GetNumber() const;

    int GetCost();
    const int GetCost() const;

    int GetResources();
    const int GetResources() const;

    int GetCitiesPowered();
    const int GetCitiesPowered() const;

    void Print();

private:
    int m_iNumber;
    int m_iResourceCost;
    int m_iResources;
    int m_iNumberOfCitiesPowered;
};

#endif // C_CARDDATA_H
