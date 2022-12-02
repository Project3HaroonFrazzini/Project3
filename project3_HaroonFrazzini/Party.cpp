// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Party.cpp

#include "Party.h"
#include "Inventory.h"
#include "Map.h"
#include "Monster.h"
#include "Merchant.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>   
#include <vector>

using namespace std;
//int split(string input_string,char separator,string arr[],int arr_size);

Party::Party()
{
    names = {"","","","",""};
    fullnessValues = {0,0,0,0,0};
    anger = 0;
    Inventory inv = Inventory();
    roomsCleared = 0;
    Map map = Map();
}
int Party::getFullness(int index)
{
    return fullnessValues[index];
}
string Party::getName(int index)
{
    return names[index];
}
void Party::setName(int index, string name)
{
    names[index] = name;
}
int Party:: getroomsCleared()
{
    return roomsCleared;
}
int Party:: getAnger()
{
    return anger;
}
int Party:: setFullness(int newFullness, int index)
{
    fullnessValues[index] = newFullness;
    return fullnessValues[index];
}
void Party:: removeName(int index)
{
    names.erase(names.begin()+index);
}
void Party:: removeFullness(int index)
{
    fullnessValues.erase(fullnessValues.begin()+index);
}
void Party:: deathFunc(int index)
{
    cout << "Oh no, party member" << getName(index) << " died!!!!" << endl;
    removeName(index);
    removeFullness(index);
    inv.removeLives(index);
}
int Party:: getNamesSize()
{
    return names.size();
}
Inventory Party:: Misfortunes()
{
    srand(time(0));
    int randum = rand()%100 + 1;
    if(randum <= 40)
    {
        randum = rand()%100 + 1;
        if(randum <= 30)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
            randum = rand()%3+ 1;
            if(randum == 1)
            {
                cout << "You lost 10 ingredients!!!!" << endl;
                inv.setIngredients(inv.getIngredients()-10);
            }
            else if(randum == 2)
            {
                randum = rand()%3 + 1;
                if(randum == 1)
                {
                    inv.setCookware(inv.getCookware(0)-1,0);
                }
                else if(randum == 2)
                {
                    inv.setCookware(inv.getCookware(1)-1,1);
                }
                else
                {
                    inv.setCookware(inv.getCookware(2)-1,2);
                }
            }
            else
            {
                inv.setArmor(inv.getArmor()-1);
            }

        }
        else if(randum <= 40)
        {
            randum = rand()%2 + 1;
            //weapons
            if(randum == 1)
            {
                randum = rand()%5;
                // tryna go through weapons array and if i = the rand value, remove weapons[i]
                for(int i = 0; i < 4; i++)
                {
                    if(i == randum)
                    {
                        cout << "Your weapon at index (add index here) broke" << endl;
                        inv.setWeapons(inv.getWeapons(i)-1,i);
                    }
                }
            }
            //remove random armor
            else
            {
                cout << "Your armor broke" << endl;
                inv.setArmor(inv.getArmor()-1);
            }
        }
        else if(randum <= 70)
        {
            //Food poisoning: One party member got food poisoning, causing them to lose 10 points of hunger. If this causes them to reach zero fullness, they die of
            // hunger immediately.
            randum = rand()%5;
            for(int i = 0; i < 5;i++)
            {
                if(i == randum)
                {
                    setFullness(getFullness(i)-1,i);
                    if(getFullness(1) <= 0)
                    {
                        //dude is dead
                        removeName(i);
                        removeFullness(i);
                    }
                }
            }
        }
        else if((map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()) == true) && (inv.getKeys() == 0))
        {
            randum = rand()%4 + 1;
            for(int i = 1; i <= 4; i++)
            {
                if(i == randum)
                {
                    deathFunc(i);
                }
            }
        }
    }

}
void Party:: Cook()
{
    srand(time(0));
    char choice;
    int ingredientsUsed;
    int meals = 0;
    int randum;
    if(inv.getIngredients() < 5)
    {
        cout << "You don't have enough ingredients to cook!" << endl;
        return;
    }
    cout << "How many ingredients do you want to use?" << endl;
    cin >> ingredientsUsed;
    while(ingredientsUsed > inv.getIngredients())
    {
        cout << "You do not have that many ingredients!" << endl;
        cout << "How many ingredients do you want to use?" << endl; 
    }
    cout << "What cookware do you want to use?\n | 1. Ceramic Pot (P)\n | 2. Frying Pan (F)\n | 3. Cauldron (C)" << endl;
    cin >> choice;
    while(choice != 'P' || choice != 'F' || choice != 'C')
    {
        cout << "Invalid input" << endl;
        cout << "What cookware do you want to use?\n | 1. Ceramic Pot (P)\n | 2. Frying Pan (F)\n | 3. Cauldron (C)" << endl;
        cin  >> choice;
    }
    if(choice == 'P')
    {
        randum = rand()%100 + 1;
        if(randum <= 25)
        {
            inv.setIngredients(inv.getIngredients()-ingredientsUsed);
            inv.setCookware(inv.getCookware(0) - 1, 0);
        }
        else
        {
            meals = ingredientsUsed/getNamesSize();
        }
    }

    else if(choice == 'F')
    {

    }
    else
    {

    }
}
void Party:: StatusUpdate(Inventory inv)
{
    cout << "+-------------+\n|      STATUS      |\n+-------------+\n";
    cout << "| Rooms Cleared: " << getroomsCleared() << " | Keys: " << inv.getKeys() << " | Sorcerer Anger\n"  << "+-------------+" << endl;
    inv.printInventory();
    cout << "+------Party------+" << endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "| " <<getName(i) << " | " << getFullness(i) << endl;
    }
    cout << "+-------------+";
}
void Party:: ActionMenu()
{
    srand(time(0));
    //rand()%100 + 1;
    int choice = 0;
    int randum;
    Monster monst = Monster(roomsCleared);
    if((map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol()) == false) && map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()) == false)
    {
        do
        {
            cout << "Choose an option" << endl;
            cin >> choice;
            switch(choice)
            {
                case 1:
                    char direction;
                    cout << " Choose a direction to move" << endl;
                    cin >> direction;
                    if(map.move(direction)){
                        for(int i = 0; i < 5; i++)
                        {
                            int randFullnessChance = rand() % 100 + 1;
                            if(randFullnessChance <= 20)
                            {
                                setFullness(getFullness(i) - 1,i);
                            }
                        }
                    }
                    break;
                case 2:
                    if(map.isExplored(map.getPlayerRow(),map.getPlayerCol()))
                    {
                        randum = rand()%100 + 1;
                        // player finds a key
                        if(randum <= 10)
                        {
                            cout << "You found a key cuh!" << endl;
                            inv.setKeys(inv.getKeys()+1);
                        }
                        // player finds a treasure
                        else if(randum <= 20)
                        {
                            cout << "You found a treasure" << endl;
                            merch.setPrice(roomsCleared);
                        }
                        // player fights a random monster
                        else if(randum <= 40)
                        {
                            monst.battle(inv);
                        }
                    }
                    else
                    {
                        cout << "This space cannot be explored" << endl;
                        break;
                    }
                    break;
                case 3:
                    inv = monst.battle(inv);
                    for(int i = 0; i < inv.getLives().size(); i++)
                    {
                        if(inv.getLives()[i] == false)
                        {
                            deathFunc(i);
                        }
                    }
                    break;
                case 4:
                    break;
                default:
                    while((choice < 0))
                    {
                    cout << "Please enter a valid input" << endl;
                    }
                    break;
            }
        }
        while(choice != 5);
        cout << "sorry that u lost!!" << endl;
    }
    else
    {
        do
        {

        }
        while( 1 != 1);
    }
}
void Party:: MainMenu()
{
    StatusUpdate(inv);
    map.displayMap();
    ActionMenu();
}

bool Party::doorPuzzle(){
    int strikes = 0;
    bool answered = false;
    string answer = "";

    srand(time(0));
    do{
    int door = rand() % 3 + 1; // 1 = Boulder, 2 = Parchment, 3 = Shears
    cout << "Choose one of the following: (B) Boulder, (P) Parchment, (S) Shears." <<endl;
    cin >> answer;
    if(answer == "B"){
        //answered = true;
        if(door == 1){
            cout << "I choose Boulder!" <<endl;
            cout << "Uh oh, we tied! Let's play again." <<endl;
        }
        else if(door == 2){
            cout << "I choose Parchment!" << endl;
            cout << "HaHa I win! Thats one strike for you" <<endl;
            strikes++;
            cout << "You have " << strikes << " strikes, if you get to 3 strikes you DIE!" <<endl;
        }
        else if (door == 3){
            cout << "I choose Shears!" <<endl;
            cout << "Nooo you won! Rules are rules, you may now enter this room." <<endl; 
            answered = true;
            break;
        }
    }
    else if(answer == "P"){
        if(door == 1){
            cout << "I choose Boulder!" <<endl;
            cout << "Nooo you won! Rules are rules, you may now enter this room." <<endl; 
            answered = true;
            break;
        }
        else if(door == 2){
            cout << "I choose Parchment!" << endl;
            cout << "Uh oh, we tied! Let's play again." <<endl;
        }
        else if (door == 3){
            cout << "I choose Shears!" <<endl;
            cout << "HaHa I win! Thats one strike for you" <<endl;
            strikes++;
            cout << "You have " << strikes << " strikes, if you get to 3 strikes you DIE!" <<endl;
        }
    }
    else if(answer == "S"){
        if(door == 1){
            cout << "I choose Boulder!" <<endl;
            cout << "HaHa I win! Thats one strike for you" <<endl;
            strikes++;
            cout << "You have " << strikes << " strikes, if you get to 3 strikes you DIE!" <<endl;
        }
        else if(door == 2){
            cout << "I choose Parchment!" << endl;
            cout << "Nooo you won! Rules are rules, you may now enter this room." <<endl; 
            answered = true;
            break;
        }
        else if (door == 3){
            cout << "I choose Shears!" <<endl;
            cout << "Uh oh, we tied! Let's play again." <<endl;
        }
    }
    else{
        cout << "Invalid Input." <<endl;
    }
    }while(!answered || strikes != 3);

    if(strikes == 3){
        return false;
    }
    else{
        return true;
    }
}
