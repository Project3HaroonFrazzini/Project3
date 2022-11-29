// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
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

    int armor;

    int club;
    int spear;
    int rapier;
    int battle_axe;
    int longsword;

    vector<int> treasure[5];
    public:
    
    Inventory();

    void printInventory();

    int getIngredients();
    void setIngredients(int ingredients);

    vector<int> getCookware();
    void setCookware(int pots, int pans, int could);

    int getArmor();
    void setArmor(int armors);

    vector<int> getWeapons();
    void setWeapons(int clubs, int spears, int rapiers, int axes, int swords);

};

#endif