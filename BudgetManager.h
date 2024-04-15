#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "OperationFile.h"

using namespace std;

class BudgetManager
{
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    const int LOGGED_USER_ID;

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
        : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId){};
    void addIncome();

};

#endif
