#include "Menus.h"

void Menus::showMainMenu(){
    showTitle("MAIN MENU");
    cout << "1. Login user" << endl;
    cout << "2. Register user" << endl;
    cout << "9. Exit app" << endl << endl;
    cout << "Choose option: ";
    return;
}

void Menus::showUserMenu(){
    showTitle("USER MENU");
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show current month balance" << endl;
    cout << "3. Show previous month balance" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Logout" << endl << endl;
    cout << "Choose option: ";
    return;

}

void Menus::showTitle(string title){
    system("cls");
    cout << "             >>> " << title << " <<<" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    return;
}


