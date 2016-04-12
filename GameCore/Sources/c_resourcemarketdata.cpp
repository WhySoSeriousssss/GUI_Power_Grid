#include "c_resourcemarketdata.h"
#include "shareddef.h"

C_ResourceMarket::C_ResourceMarket() :
    C_ResourceMarket(
        STARTING_COAL,
        STARTING_OIL,
        STARTING_GARBAGE,
        STARTING_URANIUM
        ) {

}

C_ResourceMarket::C_ResourceMarket(int coal, int oil, int garbage, int uranium) :
    m_iCoal(coal),
    m_iOil(oil),
    m_iGarbage(garbage),
    m_iUranium(uranium) {

}

C_ResourceMarket::~C_ResourceMarket() {

}

int C_ResourceMarket::GetCoal() {
    return m_iCoal;
}

const int C_ResourceMarket::GetCoal() const {
    return m_iCoal;
}

void C_ResourceMarket::SellCoal() {
    m_iCoal--;
    Notify();
}

int C_ResourceMarket::GetOil() {
    return m_iOil;
}

const int C_ResourceMarket::GetOil() const {
    return m_iOil;
}

void C_ResourceMarket::SellOil() {
    m_iOil--;
    Notify();
}

int C_ResourceMarket::GetGarbage() {
    return m_iGarbage;
}

const int C_ResourceMarket::GetGarbage() const {
    return m_iGarbage;
}

void C_ResourceMarket::SellGarbage() {
    m_iGarbage--;
    Notify();
}

int C_ResourceMarket::GetUranium() {
    return m_iUranium;
}

const int C_ResourceMarket::GetUranium() const {
    return m_iUranium;
}

void C_ResourceMarket::SellUranium() {
    m_iUranium--;
    Notify();
}

int C_ResourceMarket::GetCostOfCoal() {
    return (int)(9 - (m_iCoal + 2) / 3);
}

const int C_ResourceMarket::GetCostOfCoal() const {
    return (int)(9 - (m_iCoal + 2) / 3);
}

int C_ResourceMarket::GetCostOfOil() {
    return (int)(9 - (m_iOil + 2) / 3);
}

const int C_ResourceMarket::GetCostOfOil() const {
    return (int)(9 - (m_iOil + 2) / 3);
}

int C_ResourceMarket::GetCostOfGarbage() {
    return (int)(9 - (m_iGarbage + 2) / 3);
}

const int C_ResourceMarket::GetCostOfGarbage() const {
    return (int)(9 - (m_iGarbage + 2) / 3);
}

int C_ResourceMarket::GetCostOfUranium() {
    return (int)(18 - m_iUranium * 2);
}

const int C_ResourceMarket::GetCostOfUranium() const {
    return (int)(18 - m_iUranium * 2);
}

void C_ResourceMarket::SetResources(int coal, int oil, int garbage, int uranium) {
    m_iCoal = coal;
    m_iOil = oil;
    m_iGarbage = garbage;
    m_iUranium = uranium;
}

void C_ResourceMarket::ResetResources() {
    m_iCoal = STARTING_COAL;
    m_iOil = STARTING_OIL;
    m_iGarbage = STARTING_GARBAGE;
    m_iUranium = STARTING_URANIUM;
}
