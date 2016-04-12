#ifndef C_RESOURCEMARKETDATA_H
#define C_RESOURCEMARKETDATA_H

#include "i_subject.h"

#include "base.h"


class C_ResourceMarket : public I_Subject {
public:
    C_ResourceMarket();
    C_ResourceMarket(int coal, int oil, int garbage, int uranium);
    ~C_ResourceMarket();

    int GetCoal();
    const int GetCoal() const;
    void SellCoal();

    int GetOil();
    const int GetOil() const;
    void SellOil();

    int GetGarbage();
    const int GetGarbage() const;
    void SellGarbage();

    int GetUranium();
    const int GetUranium() const;
    void SellUranium();

    int GetCostOfCoal();
    const int GetCostOfCoal() const;

    int GetCostOfOil();
    const int GetCostOfOil() const;

    int GetCostOfGarbage();
    const int GetCostOfGarbage() const;

    int GetCostOfUranium();
    const int GetCostOfUranium() const;

    void SetResources(int coal, int oil, int garbage, int uranium);

    void ResetResources();

private:
    int m_iCoal;
    int m_iOil;
    int m_iGarbage;
    int m_iUranium;
};

#endif // C_RESOURCEMARKETDATA_H
