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

string getPlayerNames() // Asks each player's name and displays them
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Player #" << i + 1 << "'s name: ";
        cin >> allPlayers[i].playerName;
        cout << allPlayers[i].playerName << " is Player #" << i + 1 << ".\n\n";
        continue;
    }
}

// Shop related functions

void displayShopInterface(int i = 0)
{
    cout << allPlayers[i].playerName << ", please select an item to purchase.\n\n";

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
    cout << "+----------------+-----------+-------+---------+----------------+\n\n";
}

int getShopInput(int i = 0)
{
    cout << "Enter item number (1-7): ";
    cin >> allPlayers[i].playerChosenItemId;
    //allPlayers[i].playerChosenItemId--; // Takes 1 away so that the value of this variable aligns with the item IDs
}

void inputRangeCheck(int i = 0) // Checks the user's input to see if it is between 1-7. If not, an error is printed
{
    while (!(allPlayers[i].playerChosenItemId >= 0 && allPlayers[i].playerChosenItemId < 8))
    {
        cerr << "[ERROR] Invalid input! Please input numbers from 1-7." << endl;
        getShopInput();
    }
}

void overspendingCheck(int i = 0)
{
    if (party.currentCoins < allItems[allPlayers[i].playerChosenItemId].itemPrice) // If the party's current coins is less than the price of the player's chosen item (so they cannot afford their selection)
    {
        cerr << "[ERROR] You can't spend more coins than you have! You have " << party.currentCoins << " remaining. Please try again." << endl;
        getShopInput();
    }
}

void soldOutCheck(int i = 0)
{
    if (allItems[allPlayers[i].playerChosenItemId].bItemOccupied == true)
    {
        cerr << "[SOLD OUT!] This item is sold out and is no longer available. Please choose another item." << endl;
        getShopInput();
    }
}

int spendMoney(int i = 0)
{
    switch (allPlayers[i].playerChosenItemId)
    {
    case 0:
        party.currentCoins = party.currentCoins - greatSword.itemPrice;
        greatSword.bItemOccupied = true;
        break;
    case 1:
        party.currentCoins = party.currentCoins - scimitar.itemPrice;
        scimitar.bItemOccupied = true;
        break;
    case 2:
        party.currentCoins = party.currentCoins - dagger.itemPrice;
        dagger.bItemOccupied = true;
        break;
    case 3:
        party.currentCoins = party.currentCoins - longbow.itemPrice;
        longbow.bItemOccupied = true;
        break;
    case 4:
        party.currentCoins = party.currentCoins - crossbow.itemPrice;
        crossbow.bItemOccupied = true;
        break;
    case 5:
        party.currentCoins = party.currentCoins - rustySpear.itemPrice;
        rustySpear.bItemOccupied = true;
        break;
    case 6:
        party.currentCoins = party.currentCoins - ironSpear.itemPrice;
        ironSpear.bItemOccupied = true;
        break;
    }

    cout << allPlayers[i].playerName << " has chosen " << allItems[allPlayers[i].playerChosenItemId].itemName << " as their weapon." << endl;
    cout << int(party.currentCoins) << " coins are remaining.\n\n";
}

char restartSelection()
{
    char yesOrNo = ' ';

    cout << "Are you happy with your selection? [Y/N]: ";
    cin >> yesOrNo;

    if (yesOrNo == ('N' || 'n'))
    {
        cout << "Resetting shop..." << endl;
        displayShopInterface();
        getShopInput();
    }
    else if (yesOrNo == ('Y' || 'y'))
    {
        cout << "Selection confirmed!" << endl;
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

    cout << "Welcome " << allPlayers[0].playerName << ", " << allPlayers[1].playerName << " and " << allPlayers[2].playerName << " to the shop!" << endl;

    for (int i = 0; i < 3; i++)
    {
        getShopInput();
        inputRangeCheck();
        overspendingCheck();
        spendMoney();

        //continue;
    }

    restartSelection();

    return 0;
}