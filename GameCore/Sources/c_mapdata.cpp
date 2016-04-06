#include "c_mapdata.h"

C_MapData::C_MapData() {

}

C_MapData::~C_MapData() {

}


void C_MapData::LoadMap(std::string path) {
    pugi::xml_document doc;
    doc.load_file("map_canada.xml");
    pugi::xml_node root = doc.child("map");

    for (pugi::xml_node city = root.first_child(); city; city = city.next_sibling()) {
        m_vCities.push_back(new C_CityData(
            XMLParseString(city.attribute("name")),
            XMLParseString(city.attribute("region"))
            ));

        for (pugi::xml_node neighbour = city.first_child(); neighbour; neighbour = neighbour.next_sibling()) {
            m_vCities.back()->AddNeighbour(
                XMLParseString(neighbour.attribute("name")),
                XMLParseInt(neighbour.attribute("cost"))
                );
        }
    }
}


void C_MapData::Serialize(pugi::xml_node &parent) {
    //ANDRES: serialisation goes here when we decide
    //to write it
}

C_CityData* C_MapData::GetCityByName(std::string name) {
    for (int i = 0; i < m_vCities.size(); i++) {
        if (std::strcmp(m_vCities[i]->GetName().c_str(), name.c_str()) == 0)
            return m_vCities[i];
    }
}

std::vector<C_CityData*>* C_MapData::GetCities() {
    return &m_vCities;
}

