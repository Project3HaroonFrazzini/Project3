// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Party.cpp

#include "Party.h"
#include "Inventory.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>   
#include <vector>

using namespace std;

Party::Party()
{
    names = {"","","","",""};
    fullnessValues = {0,0,0,0,0};
    anger = 0;
    Inventory inv = Inventory();
    keys = 0;
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
int Party:: getKeys()
{
    return keys;
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
Inventory Party:: Misfortunes()
{
    srand(time(0));
    int rand = rand()%100 + 1;
    if(rand <= 40)
    {
        rand = rand()%100 + 1;
        if(rand <= 30)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
            rand = rand()%3+ 1;
            if(rand == 1)
            {
                cout << "You lost 10 ingredients!!!!" << endl;
                inv.setIngredients(inv.getIngredients()-10);
            }
            else if(rand == 2)
            {
                rand = rand()%3 + 1;
                if(rand == 1)
                {
                    inv.setCookware(getCookWare(0)-1,0);
                }
                else if(rand == 2)
                {
                    inv.setCookware(getCookWare(1)-1,1);
                }
                else
                {
                    inv.setCookware(getCookWare(2)-1,2);
                }
            }
            else
            {
                inv.setArmor(inv.getArmor()-1);
            }

        }
        else if(rand <= 40)
        {
            rand = rand()%2 + 1;
            //weapons
            if(rand == 1)
            {
                rand = rand()%5;
                // tryna go through weapons array and if i = the rand value, remove weapons[i]
                for(int i = 0; i < 4 )
                {
                    if(i == rand)
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
        else if(rand <= 70)
        {
            //Food poisoning: One party member got food poisoning, causing them to lose 10 points of hunger. If this causes them to reach zero fullness, they die of
            // hunger immediately.
            rand = rand()%5;
            for(int i = 0; i < 5)
            {
                if(i == rand)
                {
                    setFullness(getFullness(i)-1,i);
                    if(getFullness(1) <= 0)
                    {
                        //dude is dead
                        names.remove(i);
                        fullnessValues.remove(i);
                    }
                }
            }
        }
        else
        {

        }
    }

}
void Party:: StatusUpdate(Inventory inv)
{
    cout << "+-------------+\n|      STATUS      |\n+-------------+\n";
    cout << "| Rooms Cleared: " << getroomsCleared() << " | Keys: " << getKeys() << " | Sorcerer Anger\n"  << "+-------------+" << endl;
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
    if((map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol()) == false) && map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()) == false)
    {
        cout << "Choose an option" << endl;
        cin >> choice;
        do
        {
            switch (choice)
            {
                case 1:
                    char direction;
                    cout << " Choose a direction to move" << endl;
                    cin >> direction;
                    map.move(direction);
                    for(int i = 0; i < 5; i++)
                    {
                        int randFullnessChance = rand() % 100 + 1;
                        if(randFullnessChance <= 20)
                        {
                            setFullness(getFullness(i) - 1,i);
                        }
                    }
                    break;
                case 2:
                    break;
                case 3:
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