#include "BudgetManager.h"

void BudgetManager::addIncome(){
    Operation operation;

    operation = addOperationDetails(INCOME);

    incomes.push_back(operation);

    incomeFile.addOperationToFile(operation);

    cout << endl << "Operation added succesfully" << endl << endl;
    system("pause");
    return;


}

void BudgetManager::addExpense(){
    Operation operation;

    operation = addOperationDetails(EXPENSE);

    expenses.push_back(operation);

    expenseFile.addOperationToFile(operation);

    cout << endl << "Operation added succesfully" << endl << endl;
    system("pause");
    return;


}

Operation BudgetManager::addOperationDetails(const Type &type){
    string typeDescription, tempDate, tempAmount;
    Operation operation;

    Menus::showTitle("ADD OPERATION DETAILS");

    switch(type){
    case INCOME:
        operation.id = incomeFile.getLastOperationId() + 1;
        typeDescription = "income";
        break;
    case EXPENSE:
        operation.id = expenseFile.getLastOperationId() + 1;
        typeDescription = "expense";
        break;
    }

    operation.userId = LOGGED_USER_ID;

    do
    {
        cout << "Enter " << typeDescription << " date. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
        if(tempDate == "t") tempDate = DateMethods::convertIntDateToStringWithDashes(DateMethods::getCurrentDate());
    }
    while (!DateMethods::validateDate(tempDate));

    operation.date = DateMethods::convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::readLine();

    do
    {
        cout << "Enter " << typeDescription << " amount with up to two decimal places";
        tempAmount = Utils::readLine();
    }
    while (!CashMethods::validateAmount(tempAmount));

    operation.amount = stod(tempAmount);

    return operation;
}

