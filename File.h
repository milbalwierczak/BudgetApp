#ifndef FILE_H
#define FILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class File
{
    const string FILE_NAME;

public:

    string getFileName();

protected:
    File(string fileName) : FILE_NAME(fileName)  {};
};

#endif
