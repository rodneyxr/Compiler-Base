#include "file.h"

File::File(const std::string& filename) {
    this->mFilename = filename;
    this->mEOF = false;
}

File::~File() {
    this->close();
}

bool File::exists() {
    return FileUtils::exists(this->mFilename);
}

bool File::isRegularFile() {
    return FileUtils::isRegularFile(this->mFilename);
}

bool File::isDirectory() {
    return FileUtils::isDirectory(this->mFilename);
}

bool File::open(std::ios_base::openmode mode) {
    this->mFilestream.open(this->mFilename, mode);
    return this->mFilestream.is_open();
}

void File::close() {
    this->mFilestream.close();
}

void File::reset() {
    this->mEOF = false;
    this->mFilestream.clear();
    this->mFilestream.seekg(0, std::ios::beg);
}

/**
 * @brief File::nextChar
 * @return the next character in the file or '\0' if EOF is reached.
 */
char File::nextChar() {
    char c;
    if (!(this->mFilestream >> std::noskipws >> c)) {
        if (this->mEOF) {
            throw FileException("attempt to read after eof");
        }
        this->mEOF = true;
        return '\0';
    }

    return c;
}

/**
 * @brief File::next reads until next white space
 * @return next token represented as a std::string
 */
std::string File::next() {
    std::string token = "";
    char c;
    while (!isspace(c = nextChar()) && !this->mEOF) {
        token.push_back(c);
    }
    return token;
}
