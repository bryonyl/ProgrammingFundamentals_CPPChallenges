#include <iostream>
#include <string>

using namespace std;

// Checks whether the inputted text contains whitespace or not
bool bOnlyWhitespace(string text)
{
    cin.clear();
    return text.find_first_not_of(" \t\n") == text.npos;
    // text.find_first_not_of(" \t\n") Finds the first character that does not contain whitespace (a space, a tab or a new line)
    // text.npos tells the find_first_not_of function to continue until the end of the string
    // If bOnlyWhitespace returns true, then the text contains only whitespace. If false, it does NOT contain only whitespace.
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 4" << endl;
    cout << "-----------" << endl;

    string text;
    bool bRepeatInput = true;


    while (bRepeatInput = true)
    {
        cout << "\nEnter text: ";
        getline(cin, text); // Reads the whole line of input, so that spaces are included

        for (int i = 0 /*start of the index*/; i < text.length()/*condition*/; i++ /*increment by 1 each time*/)
        {
            cout << "|  " << text[i] << "  ";
        }

        cout << "|";

        while (bOnlyWhitespace(text) == true)
        {
            cerr << "\nError! An empty input is not allowed, please enter text: ";
            getline(cin, text);
            cout << text;
        }
    }
}