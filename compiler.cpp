#include "compiler.h"

Compiler::Compiler() {}
Compiler::~Compiler() {}

/**
 * @brief Compiler::compile opens the file and starts parsing
 *
 * @param filename - the name of the file to compile
 * @return true if compiled successfully, false otherwise
 */
bool Compiler::compile(const std::string &filename) {
    File file(filename);
    bool success = false;

    try {
        // assert that the file exists
        if (!file.exists()) {
            std::stringstream message;
            message << "Error: File '" << filename << "' does not exist!";
            throw compilerexception(message.str());
        }

        // open the file for reading text
        std::cout << "opening '" << filename << "'..." << std::endl;
        if (!file.open(std::ios_base::in)) {
            std::stringstream message;
            message << "Error: Unable to open '" << filename << "'";
            throw compilerexception(message.str());
        }

//        parse(file);
        success = true;
    } catch (compilerexception &e) {
        std::cout << "CompilerException: " << e.what() << std::endl;
        success = false;
    }

    // close the file
    std::cout << "File '" << filename << "' closed" << std::endl;
    file.close();

    return success;
}
