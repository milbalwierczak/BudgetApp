#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "Utils.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;

    /*Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);*/

    User setNewUserData();
    bool ifLoginExists(string login);
    int getNewUserId();

public:
    UserManager()
    {
        loggedUserId = 0;
    };
    int getLoggedUserId();
    void registerUser();
    void listAllUsers();
    void logInUser();
    bool isUserLoggedIn();


};

#endif
