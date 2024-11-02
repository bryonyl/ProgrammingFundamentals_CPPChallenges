#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string convertToLowercaseText(string text)
{
    for (int i = 0; i <= text.length(); i++)
    {
        char currentChar = text[i];
        cout << text[i];
        //string lowercaseText = tolower(8, currentChar);
    }

    return text;
}

string convertToUppercaseText(string text)
{
    return text;
}

string convertToSentenceCase(string text) // Characters should be uppercase only if: 1. it is the first letter of the sentence,
                                          // 2. The character is alphanumeroic and perceded by either a periodmexlamanatiom aro on question mark
{
    return text;
}

string convertToAlternatingCase(string text) // Alternating case should be preserved across whitespace and punctuation,
{
    return text;
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 5";
    cout << "-----------";

    string text = "";
    cout << "Please input your text: ";
    getline(cin, text);
    convertToLowercaseText(text);
    
    return 0;
}

