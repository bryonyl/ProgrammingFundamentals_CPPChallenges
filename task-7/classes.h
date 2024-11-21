#pragma once
#include <string>

using namespace std;

class Item // The blueprint for an item
{
public:
    string itemName = ""; // Default values
    int itemId = 0;
    int itemPrice = 0;
    int itemDamage = 0;
    string itemRole = " ";
    bool bItemOccupied = false;

    Item(string name, int id, int price, int damage, string role, bool bOccupied); // Declaration of the class constructor
};

// What is created from the blueprint above - an object

Item::Item(string name, int id, int price, int damage, string role, bool bOccupied) { // Body of the class constructor - assigns values to the object. Also technically a definition, but includes the body of the constructor
    itemName = name;
    itemId = id;
    itemPrice = price;
    itemDamage = damage;
    itemRole = role;
    bItemOccupied = bOccupied;
}

class Player
{
public:
    string playerName = "";
    int playerChosenItemId = 0;

    Player(string name, int chosenItemId);
};

Player::Player(string name, int chosenItemId) {
    playerName = name;
    playerChosenItemId = chosenItemId;
}

class Party // Shared variables amongst all players
{
public:
    int currentCoins = 100;

    Party(int coins);
};

Party::Party(int coins) {
    currentCoins = coins;
}