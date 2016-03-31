#ifndef C_HOUSEDATA_H
#define C_HOUSEDATA_H

#include "c_citydata.h"

class C_HouseData {
public:
    C_HouseData();
    C_HouseData(C_CityData* city);
    ~C_HouseData();

    C_CityData* GetCity();
    const C_CityData* GetCity() const;

private:
    C_CityData* city;
};

#endif // C_HOUSEDATA_H
