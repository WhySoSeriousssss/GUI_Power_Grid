#include "c_carddata.h"

C_CardData::C_CardData() :
    m_iNumber(0),
    m_iResourceCost(0),
    m_iResources(0),
    m_iNumberOfCitiesPowered(0) {

}

C_CardData::C_CardData(int number, int cost, int resources, int poweres) :
    m_iNumber(number),
    m_iResourceCost(cost),
    m_iResources(resources),
    m_iNumberOfCitiesPowered(poweres) {

}

C_CardData::~C_CardData() {

}

int C_CardData::GetNumber() {
    return this->m_iNumber;
}

const int C_CardData::GetNumber() const {
    return this->m_iNumber;
}

int C_CardData::GetCost() {
    return this->m_iResourceCost;
}

const int C_CardData::GetCost() const {
    return this->m_iResourceCost;
}

int C_CardData::GetResources() {
    return this->m_iResources;
}

const int C_CardData::GetResources() const {
    return this->m_iResources;
}

int C_CardData::GetCitiesPowered() {
    return this->m_iNumberOfCitiesPowered;
}

const int C_CardData::GetCitiesPowered() const {
    return this->m_iNumberOfCitiesPowered;
}

void C_CardData::Print() {
    std::cout << "Number: " << m_iNumber << "\n";
    std::cout << "Cost: " << m_iResourceCost << "\n";
    std::cout << "Resource: " << m_iResources << "\n";
    std::cout << "Powers: " << m_iNumberOfCitiesPowered << "\n";
    std::cout << "----------------------\n";
}
