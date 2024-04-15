#include "OperationFile.h"

void OperationFile::addOperationToFile(Operation operation)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("Id", operation.id);
    xml.AddElem("UserId", operation.userId);
    xml.AddElem("Date", operation.date);
    xml.AddElem("Item", operation.item);
    xml.AddElem("Amount", operation.amount);

    xml.Save(getFileName().c_str());

    return;
}

/*vector <Operation> OperationFile::loadUsersFromFile()
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
}*/
