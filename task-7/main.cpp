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

Item greatSword("Great Sword", 1, 40, 100, "Knight", 0); // Creating an item of great sword with the variables I have given it
Item scimitar("Scimitar", 2, 35, 75, "Knight", 0);
Item dagger("Dagger", 3, 10, 35, "Knight", 0);
Item longbow("Longbow", 4, 20, 55, "Archer", 0);
Item crossbow("Crossbow", 5, 40, 100, "Archer", 0);
Item rustySpear("Rusty Spear", 6, 10, 35, "Spearman", 0);
Item ironSpear("Iron Spear", 7, 20, 65, "Spearman", 0);

Item allItems[7] = { greatSword, scimitar, dagger, longbow, crossbow, rustySpear, ironSpear };

// Forward declarations, so the program knows that these functions will be declared later

bool inputRangeCheck(int i);
bool soldOutCheck(int i);
bool overspendingCheck(int i);

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

void printPlayerSummary()
{
    cout << "\nParty Summary" << endl;
    cout << "-------------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Player #" << i + 1 << " (" << allPlayers[i].playerName << "), Role: " << allItems[allPlayers[i].playerChosenItemId].itemRole << ", Weapon: " << allItems[allPlayers[i].playerChosenItemId].itemName << ", Damage: " << allItems[allPlayers[i].playerChosenItemId].itemDamage << endl;
    }
}

// Shop related functions

void displayShopInterface(int i)
{
    cout << "\n" << allPlayers[i].playerName << ", please select an item to purchase.\n\n";

    cout << "+----------------+-----------+-------+---------+----------------+" << endl;
    cout << "| ITEM NAME      | ITEM TYPE | PRICE | DAMAGE  | CHARACTER ROLE |" << endl;
    cout << "+----------------+-----------+-------+---------+----------------+" << endl;
    cout << "| 0. Great Sword | Sword     | 40    | 100     | Knight         |" << endl;
    cout << "| 1. Scimitar    | Sword     | 35    | 75      | Knight         |" << endl;
    cout << "| 2. Dagger      | Sword     | 10    | 35      | Knight         |" << endl;
    cout << "| 3. Longbow     | Bow       | 20    | 55      | Archer         |" << endl;
    cout << "| 4. Crossbow    | Bow       | 40    | 100     | Archer         |" << endl;
    cout << "| 5. Rusty Spear | Spear     | 10    | 35      | Spearmen       |" << endl;
    cout << "| 6. Iron Spear  | Spear     | 20    | 65      | Spearmen       |" << endl;
    cout << "+----------------+-----------+-------+---------+----------------+" << endl;
}

int getShopInput(int i) // Gets the player's choice of item
{
    cout << "\nEnter item number (0-6): ";
    cin >> allPlayers[i].playerChosenItemId;
;
    return allPlayers[i].playerChosenItemId;
}

bool allChecks(int i) // This function is mainly for use in the other check functions, so that once one check is completed, then the rest of the checks can be completed as well
{
    if (inputRangeCheck(i) == true && soldOutCheck(i) == true && overspendingCheck(i) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool inputRangeCheck(int i) // Checks the user's input to see if it is between 1-7. If not, an error is printed
{
    bool check = !(i >= 0 && i <= 6);

    if (check)
    {
        cerr << "\n[ERROR] Invalid input! Please input numbers from 1-7." << endl;
        cin.clear();
        cin.ignore(1000, '\n');

        return false;
    }
    else
    {
        return true;
    }
}

bool soldOutCheck(int i) // Checks if the player's chosen item has been bought already using the bItemOccupied boolean variable
{
    if (allItems[i].bItemOccupied == true)
    {
        cerr << "\n[SOLD OUT!] This item is sold out and is no longer available. Please choose another item." << endl;

        return false;
    }
    else
    {
        return true;
    }
}

bool overspendingCheck(int i) // Checks if the party is attempting to overspend by checking if their coins are less than their specified item's price
{
    if (party.currentCoins < allItems[i].itemPrice) // If the party's current coins is less than the price of the player's chosen item (so they cannot afford their selection)
    {
        cerr << "\n[ERROR] You can't spend more coins than you have! You have " << party.currentCoins << " remaining. Please try again." << endl;

        return false;
    }
    else
    {
        return true;
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
            displayShopInterface(i);
            getShopInput(i);
            if (allChecks(getShopInput(i)))
            {
                spendMoney();
            }
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
        bool notValid = false;

        while (notValid == false)
        {
            displayShopInterface(i);

            if (allChecks(getShopInput(i)))
            {
                spendMoney();
                notValid = true;
            }
        }
    }

    restartSelection();
    printPlayerSummary();

    return 0;
}