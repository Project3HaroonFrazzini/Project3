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
#include <stdio.h>

using namespace std;

Party::Party()
{
    names = {"","","","",""};
    fullnessValues = {50,50,50,50,50};
    anger = 0;
    Inventory inv = Inventory();
    roomsCleared = 0;
    Map map = Map();
    Monster monst = Monster();
    gameEnd = false;

}
int split2(string input_string,char separator,string arr[],int arr_size){
    if(input_string == ""){
        return 0;
    }
    int count = 0;
    for(int i = 0; i < input_string.length(); i++){
        if(input_string[i] == separator){
            arr[count] = input_string.substr(0,i);
            input_string = input_string.substr(i+1);
            count++;
            i = 0;
        }
    }
    arr[count] = (input_string);
    if(count +1 > arr_size){
        return -1;
    }
    return ++count;
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
    sortFunction();
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
void Party:: setAnger()
{
    anger++;
}
void Party:: deathFunc(int index)
{
    cout << "Oh no, party member " << getName(index) << " died!!!!" << endl;
    removeName(index);
    removeFullness(index);
    inv.removeLives(index);
}
int Party:: getNamesSize()
{
    return names.size();
}
int Party:: getFullnessValuesSize()
{
    return fullnessValues.size();
}
void Party:: setRoomsCleared(int amt)
{
    roomsCleared++;
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
    return inv;
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
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
    while(choice != 'P' && choice != 'F' && choice != 'C')
    {
        cout << "Invalid input" << endl;
        cout << "What cookware do you want to use?\n | 1. Ceramic Pot (P)\n | 2. Frying Pan (F)\n | 3. Cauldron (C)" << endl;
        cin  >> choice;
    }
    if(choice == 'P')
    {
        if(inv.getCookware(0) == 0)
        {
            cout << "You do not have any pots!" << endl;
        }
        else{
            randum = rand()%100 + 1;
            if(randum <= 25)
            {
                inv.setIngredients(inv.getIngredients()-ingredientsUsed);
                inv.setCookware(inv.getCookware(0) - 1, 0);
                cout << "Your pot broke!" << endl;
            }
            else
            {
                meals = ingredientsUsed/getNamesSize();
                for(int i = 0; i < getFullnessValuesSize();i++)
                {
                    setFullness(getFullness(i) + meals, i);
                }
                cout << "Cook was successfull Mr. White" << endl;
                inv.setIngredients(inv.getIngredients()-ingredientsUsed);
            }
        }
    }
    else if(choice == 'F')
    {
        if(inv.getCookware(1) == 0)
        {
            cout << "You do not have any pans!" << endl;
        }
        else
        {
            randum = rand()%100 + 1;
            if(randum <= 10)
            {
                inv.setIngredients(inv.getIngredients()-ingredientsUsed);
                inv.setCookware(inv.getCookware(1) - 1, 0);
                cout << "Your pan broke!" << endl;
            }
            else
            {
                meals = ingredientsUsed/getNamesSize();
                for(int i = 0; i < getFullnessValuesSize();i++)
                {
                    setFullness(getFullness(i) + meals, i);
                }
                cout << "Cook was successfull Mr. White" << endl;
            }
        }
    }
    else
    {
        if(inv.getCookware(2) == 0)
        {
            cout << "You do not have any cauldrons!" << endl;
        }
        else
        {
            randum = rand()%100 + 1;
            if(randum <= 2)
            {
                inv.setIngredients(inv.getIngredients()-ingredientsUsed);
                inv.setCookware(inv.getCookware(2) - 1, 0);
                cout << "Your cauldron broke!" << endl;
            }
            else
            {
                meals = ingredientsUsed/getNamesSize();
                for(int i = 0; i < getFullnessValuesSize();i++)
                {
                    setFullness(getFullness(i) + meals, i);
                }
                cout << "Cook was successfull Mr. White" << endl;
            }
        }
    }
    for(int i = 0; i < getNamesSize(); i++)
    {
        cout << "| " << getName(i) << " | Fullness " << getFullness(i) << endl;
    }
    cout << "Remaining kg of food: " << inv.getIngredients() << endl;
}
void Party:: StatusUpdate(Inventory inv)
{
    cout << "+-------------+\n|      STATUS      |\n+-------------+\n";
    cout << "| Rooms Cleared: " << getroomsCleared() << " | Keys: " << inv.getKeys() << " | Sorcerer Anger: "  << anger << "\n+-------------+" << endl;
    inv.printInventory();
    cout << "+------Party------+" << endl;
    for(int i = 0; i <= 4; i++)
    {
        cout << "| " <<getName(i) << " | " << getFullness(i) << endl;
    }
    cout << "+-------------+\n";
    displayPartyMap();
}

void Party::sortFunction(){
    int temp_hung = 0;
    string temp_player = "";

    for(int i = 1; i < fullnessValues.size(); i ++){
        for(int j = 1; j < fullnessValues.size(); j++){
            if(fullnessValues[i] > fullnessValues[j]){
                temp_hung = fullnessValues[i];
                fullnessValues[i] = fullnessValues[j];
                fullnessValues[j] = temp_hung;

                temp_player = names[i];
                names[i] = names[j];
                names[j] = temp_player;
            }
        }
    }
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

bool Party::NPCPuzzle()
{
    ifstream data("riddles.txt");
    string lines[2];
    string line = "";
    string answer = "";
    bool result  = false;

    srand(time(0));
    int random = rand() % 20;
    int i = 0;
    while(!data.eof()){
        getline(data,line);
        split2(line,'~',lines,2);
        if(i == random){
            cout << lines[0] <<endl;
            cin >> answer;
            if(answer == lines[1]){
                result = true;
                break;
            }
        }
        i++;
    }
    if(result){
        cout << "You got it right! You are a genius. Well I stand by my word, here are my prices:" <<endl;
        return true;
    }
    else{
        cout << "Nope that isn't quite correct. I was worried you were going to get it there for a second. Goodbye!" <<endl;
        return false;
    }
}
void Party:: ActionMenu()
{
    srand(time(0));
    //rand()%100 + 1;
    int choice = 0;
    int randum;
    if((map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol()) == false) && (map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()) == false))
    {
        do
        {
            StatusUpdate(inv);
            cout << "Choose an option\n1. Move\n2. Investigate\n3. Pick a Fight\n4. Cook and Eat\n5. Give up" << endl;
            cin >> choice;
            switch(choice)
            {
                case 1:
                    char direction;
                    cout << " Choose a direction to move" << endl;
                    cin >> direction;
                    if(map.move(direction) == true){
                        for(int i = 0; i < 5; i++)
                        {
                            int randFullnessChance = rand() % 100 + 1;
                            if(randFullnessChance <= 20)
                            {
                                setFullness(getFullness(i) - 1,i);
                            }
                        }
                        checkSpace();
                        break;
                    }
                    else
                    {
                        cout << "You can't move in that direction, please try again!" << endl;
                        break;
                    }
                    break;
                case 2:
                    if(map.isExplored(map.getPlayerRow(),map.getPlayerCol()) == false)
                    {
                        map.exploreSpace(map.getPlayerRow(),map.getPlayerCol());
                        randum = rand()%100 + 1;
                        // player finds a key
                        if(randum <= 10)
                        {
                            cout << "You found a key!" << endl;
                            inv.setKeys(inv.getKeys()+1);
                        }
                        // player finds a treasure
                        else if(randum <= 20)
                        {
                            cout << "You found a treasure" << endl;
                            inv.setTreasures(inv.getTreasures(roomsCleared) + 1, roomsCleared);
                        }
                        // player fights a random monster
                        else if(randum <= 40)
                        {
                            inv = monst.battle(inv);
                        }
                    }
                    else
                    {
                        cout << "This space cannot be explored" << endl;
                        break;
                    }
                    break;
                case 3:
                    //cout << "here" << endl;
                    if(roomsCleared == 5)
                    {
                        cout << "There are no monsters to fight! Your goal now is to escape!" << endl;
                        break;
                    }
                    inv = monst.battle(inv);
                    //for(int i = 0; i < inv.getLives().size(); i++)
                    //{
                        //if(inv.getLives().at(i) == false)
                        //{
                           // cout << "got here" << endl;
                            //deathFunc(i);
                        //}
                    //}
                    break;
                case 4:
                    Cook();
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
        cout << "sorry that u lost!! 3" << endl;
        gameEnd = true;
        return;
    }
}
int Party:: getRandomRow(int num_rows)
{
    srand(time(0));
    return rand() % num_rows;
}
int Party::getRandomCol(int num_columns)
{
    srand(time(0));
    return rand() % num_columns;
}
void Party:: displayPartyMap()
{
    map.displayMap();
}
void Party:: setMap()
{
    map.resetMap();
    int num = 0;
    int numRows = map.getNumRows();
    int numCols = map.getNumCols();

    int row = 0;
    int col = 0;
    int rooms = 0;
    int NPCs = 0;

    map.setPlayerPosition(0,0);
    bool exit = false;
    do{
        row = getRandomRow(numRows);
        col = getRandomCol(numCols);

        if(row != 0 && col != 0){
            if(map.addRoom(row,col)){
                rooms++;
            }
        }

    }while(rooms < 5);

    
    do{
        row = getRandomRow(numRows);
        col = getRandomCol(numCols);
        if(row != 0 && col != 0){
            if(map.addNPC(row,col)){
                
                NPCs++;
            }
        }

    }while(NPCs < 5);
}
void Party:: createGame()
{
    setMap();
    string inputStr = "";
    cout << "What is the party leader's name?" << endl;
    cin >> inputStr;
    setName(0,inputStr);
    for(int i = 1; i <= 4; i++)
    {
        cout << "What is companion " << i << "'s name?" << endl;
        cin >> inputStr;
        setName(i,inputStr);
    }
    inv = merch.menu(inv);
    while(gameEnd != true)
    {
        delay(5);
        StatusUpdate(inv);
        ActionMenu();
        displayPartyMap();
        if((roomsCleared == 5)&& (getNamesSize() >= 1))
        {
            gameEnd = true;
        }
        if(anger == 100)
        {
            gameEnd = true;
        }
    }
    if(gameEnd == true)
    {
        string myText;
        cout << "Here are your statistics" << endl;
        ofstream Results("Results.txt");
        Results << "leader: " <<names[0] << "\n"<< endl;
        Results << "Rooms cleared: " << roomsCleared << endl;
        Results << "Gold: " << inv.getGold() << endl;
        Results << "Treasures: " << inv.getTreasures(0) << inv.getTreasures(1) << inv.getTreasures(2) <<  endl;
        Results.close();
        ifstream readFile("Results.txt");
        while (getline (readFile, myText)) {
        cout << myText << endl;
        }
        readFile.close();
         
    }
}

void Party::checkSpace(){
    int choice = 0;
    int randum = 0;
    if((map.isNPCLocation(map.getPlayerRow(),map.getPlayerCol()) == true)){
        cout << "This is an NPC Space!" << endl;
        cout << "Choose an option\n1. Move\n2. Speak to an NPC\n3. Give Up" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                char direction;
                cout << " Choose a direction to move" << endl;
                cin >> direction;
                if(map.move(direction) == true){
                    for(int i = 0; i < 5; i++)
                    {
                        int randFullnessChance = rand() % 100 + 1;
                        if(randFullnessChance <= 20)
                        {
                            setFullness(getFullness(i) - 1,i);
                        }
                    }
                    setAnger();
                    break;
                }
                else
                {
                    cout << "You can't move in that direction, please try again!" << endl;
                    break;
                }
                break;
                case 2:
                    if(NPCPuzzle() == true)
                    {
                        merch.setPrice(roomsCleared);
                        merch.menu(inv);
                    }
                    else
                    {
                        inv = monst.battle(inv);
                    }
                    map.exploreSpace(map.getPlayerRow(),map.getPlayerCol());
                    map.removeNPC(map.getPlayerRow(),map.getPlayerCol());

                case 3:
                    gameEnd = true;
                    cout << "sorry that u lost!! 1" << endl;
                    return;

            StatusUpdate(inv);
        }
    }

    if((map.isRoomLocation(map.getPlayerRow(),map.getPlayerCol()) == true)){   
        cout << "This is a room space!" << endl;
        cout << "Choose an option\n1. Move\n2. Open the door\n3. Give Up" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                char direction;
                cout << " Choose a direction to move" << endl;
                cin >> direction;
                if(map.move(direction) == true){
                    for(int i = 0; i < 5; i++)
                    {
                        int randFullnessChance = rand() % 100 + 1;
                        if(randFullnessChance <= 20)
                        {
                            setFullness(getFullness(i) - 1,i);
                        }
                    }
                    setAnger();
                    break;
                }
                else
                {
                    cout << "You can't move in that direction, please try again!" << endl;
                    break;
                }
                break;
            case 2:
                if(inv.getKeys() > 0)
                {
                    int goldNumTemp = inv.getGold();
                    monst.setRating(monst.getRating()+1);
                    inv = monst.battle(inv);
                    if(inv.getGold() > goldNumTemp)
                    {
                        randum = rand()%100 + 1;
                        if(randum <= 60)
                        {
                            Misfortunes();
                        }
                        map.removeRoom(map.getPlayerRow(),map.getPlayerCol());
                        setRoomsCleared(getroomsCleared()+1);
                        setAnger();
                        inv.setKeys(inv.getKeys()-1);
                    }
                    else
                    {
                        randum = rand()%100 + 1;
                        if(randum <= 40)
                        {
                            Misfortunes();
                        }
                    }
                    //battle the source
                }
                else
                {
                    if(doorPuzzle() == true)
                    {
                        int goldNumTemp = inv.getGold();
                    monst.setRating(monst.getRating()+1);
                    inv = monst.battle(inv);
                    if(inv.getGold() > goldNumTemp)
                    {
                        randum = rand()%100 + 1;
                        if(randum <= 60)
                        {
                            Misfortunes();
                        }
                        setRoomsCleared(getroomsCleared()+1);
                        setAnger();
                        inv.setKeys(inv.getKeys()-1);
                    }
                    else
                    {
                        randum = rand()%100 + 1;
                        if(randum <= 40)
                        {
                            Misfortunes();
                        }
                        inv.setKeys(inv.getKeys()-1);
                    }
                    }
                    else
                    {
                        randum = rand()%4 + 1;
                        for(int i = 1; i < 4; i++)
                        {
                            if(i == randum)
                            {
                                deathFunc(i);
                            }
                        }
                    }
                }
            break;
            case 3:    
                gameEnd = true;               
                cout << "sorry that u lost!! 2" << endl;
                return;
            StatusUpdate(inv);
        }
    }
    cout << "Rooms: " << getroomsCleared() <<endl;
    if((getroomsCleared() == 5) && (map.isDungeonExit(map.getPlayerRow(),map.getPlayerCol() == true))){
        cout << "You won!" << endl;
        gameEnd = true;
        return;
    }
}