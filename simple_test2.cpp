#include "dynarray.hpp"
#include <iostream>

int main() {
    std::cout << "Testing basic output..." << std::endl;
    
    // Test empty array output
    Dynarray empty;
    std::cout << "Empty array: " << empty << std::endl;
    
    // Test simple array
    Dynarray arr(3, 1);
    std::cout << "Array with 3 ones: " << arr << std::endl;
    
    // Test subscript operator
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::cout << "Modified array: " << arr << std::endl;
    
    std::cout << "Basic test completed!" << std::endl;
    return 0;
}