#ifndef FILEUTILS
#define FILEUTILS

#include <string>
#include <sys/stat.h>


class FileUtils
{

public:
    /**
     * @brief File::exists tells whether a file exists
     * @param filename - the name of the file
     * @return true if the file exists
     */
    static bool exists(const std::string& filename) {
        struct stat buffer;
        return exists(filename, buffer);
    }

    static bool isRegularFile(const std::string& filename) {
        struct stat buffer;
        return exists(filename, buffer) && S_ISREG(buffer.st_mode);
    }

    static bool isDirectory(const std::string& filename) {
        struct stat buffer;
        return exists(filename, buffer) && S_ISDIR(buffer.st_mode);
    }

private:
    static bool exists(const std::string& filename, struct stat &buffer) {
        return (stat(filename.c_str(), &buffer) == 0);
    }

};

#endif // FILEUTILS
