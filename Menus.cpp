#include "Menus.h"

void Menus::showMainMenu(){
    system("cls");
    cout << "----    MAIN MENU   ----" << endl << endl;
    cout << "1. Login user" << endl;
    cout << "2. Register user" << endl;
    cout << "9. Exit app" << endl << endl;
    cout << "Choose option: ";

}

void Menus::showUserMenu(){
    system("cls");
    cout << "----    USER MENU   ----" << endl << endl;
    cout << "1. Add operation" << endl;
    cout << "2. Show balance" << endl;
    cout << "9. Logout" << endl << endl;
    cout << "Choose option: ";

}
