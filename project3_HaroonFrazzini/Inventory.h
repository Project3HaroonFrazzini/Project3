// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei___Recitation 101 - Morgan Byers
// Project 3 Inventory.h

#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>

using namespace std;
//help 
class Inventory{

    private:
    int gold;
    int keys;

    int ingredients;
    vector<int> cookware;
    int armor;
    vector<int> weapons;
    vector<int> treasures;
    
    public:
    
    Inventory();

    void printInventory();

    int getGold();
    void setGold(int);

    int getKeys();
    void setKeys(int);

    int getIngredients();
    void setIngredients(int ingredients);

    int getCookware(int);
    void setCookware(int cookAmt, int cookIndex);

    int getArmor();
    void setArmor(int armors);

    int getWeapons(int weaponIndex);
    void setWeapons(int weaponAmt, int weaponIndex);

    void setTreasures(int treasureAmt, int treasureIndex);
    int getTreasures(int treasureIndex);
};

#endif
