#include <iostream>
#include "BudgetMainApp.h"
#include "Menus.h"
#include "Utils.h"


using namespace std;

int main()
{
    char choice;
    while(true)
    {
        Menus::showMainMenu();
        choice = Utils::getCharacter();

        switch(choice)
        {
        case '9':
            cout << "\nSee you next time!\n" << endl;
            exit(0);
            break;
        default:
            cout << "\nCharacter not used. Try again.\n" << endl;
            system("pause");
            break;
        }
    }
    return 0;
}
