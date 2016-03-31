#ifndef C_CITYDATA_H
#define C_CITYDATA_H

#include "base.h"

class C_CityData {
public:
    C_CityData(std::string name, std::string region);
    ~C_CityData();

    string GetName();
    const string GetName() const;

    string GetRegion();
    const string GetRegion() const;

    string GetNeighbours();

    void AddNeighbour(std::string name, int cost);

    void IncreaseCount();

    int GetCost();

private:
    string m_sName;
    string m_sRegion;

    // The number of players who have houses in this city
    int m_iCountHouses;

    std::unordered_map<string, int> m_vConnections;
};

#endif // C_CITYDATA_H
