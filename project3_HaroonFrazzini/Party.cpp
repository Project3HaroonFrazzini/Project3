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
    vector <string> names = {"","","","",""};
    vector <int> fullnessValues = {0,0,0,0,0};
    anger = 0;
    Inventory inv = Inventory();
    keys = 0;
    roomsCleared = 0;
}
int Party::getFullness(int index)
{
    int toReturn;
    toReturn = fullnessValues[index];
    return toReturn;
}
string Party::getName(int index)
{
    return names[index];
}
void Party::setName(int index, string name)
{
    names[index] = name;
}
void Party:: StatusUpdate(Inventory inv)
{
    cout << "+-------------+\n| STATUS      |\n+-------------+\n";
    inv.printInventory();
    cout << "\n +------Party------+" << endl;
    for(int i = 0; i <= 5; i++)
    {
        //cout << names[i] << " | " << fullnessValues[i] << endl;
    }
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