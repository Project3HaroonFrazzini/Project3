// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Inventory.cpp

#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

    //vector<int> treasure[5];
}

void Inventory::printInventory(){
    string menu = "|-------------|\n|  INVENTORY  |\n|-------------|";
    string gold_print = "|  Gold       | " + to_string(gold);
    string cookware =   "|  Cookware   | P: " + to_string(ceramic_pot) + " |  F: " + to_string(frying_pan) + " |  C: " + to_string(couldron) + " |";
    string weapons =    "|  Weapons    | C: " + to_string(club) + " |  S: " + to_string(spear) + " |  R: " + to_string(rapier) + " |";
    string armor_print ="|  Armor      | " + to_string(armor);
    string treasures =  "|  Treasures  | R: " + to_string(treasure[0]) + "";
    cout << menu << endl << gold_print << endl << cookware << endl << weapons << endl << armor_print << endl;
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
    return Armor;
}
void Inventory::setArmor(int armors){

}
vector<int> Inventory::getWeapons()
{

}
void Inventory::setWeapons(int clubs, int spears, int rapiers, int axes, int swords){

}