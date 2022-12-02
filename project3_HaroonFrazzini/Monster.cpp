// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Monster.cpp

#include "Monster.h"
#include "Inventory.h"
#include "resources.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>   // for the rand() function
#include <time.h>  
#include <cstring> 


using namespace std;

/*
Default constructor that sets the monster rating to 1 and sets the name variable to an empty string
*/
Monster::Monster()
{
    name = "";
    rating = 1;
}
Monster::Monster(int new_rating)
{
    name = "";
    rating = new_rating+1;
}
/*
Get a random named monster from the file that is the right challenge rating as the number of roomes cleared
Go through all of the lines of the file and check which ones have the correct challenge rating
If the monster is the right challenge rating then add it to a vector
Randomly choose one of the monster names out of the vector and return it
Use this in battle function when getting the name of the monster the player is fighting
*/
string Monster::getName()
{
    ifstream data("monsters.txt");
    vector<string> names;
    string lines[2];
    string line = "";
    srand(time(0));
    
    while(!data.eof()){
        getline(data,line);
        split(line,',',lines,2);

        if(lines[1] == to_string(rating) && checkNames(lines[0])){
            names.push_back(lines[0]);
        }
    }

    int random = rand() % names.size();
    return names[random];
}

/*
Return the private variable rating that is currently being used
*/
int Monster:: getRating()
{
    srand(time(0));
    return rating;
    
}

/*
The main monster class is the battle class that takes an inventory and returns the same ivnentory with changes in the number of items
Start by getting the name of the monster using the getName function and the private variable for how many rooms have been cleared
Figure out the the total number of weapons the party has, sicne the party must surrender if they have no weapons
If the party has weapons then ask them if they want to fight or surrender
if they want to fight run the attack function, if they win alter the gold and ingredients accordingly
if they lose call the surrender function as losing is the same as surrendering
*/
Inventory Monster::battle(Inventory current){
    int num = 0;
    string name = getName();
    
    cout << name << " AHEAD! THEY LOOK HOSTILE!!" <<endl;
    int totWeapons = current.getWeapons(0) + current.getWeapons(1) + current.getWeapons(2) + current.getWeapons(3) + current.getWeapons(5);
    if(totWeapons > 0){
        do{
        cout << "What would you like to do? Choose an option:\n1. Fight the monster\n2. Surrender" <<endl;
        cin >> num;
        if(num == 1){
            bool result = attack(current);
            if(result){
                cout << "You won the battle!" <<endl;
                cout << "You received " << 10*rating << " gold and " << 5*rating << " ingredients.";
                current.setGold(current.getGold() + 10*rating);
                current.setIngredients(current.getIngredients() + 5*rating);
                srand(time(0));
                int random_num = rand()% 100+1;
                if(random_num <=10){
                    cout << "\nThe monster dropped a key!" << endl;
                    current.setKeys(current.getKeys() + 1);
                }
                else{
                    cout << " The monster did not drop a key." <<endl;
                }
                used_names.push_back(name);
            }
            else{
                cout << "The " << name << " defeated you in battle" <<endl;
                current = surrender(current);
            }

        }
        else if(num == 2){
            cout << "You surrender to the " << name <<endl;
            current = surrender(current);
        }
        else{
            cout << "Invalid input." <<endl;
        }
        }while(num != 1 && num != 2);

    }
    else{
        cout << "You don't have any weapons! You must Surrender. Type anything to continue." <<endl;
        cin >> num;

    }
    return current;
}

/*
The attack class is the class that uses the attack algorithm given in order to figure out if the party wins the battle or not
set the w,d,a,c variables according to the items in the inventory that is passed to the function
create to random numbers between 1 and 6 
use the equation to figure out if the battle is won ( >0) or lost (<0)
return true if its won, return false if its lost
*/
bool Monster::attack(Inventory current){
    int w = (current.getWeapons(0) + current.getWeapons(1) + current.getWeapons(2) + current.getWeapons(3) + current.getWeapons(5)) + 1*(current.getWeapons(2)) + 2*(current.getWeapons(3)) + 3*(current.getWeapons(5));
    int d = 0;
    if(current.getWeapons(0) != 0 && current.getWeapons(1) != 0 && current.getWeapons(2) != 0 && current.getWeapons(3) != 0 && current.getWeapons(4) != 0){
        d = 4;
    }
    int a = current.getArmor();
    if( a > 5){
        a = 5;
    }
    else if(a == 0){
        a = 1;
    }
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

/*
The surrender function is what happens if the party chooses to surrender or if they lose
The function takes the current inventory and alters it according to the rules of losing a battle
This includes losing 25% of your gold, up to 30 ingredients, and possibly dying
If a player does die alter the lives vector in the inventory so that it can be seen in the party class]
Use the number of pieces of armor to alter the staticists ( 10% without armor, 5% with) of death
return the updated inventory
*/
Inventory Monster::surrender(Inventory current){
    int random = 0;
    cout << "You lost " << current.getGold() - current.getGold()*.75 << " gold and ";
    current.setGold(int(current.getGold()*.75));
    if(current.getIngredients() > 30){
        current.setIngredients(current.getIngredients() -30);
        cout << 30 << " ingredients." <<endl;
    } 
    else{
        cout << current.getIngredients() << " ingredients." <<endl;
        current.setIngredients(0);
    }
    //cout << "So far so good" << current.getLives().size() << endl;
    for(int i = current.getLives().size()-1; i > 0; i--){
        random = rand() % 100 + 1;
        if(current.getArmor() >= i){
            if(random <= 5){
                current.setLives(i);
                current.setArmor(current.getArmor() -1);
            }
        }
        else{
            if(random <= 10){
                current.setLives(i);
                current.setArmor(current.getArmor() -1);
            }
        }
    }

    return current;
}

/*
Return the name of the monster
*/
string Monster::getMonster(){
    string name = "";
    return name;
}

/*
In order to avoid fighting the same monster twice, make sure that the monster 
*/
bool Monster::checkNames(string name){
    for(int i = 0; i < used_names.size();i++){
        if(name == used_names[i]){
            return false;
        }
    }
    return true;
}