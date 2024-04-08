#include "Utils.h"

string Utils::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char Utils::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Please enter again." << endl;
    }
    return character;
}
