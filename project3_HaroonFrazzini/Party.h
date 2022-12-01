// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Party.h
#ifndef PARTY_H
#define PARTY_H
#include <vector>
#include <iostream>
#include "Inventory.h"
#include "Merchant.h"
#include "Map.h"
#include <vector>

class Party
{
    private:
    vector <int> fullnessValues;
    vector <string> names;
    int anger;
    Inventory inv;
    Merchant merch;
    Map map;
    int keys;
    int roomsCleared;

    public:
    int getFullness(int);
    void setName(int, string);
    string getName(int);
    void StatusUpdate(Inventory);
    void ActionMenu();
    int getKeys();
    int getroomsCleared();
    int getAnger();
    Party();
    void MainMenu();

};
#endif