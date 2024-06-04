// player.cpp
#include "print_namespace.h"  // Includes print.h indirectly
#include <iostream> // Assuming this is needed for print()

namespace print_space {
void print(std::string input) {
    std::cout << input << std::endl;
}
}
