#include "dynarray.hpp"
#include <iostream>

int main() {
    std::cout << "Creating empty array..." << std::endl;
    Dynarray empty;
    std::cout << "Empty array created successfully" << std::endl;
    
    std::cout << "Testing output operator..." << std::endl;
    std::cout << empty << std::endl;
    
    return 0;
}