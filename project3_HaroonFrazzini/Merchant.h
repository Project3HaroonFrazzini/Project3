// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Merchant.h
#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>

class Merchant
{
    private:
    int priceMultiplier;
    public:

    void buyIngredients(Inventory);
    void buyCookware(Inventory);
    void buyWeapons(Inventory);
    void buyArmor(Inventory);
    void sellTreasures(Inventory); 
};
#endif