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
void Merchant::buyIngredients()
{

}
void Merchant::buyCookware()
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
void Merchant ::buyWeapons()
{

}
void Merchant::buyArmor()
{

}
void Merchant::sellTreasures()
{

}