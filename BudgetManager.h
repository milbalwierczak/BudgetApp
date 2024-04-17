#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

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
    void showBalance(int startDate, int endDate);
    void showOperation(Operation operation);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
        : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId)
        {
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
        };
    ~BudgetManager(){
        incomes.clear();
        expenses.clear();
    }
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();

};

#endif
