#include <iostream>
#include <string>

using namespace std;

string convertToLowercaseText(string text)
{
    cout << "Lowercase: ";

    for (int i = 0; i <= text.length(); i++)
    {
        cout << unsigned char (tolower(text[i]));
    }

    cout << endl;

    return text;
}

string convertToUppercaseText(string text)
{
    cout << "Uppercase: ";

    for (int i = 0; i <= text.length(); i++)
    {
        cout << unsigned char (toupper(text[i]));
    }

    cout << endl;

    return text;
}

string convertToSentenceCase(string text)
{
    cout << "Sentence case: ";

    text[0] = toupper(text[0]); // Prints first character as uppercase

    for (int i = 0; i <= text.length(); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        { 
            i++; // Moves on to the next character

            while (text[i] == ' ')
            {
                i++; // Skips over any spaces
            }
            text[i] = toupper(text[i]); // Capitalises the next character
        }
        else
        {
            text[i] = tolower(text[i]); // Ensures any other characters are lowercase
        }

        continue;
    }

    cout << text << endl;

    return text;
}

string convertToAlternatingCase(string text) // Alternating case should be preserved across whitespace and punctuation,
{
    cout << "Alternating case: ";

    for (int i = 0; i <= text.length(); i++)
    {
        if (i % 2 == 0) // Checks if index is even
        {
            cout << unsigned char(toupper(text[i]));
        }
        else
        {
            cout << unsigned char(tolower(text[i]));
        }
    }

    cout << endl;

    return text;
}

bool bIsInputOnlyNumbers(string text, int i = 0)
{
    if (isdigit(text[i]))
    {
        cerr << "[ERROR] Can't run text casing - only alphabetical characters allowed!" << endl;
        return true;
    }
    else
    {
        cout << "not only digits";
        return false;
    }
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 5" << endl;
    cout << "-----------" << endl;

    string text = "";

    cout << "Please input your text: ";
    getline(cin, text);
    bIsInputOnlyNumbers(text);
    convertToLowercaseText(text);
    convertToUppercaseText(text);
    convertToSentenceCase(text);
    convertToAlternatingCase(text);
    
    return 0;
}

