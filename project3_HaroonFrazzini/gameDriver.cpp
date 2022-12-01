// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 GameDriver.cpp

#include "Inventory.h"
#include "Party.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    Inventory test = Inventory();

    //test.printInventory();

    Party par = Party();
    //par.getFullness(0);
    par.StatusUpdate(test);
}