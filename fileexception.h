#ifndef FILEEXCEPTION
#define FILEEXCEPTION

#include <string>
#include <exception>

class FileException : public std::exception {

public:
    FileException() : FileException("an error occurred") {}

    FileException(std::string err_message) {
        this->err_message = err_message;
    }

    virtual const char* what() const throw() {
        return this->err_message.c_str();
    }

private:
    std::string err_message;

};

#endif // FILEEXCEPTION

