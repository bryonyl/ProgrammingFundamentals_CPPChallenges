#include <iostream>
#include <string>
#include "classes.h"
#include "globalVariables.h"

// Setting up player objects

Player player1("", 0);
Player player2("", 0);
Player player3("", 0);

Player allPlayers[] = { player1, player2, player3 };

// Setting up party object

Party party(100);

// Setting up item objects

Item greatSword("Great Sword", 0, 40, 100, "Knight", 0); // Creating an item of great sword with the variables I have given it
Item scimitar("Scimitar", 1, 35, 75, "Knight", 0);
Item dagger("Dagger", 2, 10, 35, "Knight", 0);
Item longbow("Longbow", 3, 20, 55, "Archer", 0);
Item crossbow("Crossbow", 4, 40, 100, "Archer", 0);
Item rustySpear("Rusty Spear", 5, 10, 35, "Spearman", 0);
Item ironSpear("Iron Spear", 6, 20, 65, "Spearman", 0);

Item allItems[7] = { greatSword, scimitar, dagger, longbow, crossbow, rustySpear, ironSpear };

// Forward declarations, so the program knows that these functions will be declared later

bool inputRangeCheck();
bool soldOutCheck();
bool overspendingCheck();

// Player related functions

void getPlayerNames() // Asks each player's name and displays them
{
    for (playerIndex = 0; playerIndex < 3; playerIndex++)
    {
        std::cout << "Enter Player #" << playerIndex+1 /*Adding 1 so that the player number displays correctly in the console, e.g. not player #0 but player #1*/ << "'s name: ";
        std::cin >> allPlayers[playerIndex].playerName;
        std::cout << allPlayers[playerIndex].playerName << " is Player #" << playerIndex+1 << ".\n\n";
    }
}

void printPlayerSummary()
{
    std::cout << "\nParty Summary" << endl;
    std::cout << "-------------" << endl;

    for (playerIndex = 0; playerIndex < 3; playerIndex++)
    {
        std::cout << "Player #" << playerIndex+1 << " (" << allPlayers[playerIndex].playerName << "), Role: " <<
            allItems[allPlayers[playerIndex].playerChosenItemId].itemRole << ", Weapon: " <<
            allItems[allPlayers[playerIndex].playerChosenItemId].itemName << ", Damage: " <<
            allItems[allPlayers[playerIndex].playerChosenItemId].itemDamage << endl;
    }
}

// Shop related functions

void displayShopInterface()
{
    std::cout << "\n" << allPlayers[playerIndex].playerName << ", please select an item to purchase.\n\n";

    std::cout << "+----------------+-----------+-------+---------+----------------+" << endl;
    std::cout << "| ITEM NAME      | ITEM TYPE | PRICE | DAMAGE  | CHARACTER ROLE |" << endl;
    std::cout << "+----------------+-----------+-------+---------+----------------+" << endl;
    std::cout << "| 0. Great Sword | Sword     | 40    | 100     | Knight         |" << endl;
    std::cout << "| 1. Scimitar    | Sword     | 35    | 75      | Knight         |" << endl;
    std::cout << "| 2. Dagger      | Sword     | 10    | 35      | Knight         |" << endl;
    std::cout << "| 3. Longbow     | Bow       | 20    | 55      | Archer         |" << endl;
    std::cout << "| 4. Crossbow    | Bow       | 40    | 100     | Archer         |" << endl;
    std::cout << "| 5. Rusty Spear | Spear     | 10    | 35      | Spearmen       |" << endl;
    std::cout << "| 6. Iron Spear  | Spear     | 20    | 65      | Spearmen       |" << endl;
    std::cout << "+----------------+-----------+-------+---------+----------------+" << endl;
}

int getShopInput() // Gets the player's choice of item
{
    std::cout << "\nEnter item number (0-6): ";
    
    std::cin >> allPlayers[playerIndex].playerChosenItemId;

    while (std::cin.fail())
    {
        std::cerr << "\n[ERROR] Invalid input! Please input numbers from 0-6: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> allPlayers[playerIndex].playerChosenItemId;
    }

    return allPlayers[playerIndex].playerChosenItemId;
}

bool allChecks() // This function is mainly for use in the other check functions, so that once one check is completed, then the rest of the checks can be completed as well
{
    if (inputRangeCheck() == true && soldOutCheck() == true && overspendingCheck() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool inputRangeCheck() // Checks the user's input to see if it is between 0-6. If not, an error is printed
{
    bool check = !(allPlayers[playerIndex].playerChosenItemId >= 0 && allPlayers[playerIndex].playerChosenItemId <= 6);

    if (check)
    {
        std::cerr << "\n[ERROR] Invalid input! Please input numbers from 0-6: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return false;
    }
    else
    {
        return true;
    }
}

bool soldOutCheck() // Checks if the player's chosen item has been bought already using the bItemOccupied boolean variable
{
    if (allItems[allPlayers[playerIndex].playerChosenItemId].bItemOccupied == true)
    {
        std::cerr << "\n[SOLD OUT!] This item is sold out and is no longer available. Please choose another item." << endl;

        return false;
    }
    else
    {
        return true;
    }
}

bool overspendingCheck() // Checks if the party is attempting to overspend by checking if their coins are less than their specified item's price
{
    if (party.currentCoins < allItems[allPlayers[playerIndex].playerChosenItemId].itemPrice) // If the party's current coins is less than the price of the player's chosen item (so they cannot afford their selection)
    {
        std::cerr << "\n[ERROR] You can't spend more coins than you have! You have " << party.currentCoins << " remaining. Please try again." << endl;

        return false;
    }
    else
    {
        return true;
    }
}

void spendMoney() // Subtracts the prices of individual items from the party's coins
{
    switch (allPlayers[playerIndex].playerChosenItemId)
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
    
    allItems[allPlayers[playerIndex].playerChosenItemId].bItemOccupied = true; // Sets the current player's chosen item to occupied, so that no one else can buy it

    std::cout << "\n" << allPlayers[playerIndex].playerName << " has chosen " << allItems[allPlayers[playerIndex].playerChosenItemId].itemName << " as their weapon." << endl;
    std::cout << "The party has " << int(party.currentCoins) << " coins remaining." << endl;
}

void restartSelection()
{
    char yesOrNo;

    std::cout << "\nAre you happy with your selection? [Y/N]: ";
    std::cin >> yesOrNo;

    while (!(yesOrNo == 'Y' || yesOrNo == 'y' || yesOrNo == 'N' || yesOrNo == 'n'))
    {
        std::cerr << "\n[ERROR] Invalid input! Please enter Y or N: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> yesOrNo;
    }
    if (yesOrNo == 'N' || yesOrNo == 'n')
    {
        std::cout << "\nResetting shop..." << endl;
        party.currentCoins = 100;
        
        for (playerIndex = 0; playerIndex < 3; playerIndex++)
        {
            allItems[allPlayers[playerIndex].playerChosenItemId].bItemOccupied = false; // For each player, reset their occupied item so that it becomes free and not sold out
        }
        
        for (playerIndex = 0; playerIndex < 3; playerIndex++)
        {
            bool bValidItemChoice = false;

            while (bValidItemChoice == false)
            {
                displayShopInterface();
                getShopInput();

                if (allChecks() == true)
                {
                    spendMoney();
                    bValidItemChoice = true;
                }
            }
        }

        restartSelection();
    }
    else if (yesOrNo == 'Y' || yesOrNo == 'y')
    {
        std::cout << "\nSelection confirmed!" << endl;
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Weapon Shop" << endl;
    std::cout << "-----------" << endl;

    getPlayerNames();

    std::cout << "Welcome " << allPlayers[0].playerName << ", " << allPlayers[1].playerName << " and " << allPlayers[2].playerName << " to the shop!" << endl;

    for (playerIndex = 0; playerIndex < 3; playerIndex++)
    {
        bool bValidItemChoice = false;

        while (bValidItemChoice == false)
        {
            displayShopInterface();
            getShopInput();

            if (allChecks() == true)
            {
                spendMoney();
                bValidItemChoice = true;
            }
        }
    }

    restartSelection();
    printPlayerSummary();

    cout << "\nYou find yourself in a forest. A monster appears..." << endl;

    return 0;
}