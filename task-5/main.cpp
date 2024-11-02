#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string convertToLowercaseText(string text)
{
    cout << "Lowercase: ";
    for (int i = 0; i <= text.length(); i++)
    {
        unsigned char lowercase (tolower(text[i]));
        cout << lowercase;
    }
    cout << endl;
    return text;
}

string convertToUppercaseText(string text)
{
    cout << "Uppercase: ";
    for (int i = 0; i <= text.length(); i++)
    {
        unsigned char uppercase(toupper(text[i]));
        cout << uppercase;
    }
    cout << endl;
    return text;
}

string convertToSentenceCase(string text) // Characters should be uppercase only if: 1. it is the first letter of the sentence,
                                          // 2. The character is alphanumeroic and perceded by either a periodmexlamanatiom aro on question mark
{
    cout << "Sentence case: ";
    unsigned char firstChar (toupper(text[0])); // Prints the first character of the sentence as uppercase
    cout << firstChar;

    for (int i = 0; i <= text.length(); i++)
    {
        if (text[i] == '!')
        {
            text[i] = text[i - 1]; // Shifts array elements to the right, making room for a space
        }
        else
        {
            cout << "Criteria not fulfilled";
        }
        text[i] = ' ';
        cout << text[i]; // Print the whole string ?
        break;
    }
    return text;
}

string convertToAlternatingCase(string text) // Alternating case should be preserved across whitespace and punctuation,
{
    return text;
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 5" << endl;
    cout << "-----------" << endl;

    string text = "";

    cout << "Please input your text: ";
    getline(cin, text);
    convertToLowercaseText(text);
    convertToUppercaseText(text);
    convertToSentenceCase(text);
    
    return 0;
}

