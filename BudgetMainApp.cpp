#include "BudgetMainApp.h"

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}

void BudgetMainApp::listAllUsers()
{
    userManager.listAllUsers();
}

void BudgetMainApp::logInUser()
{
    userManager.logInUser();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }
}

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::logoutUser()
{
    return userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp::changeUserPassword()
{
    return userManager.changeUserPassword();
}

void BudgetMainApp::addIncome()
{
    return budgetManager->addIncome();
}

void BudgetMainApp::addExpense()
{
    return budgetManager->addExpense();
}
