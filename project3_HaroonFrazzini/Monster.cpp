// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Monster.cpp

#include "Monster.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>   // for the rand() function
#include <time.h>   

using namespace std;

Monster::Monster()
{
    name = "";
    rating = 0;
}
// get a random line from the monsters.txt and get that name
string Monster:: getName()
{
    srand(time(0));

}
// get a random line from the monsters.txt and get that name
int Monster:: getRating()
{

}