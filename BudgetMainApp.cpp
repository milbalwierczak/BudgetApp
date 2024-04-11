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
}

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

