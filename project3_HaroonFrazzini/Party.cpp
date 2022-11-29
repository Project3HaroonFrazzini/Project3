// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Party.cpp

#include "Party.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>   

using namespace std;

Party::Party()
{
    vector <string> names = {};
    vector <int> fullnessValues = {};
}
Party:: Party getFullness(int index)
{
    return fullnessValues[index];
}
string Party:: getName(int index)
{
    return names[index];
}
void Party:: setName(int index, string name)
{
    names[index] = name;
}