#include <iostream>
#include "BudgetMainApp.h"
#include "Menus.h"
#include "Utils.h"


using namespace std;

int main()
{
    char choice;
    BudgetMainApp budgetMainApp("users.xml");

    while(true)
    {
        Menus::showMainMenu();
        choice = Utils::getCharacter();

        switch(choice)
        {
        case '1':
            budgetMainApp.listAllUsers();
            break;
         case '2':
            budgetMainApp.registerUser();
            break;
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
