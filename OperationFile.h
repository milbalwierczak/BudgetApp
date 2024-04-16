#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "Utils.h"
#include "File.h"

class OperationFile : public File
{
    int lastOperationId;
public:
    OperationFile(string operationFileName) : File(operationFileName) {
    lastOperationId = 0; };
    void addOperationToFile(Operation operation);
    vector <Operation> loadOperationsFromFile(const int loggedUserId);
    int getLastOperationId();
};

#endif
