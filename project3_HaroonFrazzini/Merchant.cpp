// CSCI1300 Fall 2022
// Author: Vince Frazzini & Ali Haroon
// Recitation: 303 - Xuafei Recitation 101 - Morgan Byers
// Project 3 Merchant.cpp
#include "Merchant.h"
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Merchant:: Merchant()
{
    priceMultiplier = 1;
}
void Merchant::buyIngredients(Inventory current)
{

}
Inventory Merchant::buyCookware(Inventory current)
{
    int num = 0;
    int amount = 0;
    string answer = "";
    do{
    cout << "Cookware is necessary for any valient soldier. Here are all the options I have for sale.\nSome options have a lower chance of breaking on use, shown by (X%)" <<endl;
    cout << "Choose one of the following:\n1. (25%) Ceramic Pot [2 Gold]\n2. (10%) Frying Pan [10 Gold]\n3. ( 2%) Cauldron [20 Gold]\n4. Cancel" <<endl;
    cin >> num; 
    if(num > 0 && num < 4){
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        while(amount < 0){
            cout << "Invalid input." << endl;
            cout << "Enter a new number to buy:" << endl;
            cin >> amount;
        }
    }
    if(amount !=0){


        if(num == 1)
        {
            while(amount*2 > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Ceramic Pots. " << endl;
                cout << "Each Ceramic Pot is 2 Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/2 << " Ceramic Pots or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Ceramic Pots for " << amount*2 << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setCookware(amount,0);
                    current.setGold(current.getGold()-amount*2);
                    cout << "Pleasure doing business with you!" << endl << "You know have " << current.getGold() << " gold." <<endl;
                }
            }
        }


        else if(num == 2)//Frying Pans
        {
            while(amount*10 > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Frying Pans. " << endl;
                cout << "Each Frying Pan is 10 Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/10 << " Frying Pans or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Frying Pans for " << amount*10 << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setCookware(amount,1);
                    current.setGold(current.getGold()-amount*10);
                    cout << "Pleasure doing business with you!" << endl << "You know have " << current.getGold() << " gold." <<endl;
                }
            }
        }



        else if(num == 3)
        {
            while(amount*20 > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Couldrons. " << endl;
                cout << "Each Couldron is 20 Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/20 << " Couldrons or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Couldrons for " << amount*20 << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setCookware(amount,2);
                    current.setGold(current.getGold()-amount*20);
                    cout << "Pleasure doing business with you!" << endl << "You know have " << current.getGold() << " gold." <<endl;
                }
            }
        }


        else if (num <= 0 || num >4)
        {
            cout << "Invalid input." << endl;
            cout << "Enter a new number" << endl;
            cin >> num;
        }
    }   
    }while (num !=4);
    return current;
}
void Merchant ::buyWeapons(Inventory current)
{
    int num = 0;
    int amount = 0;
    do{
    cout << "Ah yes weapons! Very important. Here are all the options I have for sale.\nAnd for some extra gold you can get some special weapons that do extra damage, shown by (+X)" <<endl;
    cout << "Choose one of the following:\n1. Stone Club [2 Gold]\n2. Iron Spear [2 Gold]\n3. (+1) Mythril Rapier [5 Gold]\n4. (+2) Flaming Battle-Axe Rapier [15 Gold]\n5. (+4) Vorpal Long Sword [50 Gold]\n6. Cancel" <<endl;
    cin >> num; 

        if(num == 1)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,0);
        }
        else if(num == 2)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,1);
        }
        else if(num == 3)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,2);
        }
        else if(num == 4)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,3);
        }
        else if(num == 5)
        {
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        current.setWeapons(amount,4); 
        }
        else if (num <= 0 || num >6)
        {
            cout << "Invalid input." << endl;
            cout << "Enter a new number" << endl;
            cin >> num;
        }
    } while (num !=6);
}
void Merchant::buyArmor(Inventory current)
{

}
void Merchant::sellTreasures(Inventory current)
{

}