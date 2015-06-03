#ifndef FILE_H
#define FILE_H

#include <algorithm>
#include <string>
#include <fstream>

#include <sys/stat.h>

#include "fileutils.h"
#include "fileexception.h"

#define BUFFER_SIZE 1024

class File
{
public:
    File() : File(NULL) {}
    File(const std::string& filename);
    ~File();

    bool exists();
    bool isRegularFile();
    bool isDirectory();

    bool open(std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
    void close();
    void reset();

    bool hasNext();
    char nextChar();
    std::string next();

private:
    std::string mFilename;
    std::fstream mFilestream;
    bool mEOF;
};

#endif // FILE_H
