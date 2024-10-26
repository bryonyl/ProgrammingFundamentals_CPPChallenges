#include <iostream>
#include <string>

using namespace std;

// Checks whether the inputted text contains whitespace or not
bool bOnlyWhitespace(string text)
{
    return text.find_first_not_of(" \t\n") == text.npos;
    // text.find_first_not_of(" \t\n") Finds the first character that does not contain whitespace (a space, a tab or a new line)
    // text.npos tells the find_first_not_of function to continue until the end of the string
    // If bOnlyWhitespace returns true, then the text contains only whitespace. If false, it does NOT contain only whitespace.
}

string applyAsciiArt(string text)
{
    for (int i = 0 /*start of the index*/; i < text.length() /*condition*/; i++ /*increment by 1 each time*/)
    {
        cout << "+=-=-=";
    }

    cout << "+" << endl;

    for (int i = 0; i < text.length(); i++)
    {
        cout << "|  " << text[i] << "  ";
    }

    cout << "|" << endl;

    for (int i = 0; i < text.length(); i++)
    {
        cout << "+=-=-=";
    }

    cout << "+" << endl;

    return text;
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 4" << endl;
    cout << "-----------" << endl;

    string text;

    cout << "\nEnter text: ";
    getline(cin, text); // Reads the whole line of input, so that spaces are included

    while (bOnlyWhitespace(text) == false)
    {
        applyAsciiArt(text);
        cout << "\nEnter text: ";
        getline(cin, text);
    }

    while (bOnlyWhitespace(text) == true)
    {
        cerr << "\nError! An empty input is not allowed! Please try again.";
        cout << "\nEnter text: ";
        getline(cin, text);
    }
}