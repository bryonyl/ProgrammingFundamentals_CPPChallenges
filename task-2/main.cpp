#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 2" << endl;
    cout << "-----------" << endl;

    string name;
    string username;
    string clanTag;
    unsigned int exp = 0; // Unsigned integers cannot be negative, only positive.

    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Enter your in-game username: " << endl;
    cin >> username;

    cout << "Enter your clan tag: " << endl;
    cin >> clanTag;

    cout << "Enter your exp points: " << endl;
    while (!(cin >> exp) || cin.fail()) // Input validation. Yields strange results if you enter a negative number - this is only fixed
        // if the exp variable is changed to an int variable rather than an UNSIGNED int variable.
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please re-enter; numbers allowed only.\nEnter your xp points: " << endl;
    }

    cout << "Your name is " << name << " and your in-game name is " << "[ " + clanTag + " ] " << username + "." << endl;
    cout << "You have " << exp << " experience points." << endl;

    int currentLevel = exp / 100;
    int reqExpPoints = 100 - (exp % 100); // The modulo (%) operator retrieves the remainder from a decimal number.
    int nextLevel = currentLevel + 1;

    cout << "Your current level is " << currentLevel << "." << endl;
    cout << "You need " << reqExpPoints << " points to reach the next level, which is " << nextLevel << "." << endl;
}