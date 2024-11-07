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
    bool caps = false;

    cout << "Sentence case: ";

    for (int i = 0; i <= text.length(); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            caps = true;
            i++;
        }
        if ((isalpha(text[i]) && (caps == true)))
        {
            text[i] = toupper(text[i]);
            caps = false;
        }
        else if (isalpha(text[i]))
        {
            text[i] = tolower(text[i]); // Ensures any other characters are lowercase
        }
        
        continue;
    }

    text[0] = toupper(text[0]); // Prints first character as uppercase

    cout << text << endl;

    return text;
}

string convertToAlternatingCase(string text) // Alternating case should be preserved across whitespace and punctuation,
{
    cout << "Alternating case: ";

    //int j = 0;

    //while ((isalpha(text[j])) == false) // Checks if characters entered are non-alphabetic
    //{
    //    j++; // If the program comes across any non-alphabetic characters, it skips over them to ensure the alternating case is preserved across punctuation and whitespace
    //    // I used the index j instead of i for this as j needs to go through the text to check for non-alphabetical characters. i, on the other hand, needs to go through the
    //    // text and actually make the text alternating, as seen in the for loop below.
    //}

    int tracker = 0;

    for (int tracker = 0; tracker < text.length(); tracker++) 
    {
        if (tracker % 2 == 0 && isalpha(text[tracker])) // Checks if index is even
        {
             unsigned char(toupper(text[tracker]));
        }
        else if (isalpha(text[tracker]))
        {
             unsigned char(tolower(text[tracker]));
        }

        
    }

    cout << endl;

    return text;
    cout << text;
}

bool bIsInputAlpha(string text, int i = 0)
{
    if ((isalpha(text[i])) == false) // Checks if characters entered are only numbers or not apart of the alphabet, e.g. punctuation
    {
        cerr << "[ERROR] Can't run text casing - only alphabetical characters allowed!" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int main(int argc, char* argv[])
{
    cout << "CHALLENGE 5" << endl;
    cout << "-----------" << endl;

    string text = "";

    cout << "Please input your text: ";
    getline(cin, text);

    if (!bIsInputAlpha(text))
    {
        return 0;
    }
    
    
    //convertToLowercaseText(text);
    //convertToUppercaseText(text);
    //convertToSentenceCase(text);
    convertToAlternatingCase(text);
    
    return 0;
}

