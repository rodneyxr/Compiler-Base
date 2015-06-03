#include <iostream>
#include <compiler.h>
#include <fileutils.h>
#include <file.h>

/**
 * This application will ensure that a build script will execute without problems due
 * to an incompatible file structure. It will analyze a build script and attempt to determine the
 * pre-conditions for the file structure and compare it with the post-conditions for the file structure.
 */

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "usage: fileflow <script>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

//    Compiler compiler;
//    compiler.compile(filename);

    File file(filename);
    file.open();

    std::string token;
    while (!(token = file.next()).empty()) {
        std::cout << token << std::endl;
    }

    file.close();

    system("pause");
    return 0;
}
