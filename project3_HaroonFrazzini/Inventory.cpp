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
    lives = {true,true,true,true,true};
    gold = 100;
    keys = 0;

    ingredients = 0;
    cookware = {0,0,0};
    armor = 0;
    weapons = {0,0,0,0,0};
    treasures = {0,0,0,0,0};
}

/*
Print out the current inventory in the format provided, printing the gold, cookware, weapon, armor, and treasure
Void function since it prints and thats it
*/

void Inventory::printInventory(){
    string menu = "|-------------|\n|  INVENTORY  |\n|-------------|";
    string gold_print     =   "|  Gold       | " + to_string(gold);
    string cookware_print =   "|  Cookware   | P: " + to_string(cookware[0]) + " |  F: " + to_string(cookware[1]) + " |  C: " + to_string(cookware[2]) + " |";
    string weapon       =     "|  Weapons    | C: " + to_string(weapons[0]) + " |  S: " + to_string(weapons[1]) + " |  R: " + to_string(weapons[2]) + " | B: " + to_string(weapons[3]) + " | L: " + to_string(weapons[4]) + " |";
    string armor_print    =   "|  Armor      | " + to_string(armor);
    string treasure =        "|  Treasures  | R: " + to_string(treasures[0]) + " |  N: " + to_string(treasures[1]) + " |  B: " + to_string(treasures[2]) + " | C: " + to_string(treasures[3]) + " | G: " + to_string(treasures[4]) + " |";
    cout << menu << endl << gold_print << endl << cookware_print << endl << weapon << endl << armor_print << endl << treasure << endl;
}


/*
Getter function that returns the lives vector, not at an index becuase you need to loop through the lives
*/
vector<bool> Inventory::getLives(){
    return lives;
}

/*
Setter function that sets lives
*/
void Inventory::setLives(int index){
    lives[index] = false;
}
/*
Getter function that removes lives
*/
void Inventory::removeLives(int index){
    lives.erase(lives.begin() + index);
}

/*
Getter function that gets gold
*/
int Inventory::getGold(){
    return gold;
}

/*
Setter function that sets Gold
*/
void Inventory::setGold(int new_gold){
    gold = new_gold;
}

/*
Getter function that gets keys
*/
int Inventory::getKeys(){
    return keys;
}

/*
Setter function that sets keys
*/
void Inventory::setKeys(int new_keys){
    keys = new_keys;
}

/*
Getter function that getes ingredients
*/
int Inventory::getIngredients()
{
    return ingredients;
}

/*
Setter function that sets ingredients
*/
void Inventory::setIngredients(int ingred)
{
    ingredients = ingred;
}

/*
Getter function that gets cookware
*/
int Inventory::getCookware(int cookIndex)
{
    return cookware[cookIndex];
}

/*
Setter function that sets cookware
*/
void Inventory::setCookware(int cookAmt, int cookIndex)
{
    cookware[cookIndex] += cookAmt;
}

/*
Getter function that gets armor
*/
int Inventory::getArmor()
{
    return armor;
}

/*
Setter function that sets armor
*/
void Inventory::setArmor(int armors){
    armor = armors;
}

/*
Getter function that sets weapons
*/
int Inventory::getWeapons(int weaponIndex)
{
    return weapons[weaponIndex];
}

/*
Setter function that sets weapons
*/
void Inventory::setWeapons(int weaponAmt, int weaponIndex){
    weapons[weaponIndex] = weapons[weaponIndex] + weaponAmt;
}

/*
Setter function that sets treasure
*/
void Inventory::setTreasures(int treasureAmt, int treasureIndex){
    treasures[treasureIndex] = treasureAmt;
}

/*
Getter function that gets treasure
*/
int Inventory::getTreasures(int treasureIndex){
    return treasures[treasureIndex];
}