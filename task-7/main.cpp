#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

#pragma region Variable Setup

// Setting up player objects

Player player1("", 0);
Player player2("", 0);
Player player3("", 0);

Player allPlayers[] = { player1, player2, player3 };

// Setting up party object

Party party(100);

// Setting up item objectss

Item greatSword("Great Sword", 1, 40, 100); // Creating an item of great sword with the variables I have given it
Item scimitar("Scimitar", 2, 35, 75);
Item dagger("Dagger", 3, 10, 35);
Item longbow("Longbow", 4, 20, 55);
Item crossbow("Crossbow", 5, 40, 100);
Item rustySpear("Rusty Spear", 6, 10, 35);
Item ironSpear("Iron Spear", 7, 20, 65);

Item allItems[7] = { greatSword, scimitar, dagger, longbow, crossbow, rustySpear, ironSpear };

#pragma endregion

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 7" << endl;
    cout << "-----------" << endl;

    // Asks for each player's name

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Player #" << i + 1 << "'s name: ";
        cin >> allPlayers[i].playerName;
        cout << allPlayers[i].playerName << " is Player #" << i + 1 << ".\n\n";
        continue;
    }

    // Displays items and allows each player to buy an item. Deducts the cost of their chosen item from the coins

    cout << "Welcome " << allPlayers[0].playerName << ", " << allPlayers[1].playerName << " and " << allPlayers[2].playerName << " to the shop!" << endl;

    for (int i = 0; i < 3; i++)
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

        cout << "Enter item number: ";
        cin >> allPlayers[i].playerChosenItemId;

        while (!(allPlayers[i].playerChosenItemId > 0 && allPlayers[i].playerChosenItemId < 8))
        {
            cerr << "[ERROR] Invalid input! Please input numbers from 1-7." << endl;
            cout << "Reenter item number: ";
            cin >> allPlayers[i].playerChosenItemId;
        }
        cout << allItems[allPlayers[i].playerChosenItemId].itemName;
        if (party.currentCoins < allItems[allPlayers[i].playerChosenItemId].itemPrice)
        {
            cerr << "[ERROR] You can't spend more coins than you have! You have " << party.currentCoins << " remaining." << endl;
        }
        else
        {
            switch (allPlayers[i].playerChosenItemId)
            {
            case 1:
                party.currentCoins = party.currentCoins - greatSword.itemPrice;
                break;
            case 2:
                party.currentCoins = party.currentCoins - scimitar.itemPrice;
                break;
            case 3:
                party.currentCoins = party.currentCoins - dagger.itemPrice;
                break;
            case 4:
                party.currentCoins = party.currentCoins - longbow.itemPrice;
                break;
            case 5:
                party.currentCoins = party.currentCoins - crossbow.itemPrice;
                break;
            case 6:
                party.currentCoins = party.currentCoins - rustySpear.itemPrice;
                break;
            case 7:
                party.currentCoins = party.currentCoins - ironSpear.itemPrice;
                break;
            }
        }

        cout << allPlayers[i].playerName << " has chosen " << allPlayers[i].playerChosenItemId << " as their weapon." << endl;
        cout << int (party.currentCoins) << " coins are remaining.\n\n";

        //continue;
    }

    return 0;
}