#include <iostream>
#include <compiler.h>
#include <fileutils.h>

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

    // print out the number of arguments
//     std::cout << "Number of Args: " << argc << std::endl;

    // print all arguments
//    for (int i = 0; i < argc; i++) {
//        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
//    }

    std::string filename = argv[1];

    Compiler compiler;
    compiler.compile(filename);

    system("pause");
    return 0;
}
