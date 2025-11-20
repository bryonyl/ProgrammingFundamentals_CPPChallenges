#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "RandomCalculationsChallenge" << endl;
    cout << "---------------------------" << endl;

    float x = 0; // Initialising x with 0 to avoid problems in the future.

    cout << "Enter a number: " << endl;
    cin >> x;

    if (cin.fail()) // If the input data type does not match with the required data type
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cerr << "Error! Invalid input - please input a number, not a string. Exiting." << endl;
        exit(404); // Exits the program with the error code 404
    }

    cout << "neg(" << x << "): " << -x << endl; // Negation of x
    cout << "abs(" << x << "): " << abs(x) << endl; // Absolute value of x
    cout << "pow2(" << x << "): " << pow(x, 2) << endl; // x squared
    cout << "pow3(" << x << "): " << pow(x, 3) << endl; // x cubed
    cout << "sqrt(" << x << "): " << sqrt(abs(x)) << endl; // Square root of x
    cout << "floor(" << x << "): " << floor(x) << endl; // The floor of x
    cout << "ceil(" << x << "): " << ceil(x) << endl; // The ceiling of x
    cout << "round(" << x << "): " << round(x) << endl; // x rounded

    return 0;
}