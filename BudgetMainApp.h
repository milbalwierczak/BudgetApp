#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetMainApp {

    UserManager userManager;

public:
    void registerUser();
    void listAllUsers();
};

#endif
