#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "OperationFile.h"
#include "DateMethods.h"
#include "CashMethods.h"
#include "Type.h"
#include "Menus.h"

using namespace std;

class BudgetManager
{
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    const int LOGGED_USER_ID;

    Operation addOperationDetails(const Type &type);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
        : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId)
        {
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
        };
    void addIncome();
    void addExpense();

};

#endif
