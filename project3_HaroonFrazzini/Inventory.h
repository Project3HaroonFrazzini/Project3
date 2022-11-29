// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei___Recitation 101 - Morgan Byers
// Project 3 Inventory.h

#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>

using namespace std;

class Inventory{

    private:
    int gold;

    int ingredients;
    int ceramic_pot;
    int frying_pan;
    int couldron;
    vector<int> cookware;

    int armor;

    int club;
    int spear;
    int rapier;
    int battle_axe;
    int longsword;
    vector<int> weapons;
    vector<int> treasure;
    public:
    
    Inventory();

    void printInventory();

    int getGold();

    int getIngredients();
    void setIngredients(int ingredients);

    int getCookware();
    void setCookware(int cookAmt, int cookIndex);

    int getArmor();
    void setArmor(int armors);

    vector<int> getWeapons();
    void setWeapons(int weaponAmt, int weaponIndex);

};

#endif
