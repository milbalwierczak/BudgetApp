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
    void logoutUser();
    bool isUserLoggedIn();


};

#endif
