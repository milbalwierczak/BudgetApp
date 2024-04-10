#include "UserFile.h"

void UserFile::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.AddElem("FirstName", user.firstName);
    xml.AddElem("LastName", user.lastName);

    xml.Save(getFileName().c_str());
}

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    if (xml.Load(getFileName().c_str()))
    {

        xml.FindElem("Users");
        xml.IntoElem();

        while (xml.FindElem("User"))
        {
            xml.IntoElem();

            xml.FindElem("Id");
            user.id = stoi(xml.GetData());
            xml.FindElem("Login");
            user.login = xml.GetData();
            xml.FindElem("Password");
            user.password = xml.GetData();
            xml.FindElem("FirstName");
            user.firstName = xml.GetData();
            xml.FindElem("LastName");
            user.lastName = xml.GetData();

            users.push_back(user);

            xml.OutOfElem();
        }
    }

    return users;
}
