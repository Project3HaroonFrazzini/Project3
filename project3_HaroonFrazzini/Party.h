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
#include "Monster.h"
#include <vector>

using namespace std;
class Party
{
    private:
    vector <int> fullnessValues;
    vector <string> names;
    int anger;
    Inventory inv;
    Merchant merch;
    Map map;
    int roomsCleared;
    Monster monst;
    bool gameEnd;

    public:
    int getFullness(int);
    void setName(int, string);
    string getName(int);
    void StatusUpdate(Inventory);
    void ActionMenu();
    int getroomsCleared();
    int getAnger();
    void setRoomsCleared(int);
    void setAnger();
    Party();
    int setFullness(int, int);
    Inventory Misfortunes();
    void removeName(int);
    void removeFullness(int);
    void deathFunc(int);
    bool doorPuzzle();
    void Cook();
    int getNamesSize();
    int getFullnessValuesSize();
    bool NPCPuzzle();
    void setMap();
    int getRandomRow(int);
    int getRandomCol(int);
    void displayPartyMap();
    void createGame();

};
#endif