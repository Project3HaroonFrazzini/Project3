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
Merchant:: Merchant(int mult){
    priceMultiplier = mult;
}
void Merchant::buyIngredients(Inventory current)
{

}
Inventory Merchant::buyCookware(Inventory current)
{
    int ceramic = 2*priceMultiplier;
    int frying = 10*priceMultiplier;
    int could = 20*priceMultiplier;

    int num = 0;
    int amount = 0;
    string answer = "";
    do{
    cout << "Cookware is necessary for any valient soldier. Here are all the options I have for sale.\nSome options have a lower chance of breaking on use, shown by (X%)" <<endl;
    cout << "Choose one of the following:\n1. (25%) Ceramic Pot [" << ceramic <<" Gold]\n2. (10%) Frying Pan [" << frying <<" Gold]\n3. ( 2%) Cauldron [" << could <<" Gold]\n4. Cancel" <<endl;
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
            while(amount*ceramic > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Ceramic Pots. " << endl;
                cout << "Each Ceramic Pot is "<< ceramic <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/ceramic << " Ceramic Pots or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Ceramic Pots for " << amount*ceramic << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setCookware(amount,0);
                    current.setGold(current.getGold()-amount*ceramic);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }


        else if(num == 2)//Frying Pans
        {
            while(amount*frying > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Frying Pans. " << endl;
                cout << "Each Frying Pan is "<< frying <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/frying << " Frying Pans or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Frying Pans for " << amount*frying << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setCookware(amount,1);
                    current.setGold(current.getGold()-amount*frying);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }



        else if(num == 3)
        {
            while(amount*could > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Couldrons. " << endl;
                cout << "Each Couldron is "<< could <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/could << " Couldrons or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Couldrons for " << amount*could << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setCookware(amount,2);
                    current.setGold(current.getGold()-amount*could);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
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
Inventory Merchant ::buyWeapons(Inventory current)
{
    int club = 2*priceMultiplier;
    int spear = 2*priceMultiplier;
    int rapier = 5*priceMultiplier;
    int axe = 15*priceMultiplier;
    int sword = 50*priceMultiplier;

    int num = 0;
    int amount = 0;
    string answer = "";
    
    do{
    cout << "Ah yes weapons! Very important. Here are all the options I have for sale.\nAnd for some extra gold you can get some special weapons that do extra damage, shown by (+X)" <<endl;
    cout << "Choose one of the following:\n1. Stone Club ["<< club <<" Gold]\n2. Iron Spear ["<<spear<<" Gold]\n3. (+1) Mythril Rapier ["<<rapier <<" Gold]\n4. (+2) Flaming Battle-Axe ["<<axe<<" Gold]\n5. (+4) Vorpal Long Sword ["<<sword<<" Gold]\n6. Cancel" <<endl;
    cin >> num; 
    if(num > 0 && num < 6){
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        while(amount < 0){
            cout << "Invalid input." << endl;
            cout << "Enter a new number to buy:" << endl;
            cin >> amount;
            }
    }

        if(num == 1)
        {
            while(amount*club > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Stone Clubs. " << endl;
                cout << "Each Stone Club is "<< club <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/club << " Stone Clubs or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Stone Clubs for " << amount*club << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setWeapons(amount,0);
                    current.setGold(current.getGold()-amount*club);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }
        else if(num == 2)
        {
            while(amount*spear > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Iron Spears. " << endl;
                cout << "Each Iron Spear is "<< spear <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/spear << " Iron Spears or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Iron Spears for " << amount*spear << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setWeapons(amount,1);
                    current.setGold(current.getGold()-amount*spear);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }
        else if(num == 3)
        {
            while(amount*rapier > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Mythril Rapiers. " << endl;
                cout << "Each Mythril Rapier is "<< rapier <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/rapier << " Mythril Rapiers or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Mythril Rapiers for " << amount*rapier << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setWeapons(amount,2);
                    current.setGold(current.getGold()-amount*rapier);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }
        else if(num == 4)
        {
            while(amount*axe > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Flaming Battle-Axes. " << endl;
                cout << "Each Flaming Battle-Axe is "<< axe <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/axe << " Flaming Battle-Axes or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Flaming Battle-Axes for " << amount*axe << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setWeapons(amount,3);
                    current.setGold(current.getGold()-amount*axe);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }
        else if(num == 5)
        {
            while(amount*sword > current.getGold()){
                cout << "You do not have enough money to purchase " << amount << " " << "Vorpal Long Swords. " << endl;
                cout << "Each Vorpal Long Sword is "<< sword <<" Gold and you have " << current.getGold() << " gold." << endl;
                cout << "Choose between 1-" << current.getGold()/sword << " Vorpal Long Swords or enter 0 to cancel."<<endl;
                cin >> amount;
                if(amount == 0){
                    break;
                }
            }
            if(amount != 0){
                cout << "Are you sure you want to buy " << amount << " Vorpal Long Swords for " << amount*sword << " Gold? (y/n)" <<endl;
                cin >> answer;
                if(answer == "y"){
                    current.setWeapons(amount,4);
                    current.setGold(current.getGold()-amount*sword);
                    cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
                }
            }
        }
        else if (num <= 0 || num >6)
        {
            cout << "Invalid input." << endl;
            cout << "Enter a new number" << endl;
            cin >> num;
        }
    } while (num !=6);
    return current;
}
void Merchant::buyArmor(Inventory current)
{

}
void Merchant::sellTreasures(Inventory current)
{

}