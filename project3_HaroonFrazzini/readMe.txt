------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 gameDriver.cpp Inventory.cpp Merchant.cpp Monster.cpp Party.cpp Map.cpp 
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
Monster.h, Merchant.h, Party.h, Inventory.h, and Map.h must be in the same directory as the cpp 
files in order to compile.
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Vince Frazzini and Ali Haroon
Vince's Recitation: 303 - Xuafei Son 
Ali's Recitation 101 - Morgan Byers
Date: Dec 1, 2022
------------------------
ABOUT THIS PROJECT
------------------------
This project is a fun game file that is run through a terminal and allows
for extensive interaction between the user and the terminal. The game starts by 
entering player names and then exploring a 2D map looking for monsters, 
opening rooms, and interacting with NPC's. We also implemented a sort function to 
sort the players by their fullness levels so that the most full is always on top 
and the closest to dying is on the bottom.