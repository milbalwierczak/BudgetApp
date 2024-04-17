#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"


using namespace std;

class BudgetMainApp {

    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;


public:
    BudgetMainApp(string userFileName, string incomeFileName, string expenseFileName)
        : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
        {
            budgetManager = NULL;
        };

    ~BudgetMainApp()
        {
            delete budgetManager;
            budgetManager = NULL;
        };

    void registerUser();
    void listAllUsers();
    void logInUser();
    bool isUserLoggedIn();
    void logoutUser();
    void changeUserPassword();

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
};

#endif
