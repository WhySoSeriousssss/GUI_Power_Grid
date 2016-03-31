#include "c_housedata.h"

C_HouseData::C_HouseData() :
    city(NULL){

}

C_HouseData::C_HouseData(C_CityData* city) :
    city(city) {
    city->IncreaseCount();
}

C_HouseData::~C_HouseData() {
    delete city;
    city = NULL;
}

C_CityData* C_HouseData::GetCity() {
    return city;
}

const C_CityData* C_HouseData::GetCity() const{
    return city;
}
