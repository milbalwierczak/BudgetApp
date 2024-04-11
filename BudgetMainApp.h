#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetMainApp {

    UserManager userManager;

public:
    BudgetMainApp(string userFileName) : userManager(userFileName) {};
    void registerUser();
    void listAllUsers();
    void logInUser();
    bool isUserLoggedIn();
    void logoutUser();
};

#endif
