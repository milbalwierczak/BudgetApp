#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    /*Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);*/

    User setNewUserData();
    bool ifLoginExists(string login);
    int getNewUserId();

public:
    UserManager(string userFileName) : userFile(userFileName)
    {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    };
    int getLoggedUserId();
    void registerUser();
    void listAllUsers();
    void logInUser();
    bool isUserLoggedIn();


};

#endif
