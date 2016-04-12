#ifndef C_PLAYERDATA_H
#define C_PLAYERDATA_H

#include "base.h"
#include "C_CardData.h"
#include "C_HouseData.h"

// Common
#include "i_subject.h"

enum GenerateResults_e {
    GENERATE_NOT_ENOUGH_FUEL,
    GENERATE_SUCCEED
};

class C_PlayerData : I_Subject {
public:
    C_PlayerData();
    C_PlayerData(string name);
    C_PlayerData(std::string name, int money, int coal, int oil, int garbage, int uranium, std::vector<C_CardData *> cards, std::vector<C_HouseData *> houses);
    ~C_PlayerData();

    string GetName();
    const string GetName() const;

    int GetMoney();
    const int GetMoney() const;

    int GetCoal();
    const int GetCoal() const;

    int GetOil();
    const int GetOil() const;

    int GetGarbage();
    const int GetGarbage() const;

    int GetUranium();
    const int GetUranium() const;

    int GetMaxCoal();
    const int GetMaxCoal() const;

    int GetMaxOil();
    const int GetMaxOil() const;

    int GetMaxGarbage();
    const int GetMaxGarbage() const;

    int GetMaxUranium();
    const int GetMaxUranium() const;

    void BuyCoal();
    void BuyOil();
    void BuyGarbage();
    void BuyUranium();

    std::vector<C_HouseData *> GetHouse();
    const std::vector<C_HouseData *> GetHouse() const;

    std::vector<C_CardData *> GetCard();
    const std::vector<C_CardData *> GetCard() const;

    bool BuyCard(C_CardData* card);

    bool BuyCity(C_CityData* city);

    void ConsumeMoney(int amount);

    GenerateResults_e GenerateElectricity(int cardNum);

    int GetIncome();

    void Serialize(pugi::xml_node &parent);

private:
    string m_sName;

    int m_iMoney;
    int m_iCoal;
    int m_iOil;
    int m_iGarbage;
    int m_iUranium;

    //The max amount of resoures a player can buy
    int m_iMaxCoal;
    int m_iMaxOil;
    int m_iMaxGarbage;
    int m_iMaxUranium;

    int m_iNumberOfCitiesPoweredThisTurn;

    std::vector<C_CardData *> m_vCard;
    std::vector<C_HouseData *> m_vHouse;
};

#endif // C_PLAYERDATA_H
