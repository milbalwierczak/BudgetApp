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
        cout << "Enter " << typeDescription << " date in 'yyyy-mm-dd' format. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
        if(tempDate == "t") tempDate = DateMethods::convertIntDateToStringWithDashes(DateMethods::getCurrentDate());
    }
    while (!DateMethods::validateDate(tempDate));

    operation.date = DateMethods::convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::readLine();

    do
    {
        cout << "Enter " << typeDescription << " amount with up to two decimal places: ";
        tempAmount = Utils::readLine();
    }
    while (!CashMethods::validateAmount(tempAmount));

    operation.amount = stod(tempAmount);

    return operation;
}

void BudgetManager::showBalance(int startDate, int endDate){
    int counter = 0;
    cout << "             >>> Incomes <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    if (!incomes.empty())
    {
        for (vector <Operation> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if((*itr).date >= startDate && (*itr).date <= endDate) {
                showOperation(*itr);
                counter++;
            }
        }
        cout << endl;
    }

    if (counter == 0)
    {
        cout << "No incomes for given period." << endl << endl;
    }

    counter = 0;
    cout << "             >>> Expenses <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    if (!expenses.empty())
    {
        for (vector <Operation> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if((*itr).date >= startDate && (*itr).date <= endDate){
                showOperation(*itr);
                counter++;
            }
        }
        cout << endl;
    }

    if (counter == 0)
    {
        cout << "No expenses for given period." << endl << endl;
    }

    cout << "TOTAL BALANCE: " << setprecision(2) << fixed << calculateBalance(startDate, endDate) << endl << endl;
    system("pause");
}

void BudgetManager::showOperation(Operation operation){
    cout << "ID: " << operation.id;
    cout << ", Date: " << DateMethods::convertIntDateToStringWithDashes(operation.date);
    cout << ", Item: " << operation.item;
    cout << ", Amount: " << setprecision(2) << fixed << operation.amount << endl;
    return;
}

void BudgetManager::showCurrentMonthBalance(){
    Menus::showTitle("Current Month Balance");
    showBalance(DateMethods::getCurrentMonthFirstDayDate(), DateMethods::getCurrentMonthLastDayDate());
}

void BudgetManager::showPreviousMonthBalance(){
    Menus::showTitle("Previous Month Balance");
    showBalance(DateMethods::getPreviousMonthFirstDayDate(), DateMethods::getPreviousMonthLastDayDate());
}

void BudgetManager::showCustomPeriodBalance(){
    int startDate, endDate;
    string tempDate;

    Menus::showTitle("Custom Period Balance");

    do
    {
        cout << "Enter start date in 'yyyy-mm-dd' format. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
        if(tempDate == "t") tempDate = DateMethods::convertIntDateToStringWithDashes(DateMethods::getCurrentDate());
    }
    while (!DateMethods::validateDate(tempDate));

    startDate = DateMethods::convertStringDateToInt(tempDate);

    do
    {
        cout << "Enter end date in 'yyyy-mm-dd' format. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
        if(tempDate == "t") tempDate = DateMethods::convertIntDateToStringWithDashes(DateMethods::getCurrentDate());
    }
    while (!DateMethods::validateDate(tempDate));

    endDate = DateMethods::convertStringDateToInt(tempDate);


    showBalance(startDate, endDate);
}

double BudgetManager::calculateBalance(int startDate, int endDate){
    double balance;

    if (!incomes.empty())
    {
        for (vector <Operation> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if((*itr).date >= startDate && (*itr).date <= endDate) {
                balance +=(*itr).amount;
            }
        }
    }

    if (!expenses.empty())
    {
        for (vector <Operation> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if((*itr).date >= startDate && (*itr).date <= endDate){
                balance -=(*itr).amount;
            }
        }
    }

    return balance;
}
