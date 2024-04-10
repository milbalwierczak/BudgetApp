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


