// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Party.h
#ifndef PARTY_H
#define PARTY_H
#include <vector>
#include <iostream>

class Party
{
    private:
    vector <int> fullnessValues[5];
    string <vector> names[5];

    public:
    int getFullness(int);
    void setName(int, string)
    string getName(int);
    Party();

};
#endif