#ifndef COMPILEREXCEPTION
#define COMPILEREXCEPTION

#include <string>
#include <exception>

class compilerexception : public std::exception {

public:
    compilerexception() : compilerexception("an error occurred") {}

    compilerexception(std::string err_message) {
        this->err_message = err_message;
    }

    virtual const char* what() const throw() {
        return this->err_message.c_str();
    }

private:
    std::string err_message;

};

#endif // COMPILEREXCEPTION

