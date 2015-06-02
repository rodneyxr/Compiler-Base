#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

#include <sys/stat.h>

#include "fileutils.h"

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

private:
    std::string mFilename;
    std::fstream mFilestream;

};

#endif // FILE_H
