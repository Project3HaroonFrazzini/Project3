// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Inventory.h
#ifndef MONSTER_H
#define MONSTER_H
#include <vector>
#include <iostream>
#include "Inventory.h"

using namespace std;

class Monster
{

    private:
    string name;
    int rating;

    public:
    string getName();
    int getRating();
    Monster();
    Monster(int);

    bool attack(Inventory);
    Inventory battle(Inventory current);
    Inventory surrender(Inventory current);
    
    
};
#endif