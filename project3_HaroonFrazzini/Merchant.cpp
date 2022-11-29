// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Merchant.cpp
#include "Merchant.h"
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Merchant:: Merchant()
{
    priceMultiplier = 1;
}
void Merchant::buyIngredients(Inventory current)
{

}
void Merchant::buyCookware(Inventory current)
{
    int num = 0;
    cout << "Choose one of the following:\n1. (25%) Ceramic Pot [2 Gold]\n2. (10%) Frying Pan [10 Gold]\n3. ( 2%) Cauldron [20 Gold]\n4. Cancel";
    cin >> num;
    do
    {
        if(num == 1)
        {

        }
        else if(num == 2)
        {

        }
        else if(num == 3)
        {

        }
        else
        {
            cout << "Invalid input." << endl;
            cout << "Enter a new number" << endl;
            cin >> num;
        }
    } while (num !=4);
    
}
void Merchant ::buyWeapons(Inventory current)
{
    int num = 0;
    int amount = 0;
    do{
    cout << "Ah yes weapons! Very important. Here are all the options I have for sale.\nAnd for some extra gold you can get some special weapons that do extra damage, shown by (+X)" <<endl;
    cout << "Choose one of the following:\n1. Stone Club [2 Gold]\n2. Iron Spear [2 Gold]\n3. (+1) Mythril Rapier [5 Gold]\n4. (+2) Flaming Battle-Axe Rapier [15 Gold]\n5. (+4) Vorpal Long Sword [50 Gold]\n6. Cancel" <<endl;
    cin >> num; 
        if(num == 1)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,0);
        }
        else if(num == 2)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,1);
        }
        else if(num == 3)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,2);
        }
        else if(num == 4)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,3);
        }
        else if(num == 5)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,4); 
        }
        else if (num <= 0 || num >6)
        {
            cout << "Invalid input." << endl;
            cout << "Enter a new number" << endl;
            cin >> num;
        }
    } while (num !=6);
}
void Merchant::buyArmor(Inventory current)
{

}
void Merchant::sellTreasures(Inventory current)
{

}