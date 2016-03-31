#ifndef C_MAPDATA_H
#define C_MAPDATA_H

#include "c_citydata.h"
#include "i_subject.h"

#include "base.h"

class C_MapData : public I_Subject {
public:
    C_MapData();
    ~C_MapData();

    void LoadMap(std::string path);

 //   void Serialize(pugi::xml_node &parent);
    void AddCity(std::string name, std::string region);
    void DisplayCities();
    C_CityData GetCityByName(std::string name);

private:
    std::vector<C_CityData> m_vCities;
};

#endif // C_MAPDATA_H
