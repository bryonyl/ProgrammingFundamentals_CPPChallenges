#include "main.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    ////The project is currently set up with a function to produce random numbers between
    ////intervals that you specify. Modify the current solution to provide the functionality
    ////requested by the document that outlines the challenges.
    //
    ////Here is an example just showing how you use the random(min, max) function:
    //std::cout << "Here is a random number between 1 and 10: " << random(1, 10) << std::endl;
    //std::cout << "And here is one between -3 and -5: " << random(-3, -5) << std::endl;

    //return 0;

    cout << "CHALLENGE 6" << endl;
    cout << "-----------" << endl;

    int guess = 1;
    int randomNum = /*random(0, 100);*/ 56;
    int difference = abs(guess - randomNum);
    int totalGuesses = 0;
    bool bPlayerWon = false;

    cout << "Psst! The correct answer is " << randomNum << endl;

    while (bPlayerWon == false)
    {
        cout << "Guess what the random number is: ";
        cin >> guess;
        cout << endl;

        totalGuesses++;

        if (difference >= 50)
        {
            cout << "Freezing";
            break;
        }
        else if (35 <= difference < 50)
        {
            cout << "Colder";
            break;
        }
        else if (25 <= difference < 35)
        {
            cout << "Cold";
            break;
        }
        else if (15 <= difference < 25)
        {
            cout << "Warm";
            break;
        }
        else if (10 <= difference < 15)
        {
            cout << "Warmer";
            break;
        }
        else if (5 <= difference < 10)
        {
            cout << "Hot";
            break;
        }
        else if (3 <= difference < 5)
        {
            cout << "Hotter";
            break;
        }
        else if (1 <= difference <= 2)
        {
            cout << "Boiling";
            break;
        }
        else if (guess == 0)
        {
            guess == 0;
            cout << "Correct! You Win!";
            cout << "Total number of guesses: " << totalGuesses << endl;
            exit(0);
        }

        
        }
}
   
/*switch (guess)
        {
        case freezing:
            difference >= 50;
            cout << "Freezing";

        case 2:
            guess == (35 <= difference < 50);
            cout << "Colder";

        case 3:
            guess == (25 <= difference < 35);
            cout << "Cold";

        case 4:
            guess == (15 <= difference < 25);
            cout << "Warm";

        case 5:
            guess == (10 <= difference < 15);
            cout << "Warmer";

        case 6:
            guess == (5 <= difference < 10);
            cout << "Hot";

        case 7:
            guess == (3 <= difference < 5);
            cout << "Hotter";

        case 8:
            guess == (1 <= difference <= 2);
            cout << "Boiling";

        case 9:
            guess == randomNum;
            cout << "Correct! You Win!";
            cout << "Total number of guesses: " << totalGuesses << endl;
            exit(0);*/