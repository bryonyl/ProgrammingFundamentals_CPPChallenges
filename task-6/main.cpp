#include "main.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 6" << endl;
    cout << "-----------" << endl;

    int guess = 0;
    int randomNum = random(0, 100);
    
    int totalGuesses = 0;
    bool bPlayerWon = false;

    cout << "Psst! The correct answer is " << randomNum << endl;

    while (bPlayerWon == false)
    {
        cout << "Guess what the random number is: ";
        cin >> guess;
        cout << endl;

        totalGuesses++;

        int difference = abs(guess - randomNum);
        cout << difference;

        if (difference >= 50)
        {
            cout << "Freezing" << endl;
        }
        else if (35 <= difference && difference < 50)
        {
            cout << "Colder" << endl;
        }
        else if (25 <= difference && difference < 35)
        {
            cout << "Cold" << endl;
        }
        else if (15 <= difference && difference < 25)
        {
            cout << "Warm" << endl;
        }
        else if (10 <= difference && difference < 15)
        {
            cout << "Warmer" << endl;
        }
        else if (5 <= difference && difference < 10)
        {
            cout << "Hot" << endl;
        }
        else if (3 <= difference && difference < 5)
        {
            cout << "Hotter" << endl;
        }
        else if (1 <= difference && difference <= 2)
        {
            cout << "Boiling" << endl;
        }
        else if (guess == randomNum)
        {
            bPlayerWon = true;
            cout << "Correct! You Win!" << endl;
            cout << "Total number of guesses: " << totalGuesses << endl;
            exit(0);
        }
    }
    return 0;
}