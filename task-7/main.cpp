#include <iostream>
#include <string>

using namespace std;

class player
{
public:
    int totalPlayers[3];
    string name = "";
    string characterRole[3] = { "Knight", "Archer", "Spearman" };
};

class item
{
    string itemName = "";
    string itemType = "";
    int price = 0;
    int damage = 0;
};

void getPlayerName()
{

}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 7" << endl;
    cout << "-----------" << endl;

    int coins = 100;

    player player1;
    player player2;
    player player3;

    player totalPlayers[3] = { player1, player2, player3 };

    for (int i = 0; i <= 3; i++)
    {
        cout << "Enter player #" << i++ << "'s name: ";
        cin >> totalPlayers[i].name;
        cout << totalPlayers[i].name;
    }

    return 0;
}