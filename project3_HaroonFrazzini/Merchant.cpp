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
Merchant:: Merchant(int rooms){
    priceMultiplier = 1 + (.25 * rooms);
}

Inventory Merchant::menu(Inventory current){
    int num = 0;
    cout << "If you're looking to get supplies, you've come to the right place.\nI would be happy to part with some of my wares...for the proper price!" <<endl;
    do{
    current.printInventory();
    cout << "Choose one of the following:\n1. Ingredients: To make food, you have to cook raw ingredients.\n2. Cookware: You will need something to cook those ingredients.\n3. Weapons: It's dangerous to go alone, take this!\n4. Armor: If you want to survive monster attacks, you will need some armor.\n5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n6. Leave: Make sure you get everything you need, I'm leaving after this sale!\n" <<endl;
    cin >> num;
    if(num == 1){
        current = buyIngredients(current);
        //cout << "Thank you for your patronage! What else can I get for you?" <<endl;
    }
    else if(num == 2){
        current = buyCookware(current);
        //cout << "Thank you for your patronage! What else can I get for you?" <<endl;
    }
    else if(num == 3){
        current = buyWeapons(current);
        //cout << "Thank you for your patronage! What else can I get for you?" <<endl;
    }
    else if(num == 4){
        current = buyArmor(current);
        //cout << "Thank you for your patronage! What else can I get for you?" <<endl;
    }
    else if(num == 5){
        current = sellTreasures(current);
        //cout << "Thank you for your patronage! What else can I get for you?" <<endl;
    }
    else if(num <=0 || num > 6){
        cout << "Invalid input." << endl;
        cout << "Enter a new number" << endl;
        cin >> num;
    }
    
    }while(num != 6);
    return current;
}

Inventory Merchant::buyIngredients(Inventory current)
{
    int amount = 0;
    string answer = "";
    int ingred = 1*priceMultiplier;

    cout << "I recommend at least 10 kg of ingredients per person! Ingredients are "<< ingred << " gold per kg.\nHow many kg of ingredients do you need? (Enter a positive mulitple of 5, or 0 to cancel)" <<endl;
    cin >> amount; 
    while(amount*ingred > current.getGold() || amount%5 != 0){
        if(amount*ingred > current.getGold()){
            cout << "You do not have enough money to purchase " << amount << " " << " kg of ingredients." << endl;
            cout << "Each kg of ingredients is "<< ingred <<" Gold and you have " << current.getGold() << " gold." << endl;
            cout << "Choose between 1-" << current.getGold()/ingred << " kg of ingredients or enter 0 to cancel."<<endl;
            cin >> amount;
            if(amount == 0){
                break;
            }
        }
        else if(amount%5 != 0){
            cout << "You must buy ingredients in increments in 5 kg" <<endl;
            cout << "How many kg of ingredients do you need? (Enter a positive mulitple of 5, or 0 to cancel)" <<endl;
            cin >> amount;
            if(amount == 0){
                break;
            }
        }
    }
    if(amount != 0){
        cout << "Are you sure you want to buy " << amount << " kg of ingredients for " << amount*ingred << " Gold? (y/n)" <<endl;
        cin >> answer;
        if(answer == "y"){
            current.setIngredients(amount);
            current.setGold(current.getGold()-amount*ingred);
            cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
        }
    }
    return current;
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
Inventory Merchant::buyArmor(Inventory current)
{
    int amount = 0;
    string answer = "";
    int armor = 5*priceMultiplier;

    cout << "Armor is necessary for your party, each piece costs "<< armor << " gold.\nHow many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" <<endl;
    cin >> amount; 
    while(amount*armor > current.getGold()){
        cout << "You do not have enough money to purchase " << amount << " " << "pieces of armor." << endl;
        cout << "Each piece of armor is "<< armor <<" Gold and you have " << current.getGold() << " gold." << endl;
        cout << "Choose between 1-" << current.getGold()/armor << " Pieces of armor or enter 0 to cancel."<<endl;
        cin >> amount;
        if(amount == 0){
            break;
        }
    }
    if(amount != 0){
        cout << "Are you sure you want to buy " << amount << " pieces of armor for " << amount*armor << " Gold? (y/n)" <<endl;
        cin >> answer;
        if(answer == "y"){
            current.setArmor(amount);
            current.setGold(current.getGold()-amount*armor);
            cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
        }
    }
    return current;
}
Inventory Merchant::sellTreasures(Inventory current)
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
    cout << "Oh do you have something for me?\nI'll happily take some of those treasures off of you!" <<endl;
    cout << "Choose one of the following to sell:\n1. Silver Ring [10 Gold each]\n2. Ruby Necklace [20 Gold Each]\n3. Emerald Bracelet [30 Gold Each]\n4. Diamond Circlet [40 Gold Each]\n5. Gem-Encrusted Goblet [50 Gold Each]\n6. Cancel" <<endl;
    cin >> num; 
    if(num > 0 && num < 6 ){
        if(current.getTreasures(num-1) > 0){
            cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> amount;
            while(amount > current.getTreasures(num-1) || amount < 0){
                    if(amount > current.getTreasures(num-1)){
                        cout << "It doesn't look like you have that many!" <<endl;
                        cout << "Choose between 1-" << current.getTreasures(num-1) << " to sell or enter 0 to cancel." <<endl;
                        cin >> amount;
                        if(amount ==0 ){
                            break;
                        }
                    }
                    else{
                        cout << "Invalid input." << endl;
                        cout << "Enter a new number to buy:" << endl;
                        cin >> amount;
                    }
            }
        }
        else{
            cout << "Oops! It doesn't look like you have any of that treasure" <<endl;
            //break;
        }
    }

    if(amount != 0){
        if(num == 1){
            cout << "Are you sure you want to sell " << amount << " Silver Rings for " << amount*10 << " Gold? (y/n)" <<endl;
            cin >> answer;
            if(answer == "y"){
                current.setTreasures(current.getTreasures(0) - amount,0);
                current.setGold(current.getGold()+amount*10);
                cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
            }
        }
        else if(num == 2){
            cout << "Are you sure you want to sell " << amount << " Ruby Necklaces for " << amount*20 << " Gold? (y/n)" <<endl;
            cin >> answer;
            if(answer == "y"){
                current.setTreasures(current.getTreasures(1) - amount,1);
                current.setGold(current.getGold()+amount*20);
                cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
            }
        }
        else if(num == 3){
            cout << "Are you sure you want to sell " << amount << " Emerald Bracelets for " << amount*30 << " Gold? (y/n)" <<endl;
            cin >> answer;
            if(answer == "y"){
                current.setTreasures(current.getTreasures(2) - amount,2);
                current.setGold(current.getGold()+amount*30);
                cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
            }
        }
        else if(num == 4){
            cout << "Are you sure you want to sell " << amount << " Diamond Circlets for " << amount*40 << " Gold? (y/n)" <<endl;
            cin >> answer;
            if(answer == "y"){
                current.setTreasures(current.getTreasures(3) - amount,3);
                current.setGold(current.getGold()+amount*40);
                cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
            }
        }
        else if(num == 5){
            cout << "Are you sure you want to sell " << amount << " Gem-Encrusted Goblets for " << amount*50 << " Gold? (y/n)" <<endl;
            cin >> answer;
            if(answer == "y"){
                current.setTreasures(current.getTreasures(4) - amount,4);
                current.setGold(current.getGold()+amount*50);
                cout << "Pleasure doing business with you!" << endl << "You now have " << current.getGold() << " gold." <<endl;
            }
        }
        else if (num <= 0 || num >6)
        {
            cout << "Invalid input." << endl;
            cout << "Enter a new number" << endl;
            cin >> num;
        }
    }    

    } while (num !=6);
    return current;
}