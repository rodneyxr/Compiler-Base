#ifndef COMPILER_H
#define COMPILER_H

#define DEBUG 1
#if DEBUG
#include <iostream>
#endif

#include <string>
#include <sstream>
#include <fstream>

#include "file.h"
#include "compilerexception.h"

class Compiler
{
public:
    Compiler();
    ~Compiler();

    bool compile(const std::string &filename);
};

#endif // COMPILER_H
