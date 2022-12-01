// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Monster.cpp

#include "Monster.h"
#include "Inventory.h"
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
Monster::Monster(int rating)
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
    srand(time(0));
    
}

Inventory Monster::battle(Inventory current){
    int num = 0;
    string name = getMonster();
    
    cout << "MINOTAUR AHEAD! THEY LOOK HOSTILE!!" <<endl;
    int totWeapons = current.getWeapons(0) + current.getWeapons(1) + current.getWeapons(2) + current.getWeapons(3) + current.getWeapons(5);
    if(totWeapons > 0){
        do{
        cout << "What would you like to do? Choose an option:\n1. Fight the monster\n2.Surrender" <<endl;
        cin >> num;
        if(num == 1){
            bool result = attack(current);
            if(result){
                current.setGold(current.getGold() + 10*rating);
                current.setIngredients(current.getIngredients() + 5*rating);
                srand(time(0));
                int random_num = rand()% 100+1;
                if(random_num <=10){
                    cout << "The monster dropped a key!" << endl;
                    current.setKeys(current.getKeys() + 1);
                }
                removeMonster(name);
            }
            else{

            }
        }
        else if(num == 2){
            current = surrender(current);
        }
        else{
            cout << "Invalid input." <<endl;
        }
        }while(num != 1 || num != 2);

    }
    else{
        cout << "You don't have any weapons! You must Surrender. Type anything to continue." <<endl;
        cin >> num;

    }
    return current;
}

bool Monster::attack(Inventory current){
    int w = (current.getWeapons(0) + current.getWeapons(1) + current.getWeapons(2) + current.getWeapons(3) + current.getWeapons(5)) + 1*(current.getWeapons(2)) + 2*(current.getWeapons(3)) + 3*(current.getWeapons(5));
    int d = 0;
    if(current.getWeapons(0) != 0 && current.getWeapons(1) != 0 && current.getWeapons(2) != 0 && current.getWeapons(3) != 0 && current.getWeapons(4) != 0){
        d = 4;
    }
    int a = current.getArmor();
    int c = rating;
    srand(time(0));
    int r_one = rand() % 6 + 1;
    int r_two = rand() % 6 + 1;
    
    int battle = (r_one * w + d) - ((r_two*c)/a);

    if(battle > 0){
        return true;
    }
    else{
        return false;
    }
}

Inventory Monster::surrender(Inventory current){
    return current;
}

string Monster::getMonster(){
    string name = "";
    return name;
}

void Monster::removeMonster(string name){
    return;
}