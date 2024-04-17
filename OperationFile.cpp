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
    xml.AddElem("UserId", operation.userId);
    xml.AddElem("Id", operation.id);
    xml.AddElem("Date", operation.date);
    xml.AddElem("Item", operation.item);
    xml.AddElem("Amount", to_string(operation.amount));

    xml.Save(getFileName().c_str());

    lastOperationId++;

    return;
}

vector <Operation> OperationFile::loadOperationsFromFile(const int loggedUserId)
{
    vector <Operation> operations;
    Operation operation;
    CMarkup xml;

    if (xml.Load(getFileName().c_str()))
    {
        xml.FindElem("Operations");
        xml.IntoElem();

        while (xml.FindElem("Operation"))
        {
            lastOperationId++;
            xml.IntoElem();
            xml.FindElem("UserId");

            if(stoi(xml.GetData()) == loggedUserId)
            {
                operation.userId = stoi(xml.GetData());
                xml.FindElem("Id");
                operation.id = stoi(xml.GetData());
                xml.FindElem("Date");
                operation.date = stoi(xml.GetData());
                xml.FindElem("Item");
                operation.item = xml.GetData();
                xml.FindElem("Amount");
                operation.amount = stod(xml.GetData());

            operations.push_back(operation);
            }
            xml.OutOfElem();

        }

    xml.Save(getFileName().c_str());
    }

    return operations;
}

int OperationFile::getLastOperationId(){
    return lastOperationId;
}
