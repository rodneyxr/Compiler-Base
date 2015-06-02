#include "file.h"

File::File(const std::string& filename) {
    this->mFilename = filename;
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
