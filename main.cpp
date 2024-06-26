#include <iostream>
#include "BudgetMainApp.h"
#include "Menus.h"
#include "Utils.h"


using namespace std;

int main()
{
    char choice;
    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");

    while(true)
    {
        if(!budgetMainApp.isUserLoggedIn())
        {
            Menus::showMainMenu();
            choice = Utils::getCharacter();

            switch(choice)
            {
            case '1':
                budgetMainApp.logInUser();
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
        else
        {
            Menus::showUserMenu();
            choice = Utils::getCharacter();

            switch(choice)
            {
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.showCurrentMonthBalance();
                break;
            case '4':
                budgetMainApp.showPreviousMonthBalance();
                break;
            case '5':
                budgetMainApp.showCustomPeriodBalance();
                break;
            case '6':
                budgetMainApp.changeUserPassword();
                break;
            case '9':
                budgetMainApp.logoutUser();
                break;
            default:
                cout << "\nCharacter not used. Try again.\n" << endl;
                system("pause");
                break;

            }
        }
    }
    return 0;
}
