#include "dynarray.hpp"
#include <iostream>

int main() {
    std::cout << "Creating empty array..." << std::endl;
    Dynarray empty;
    std::cout << "Empty array created successfully" << std::endl;
    
    std::cout << "Testing subscript operator..." << std::endl;
    Dynarray arr(3, 1);
    arr[0] = 10;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    
    std::cout << "Testing comparison..." << std::endl;
    Dynarray arr2(3, 1);
    std::cout << "arr == arr2: " << (arr == arr2) << std::endl;
    
    return 0;
}