#include "c_citydata.h"

C_CityData::C_CityData(std::string name, std::string region) :
    m_sName(name),
    m_sRegion(region),
    m_iCountHouses(0) {

}

C_CityData::~C_CityData() {

}

string C_CityData::GetName() {
    return m_sName;
}

const string C_CityData::GetName() const {
    return m_sName;
}

string C_CityData::GetRegion() {
    return m_sRegion;
}

const string C_CityData::GetRegion() const {
    return m_sRegion;
}

string C_CityData::GetNeighbours() {
    string neighbours = "";
    for (auto &i : m_vConnections) {
        neighbours = neighbours + i.first + ", ";
    }
    return neighbours;
}

void C_CityData::AddNeighbour(std::string name, int cost) {
    m_vConnections.insert({ name, cost });
}

void C_CityData::IncreaseCount() {
    m_iCountHouses++;
}

int C_CityData::GetCost() {
    return (10 + m_iCountHouses * 5);
}
