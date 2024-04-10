#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "Utils.h"
#include "File.h"

using namespace std;

class UserFile : public File
{
public:
    UserFile(string userFileName) : File(userFileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif
