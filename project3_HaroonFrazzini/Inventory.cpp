// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Inventory.cpp

#include "inventory.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// sadlsadl
Inventory::Inventory(){
    gold = 100;

    ingredients = 0;
    ceramic_pot = 0;
    frying_pan = 0;
    couldron = 0;

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
    string gold_print = "|  Gold       | " + to_string(gold);
    string cookware =   "|  Cookware   | P: " + to_string(ceramic_pot) + " |  F: " + to_string(frying_pan) + " |  C: " + to_string(couldron) + " |";
    string weapon =     "|  Weapons    | C: " + to_string(weapons[0]) + " |  S: " + to_string(weapons[1]) + " |  R: " + to_string(weapons[2]) + " | B: " + to_string(weapons[3]) + " | L: " + to_string(weapons[4]) + " |";
    string armor_print ="|  Armor      | " + to_string(armor);
    string treasures =  "|  Treasures  | R: " ; //to_string(treasure[0]) + "";
    cout << menu << endl << gold_print << endl << cookware << endl << weapon << endl << armor_print << endl;
}

int Inventory::getIngredients()
{
    return ingredients;
}
void Inventory::setIngredients(int ingredients)
{

}

vector<int> Inventory::getCookware()
{

}
void Inventory::setCookware(int pots, int pans, int could)
{

}

int Inventory::getArmor()
{
    //return Armor;
}
void Inventory::setArmor(int armors){

}
vector<int> Inventory::getWeapons()
{

}
void Inventory::setWeapons(int weaponAmt, int weaponIndex){
    weapons.at(weaponIndex) = weapons.at(weaponIndex) + weaponAmt;
}