#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>

#include "Operation.h"
#include "Utils.h"
#include "File.h"

class OperationFile : public File
{
public:
    OperationFile(string operationFileName) : File(operationFileName) {};
    void addOperationToFile(Operation operation);
    vector <Operation> loadOperationsFromFile();
};

#endif
