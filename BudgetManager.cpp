#include "BudgetManager.h"

void BudgetManager::addIncome(){
    Operation operation;

    if (incomes.empty() == true)
        operation.id = 1;
    else
        operation.id = incomes.back().id + 1;

    operation.userId = LOGGED_USER_ID;
    operation.date = 20240415;
    operation.item = "Zakupy";
    operation.amount = 10.50;

    incomes.push_back(operation);

    incomeFile.addOperationToFile(operation);

    cout << endl << "Operation added succesfully" << endl << endl;
    system("pause");
    return;


}
