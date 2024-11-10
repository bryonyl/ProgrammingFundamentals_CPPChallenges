#include <iostream>
#include <string>

using namespace std;

class item
{
public:
    string itemName = "";
    int itemId = 0;
    int price = 0;
    int damage = 0;
};

class player
{
public:
    string name = "";
    int chosenItemId;
};

class party // Shared variables amongst all players
{
public:
    int coins = 100;
};

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 7" << endl;
    cout << "-----------" << endl;

    // Setting up player variables

    player player1;
    player1.name = "";
    player1.chosenItemId = 0;

    player player2;
    player2.name = "";
    player2.chosenItemId = 0;

    player player3;
    player3.name = "";
    player3.chosenItemId = 0;

    player allPlayers[] = { player1, player2, player3 };

    // Setting up party variables

    party party;
    party.coins;

    // Setting up items

    item greatSword;
    greatSword.itemName = "Great Sword";
    greatSword.itemId = 1;
    greatSword.price = 40;
    greatSword.damage = 100;

    item scimitar;
    greatSword.itemName = "Scimitar";
    greatSword.itemId = 2;
    greatSword.price = 35;
    greatSword.damage = 75;

    item dagger;
    dagger.itemName = "Dagger";
    dagger.itemId = 3;
    dagger.price = 10;
    dagger.damage = 35;

    item longbow;
    longbow.itemName = "Longbow";
    longbow.itemId = 4;
    longbow.price = 20;
    longbow.damage = 55;

    item crossbow;
    crossbow.itemName = "Crossbow";
    crossbow.itemId = 5;
    crossbow.price = 40;
    crossbow.damage = 100;

    item rustySpear;
    rustySpear.itemName = "Rusty Spear";
    rustySpear.itemId = 6;
    rustySpear.price = 10;
    rustySpear.damage = 35;

    item ironSpear;
    ironSpear.itemName = "Iron Spear";
    ironSpear.itemId = 7;
    ironSpear.price = 20;
    ironSpear.damage = 65;

    item allItems[7] = { greatSword, scimitar, dagger, longbow, crossbow, rustySpear, ironSpear };

    // Asks for each player's name

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Player #" << i + 1 << "'s name: ";
        cin >> allPlayers[i].name;
        cout << allPlayers[i].name << " is Player #" << i + 1 << ".\n\n";
        continue;
    }

    // Displays items and allows each player to buy an item. Deducts the cost of their chosen item from the coins

    cout << "Welcome " << allPlayers[0].name << ", " << allPlayers[1].name << " and " << allPlayers[2].name << " to the shop!" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << allPlayers[i].name << ", please select an item to purchase.\n\n";

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
        cin >> allPlayers[i].chosenItemId;

        switch (allPlayers[i].chosenItemId)
        {
        case 1:
            party.coins = party.coins - greatSword.price;
            break;
        case 2:
            party.coins = party.coins - scimitar.price;
            break;
        case 3:
            party.coins = party.coins - dagger.price;
            break;
        case 4:
            party.coins = party.coins - longbow.price;
            break;
        case 5:
            party.coins = party.coins - crossbow.price;
            break;
        case 6:
            party.coins = party.coins - rustySpear.price;
            break;
        case 7:
            party.coins = party.coins - ironSpear.price;
            break;
        }

        cout << allPlayers[i].name << " has chosen " << allPlayers[i].chosenItemId << " as their weapon." << endl;
        cout << int (party.coins) << " coins are remaining.\n\n";

        continue;
    }

    return 0;
}