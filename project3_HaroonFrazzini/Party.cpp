// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Party.cpp

#include "Party.h"
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>   
#include <vector>

using namespace std;

Party::Party()
{
    names = {"","","","",""};
    fullnessValues = {0,0,0,0,0};
    anger = 0;
    Inventory inv = Inventory();
    keys = 0;
    roomsCleared = 0;
}
int Party::getFullness(int index)
{
    return fullnessValues[index];
}
string Party::getName(int index)
{
    return names[index];
}
void Party::setName(int index, string name)
{
    names[index] = name;
}
int Party:: getKeys()
{
    return keys;
}
int Party:: getroomsCleared()
{
    return roomsCleared;
}
int Party:: getAnger()
{
    return anger;
}
void Party:: StatusUpdate(Inventory inv)
{
    cout << "+-------------+\n|      STATUS      |\n+-------------+\n";
    cout << "| Rooms Cleared: " << getroomsCleared() << " | Keys: " << getKeys() << " | Sorcerer Anger\n"  << "+-------------+" << endl;
    inv.printInventory();
    cout << "+------Party------+" << endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "| " <<getName(i) << " | " << getFullness(i) << endl;
    }
    cout << "+-------------+";
}
void Party:: ActionMenu()
{
    int choice = 0;
    cout << "Choose an option" << endl;
    do
    {
    switch (choice)
    {
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        while(!(choice > 0))
        {
        cout << "Please enter a valid input" << endl;
        }
        break;
    }
    }
    while(choice != 5);
}