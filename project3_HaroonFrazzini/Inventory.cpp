// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Inventory.cpp

#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Inventory::Inventory(){
    gold = 100;

    ingredients = 0;
    ceramic_pot = 0;
    frying_pan = 0;
    couldron = 0;
    cookware = {0,0,0};

    armor = 0;

    club = 0;
    spear = 0;
    rapier = 0;
    battle_axe = 0;
    longsword = 0;
    vector<int> weapons {0,0,0,0,0};
    vector<int> treasure {0,0,0,0,0};
}


void Inventory::printInventory(){
    string menu = "|-------------|\n|  INVENTORY  |\n|-------------|";
    string gold_print     =   "|  Gold       | " + to_string(gold);
    string cookware_print =   "|  Cookware   | P: " + to_string(cookware[0]) + " |  F: " + to_string(cookware[1]) + " |  C: " + to_string(cookware[2]) + " |";
    string weapon       =     "|  Weapons    | C: " + to_string(weapons[0]) + " |  S: " + to_string(weapons[1]) + " |  R: " + to_string(weapons[2]) + " | B: " + to_string(weapons[3]) + " | L: " + to_string(weapons[4]) + " |";
    string armor_print    =   "|  Armor      | " + to_string(armor);
    string treasures =        "|  Treasures  | R: " ; //to_string(treasure[0]) + "";
    cout << menu << endl << gold_print << endl << cookware_print << endl << weapon << endl << armor_print << endl;
}

int Inventory::getGold(){
    return gold;
}

int Inventory::getIngredients()
{
    return ingredients;
}
void Inventory::setIngredients(int ingredients)
{

}

int Inventory::getCookware()
{
    for(int i : cookware){
        cout << i <<endl;
    }
    return 0;
}
void Inventory::setCookware(int cookAmt, int cookIndex)
{

    cout << "Cook Index: " << cookIndex <<endl;
    cout << to_string(cookware.at(0)) << endl;
    //cookware.at(cookIndex) = cookware.at(cookIndex) + cookAmt;
}

int Inventory::getArmor()
{
    return armor;
}
void Inventory::setArmor(int armors){

}
vector<int> Inventory::getWeapons()
{
    return weapons;
}
void Inventory::setWeapons(int weaponAmt, int weaponIndex){
    weapons.at(weaponIndex) = weapons.at(weaponIndex) + weaponAmt;
}