#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

// Setting up player objects

Player player1("", 0);
Player player2("", 0);
Player player3("", 0);

Player allPlayers[] = { player1, player2, player3 };

// Setting up party object

Party party(100);

// Setting up item objects

Item greatSword("Great Sword", 1, 40, 100, 0); // Creating an item of great sword with the variables I have given it
Item scimitar("Scimitar", 2, 35, 75, 0);
Item dagger("Dagger", 3, 10, 35, 0);
Item longbow("Longbow", 4, 20, 55, 0);
Item crossbow("Crossbow", 5, 40, 100, 0);
Item rustySpear("Rusty Spear", 6, 10, 35, 0);
Item ironSpear("Iron Spear", 7, 20, 65, 0);

Item allItems[7] = { greatSword, scimitar, dagger, longbow, crossbow, rustySpear, ironSpear };

// Player related functions

void getPlayerNames() // Asks each player's name and displays them
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Player #" << i + 1 << "'s name: ";
        cin >> allPlayers[i].playerName;
        cout << allPlayers[i].playerName << " is Player #" << i + 1 << ".\n\n";
    }
}

// Shop related functions

void displayShopInterface(int i = 0)
{
    cout << "\n" << allPlayers[i].playerName << ", please select an item to purchase.\n\n";

    cout << "+----------------+-----------+-------+---------+----------------+" << endl;
    cout << "| ITEM NAME      | ITEM TYPE | PRICE | DAMAGE  | CHARACTER ROLE |" << endl;
    cout << "+----------------+-----------+-------+---------+----------------+" << endl;
    cout << "| 1. Great Sword | Sword     | 40    | 100     | Knight         |" << endl;
    cout << "| 2. Scimitar    | Sword     | 35    | 75      | Knight         |" << endl;
    cout << "| 3. Dagger      | Sword     | 10    | 35      | Knight         |" << endl;
    cout << "| 4. Longbow     | Bow       | 20    | 55      | Archer         |" << endl;
    cout << "| 5. Crossbow    | Bow       | 40    | 100     | Archer         |" << endl;
    cout << "| 6. Rusty Spear | Spear     | 10    | 35      | Spearmen       |" << endl;
    cout << "| 7. Iron Spear  | Spear     | 20    | 65      | Spearmen       |" << endl;
    cout << "+----------------+-----------+-------+---------+----------------+" << endl;
}

int getShopInput(int i = 0) // Gets the player's choice of item
{
    cout << "\nEnter item number (1-7): ";
    cin >> allPlayers[i].playerChosenItemId;
    allPlayers[i].playerChosenItemId--; // Takes 1 away so that the value of this variable aligns with the item IDs

    return allPlayers[i].playerChosenItemId;
}

void allChecks() // This function is mainly for use in the other check functions, so that once one check is completed, then the rest of the checks can be completed as well
{
    void inputRangeCheck(); // Forward declarations, so the program knows that these functions will be declared later
    void soldOutCheck();
    void overspendingCheck();
}

void inputRangeCheck(int i = 0) // Checks the user's input to see if it is between 1-7. If not, an error is printed
{
    while (!(allPlayers[i].playerChosenItemId >= 0 && allPlayers[i].playerChosenItemId < 7))
    {
        cerr << "\n[ERROR] Invalid input! Please input numbers from 1-7." << endl;
        cin.clear();
        cin.ignore(1000, '\n');

        getShopInput();
        allChecks();
    }
}

void soldOutCheck(int i = 0) // Checks if the player's chosen item has been bought already using the bItemOccupied boolean variable
{
    while (allItems[allPlayers[i].playerChosenItemId].bItemOccupied == true)
    {
        cerr << "\n[SOLD OUT!] This item is sold out and is no longer available. Please choose another item." << endl;

        getShopInput();
        allChecks();
    }
}

void overspendingCheck(int i = 0) // Checks if the party is attempting to overspend by checking if their coins are less than their specified item's price
{
    while (party.currentCoins < allItems[allPlayers[i].playerChosenItemId].itemPrice) // If the party's current coins is less than the price of the player's chosen item (so they cannot afford their selection)
    {
        cerr << "\n[ERROR] You can't spend more coins than you have! You have " << party.currentCoins << " remaining. Please try again." << endl;

        getShopInput();
        allChecks();
    }
}

void spendMoney(int i = 0) // Subtracts the prices of individual items from the party's coins
{
    switch (allPlayers[i].playerChosenItemId)
    {
    case 0:
        party.currentCoins = party.currentCoins - greatSword.itemPrice;
        break;
    case 1:
        party.currentCoins = party.currentCoins - scimitar.itemPrice;
        break;
    case 2:
        party.currentCoins = party.currentCoins - dagger.itemPrice;
        break;
    case 3:
        party.currentCoins = party.currentCoins - longbow.itemPrice;
        break;
    case 4:
        party.currentCoins = party.currentCoins - crossbow.itemPrice;
        break;
    case 5:
        party.currentCoins = party.currentCoins - rustySpear.itemPrice;
        break;
    case 6:
        party.currentCoins = party.currentCoins - ironSpear.itemPrice;
        break;
    }
    
    allItems[allPlayers[i].playerChosenItemId].bItemOccupied = true; // Sets the current player's chosen item to occupied, so that no one else can buy it

    cout << "\n" << allPlayers[i].playerName << " has chosen " << allItems[allPlayers[i].playerChosenItemId].itemName << " as their weapon." << endl;
    cout << "The party has " << int(party.currentCoins) << " coins remaining." << endl;
}

void restartSelection(char yesOrNo = ' ')
{
    cout << "\nAre you happy with your selection? [Y/N]: ";
    cin >> yesOrNo;

    if (yesOrNo == 'N' || yesOrNo == 'n')
    {
        cout << "\nResetting shop..." << endl;
        party.currentCoins = 100;
        
        for (int i = 0; i < 3; i++)
        {
            displayShopInterface();
            getShopInput();
            inputRangeCheck();
            overspendingCheck();
            spendMoney();

        }
        restartSelection();
    }
    else if (yesOrNo == 'Y' || yesOrNo == 'y')
    {
        cout << "\nSelection confirmed!" << endl;
    }
    else
    {
        cerr << "[ERROR] Invalid input! Please enter Y or N: ";
        cin >> yesOrNo;
    }
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 7" << endl;
    cout << "-----------" << endl;

    getPlayerNames();

    cout << "Welcome " << allPlayers[0].playerName << ", " << allPlayers[1].playerName << " and " << allPlayers[2].playerName << " to the shop!" << endl;

    for (int i = 0; i < 3; i++)
    {
        displayShopInterface();
        getShopInput();
        allChecks();
        spendMoney();
    }

    restartSelection();

    return 0;
}