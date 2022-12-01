// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Merchant.h
#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include "Inventory.h"

class Merchant
{
    private:
    int priceMultiplier;
    public:

    Merchant();
    Merchant(int);

    Inventory menu(Inventory);

    Inventory buyIngredients(Inventory);
    Inventory buyCookware(Inventory);
    Inventory buyWeapons(Inventory);
    Inventory buyArmor(Inventory);
    Inventory sellTreasures(Inventory); 
};
#endif