#include "dynarray.hpp"
#include <iostream>

int main() {
    // Test type aliases and basic functionality
    std::cout << "=== Testing Dynamic Array 2.0 ===" << std::endl;
    
    // Test constructors and subscript operator
    Dynarray arr1(5, 42);
    std::cout << "arr1 (size 5, value 42): " << arr1 << std::endl;
    
    // Test subscript operator
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;
    std::cout << "arr1 after modification: " << arr1 << std::endl;
    
    // Test copy and comparison
    Dynarray arr2 = arr1;
    std::cout << "arr2 (copy of arr1): " << arr2 << std::endl;
    std::cout << "arr1 == arr2: " << (arr1 == arr2) << std::endl;
    std::cout << "arr1 != arr2: " << (arr1 != arr2) << std::endl;
    
    // Test relational operators
    arr2[4] = 6;  // Make arr2 > arr1
    std::cout << "arr2 after changing last element to 6: " << arr2 << std::endl;
    std::cout << "arr1 < arr2: " << (arr1 < arr2) << std::endl;
    std::cout << "arr1 <= arr2: " << (arr1 <= arr2) << std::endl;
    std::cout << "arr1 > arr2: " << (arr1 > arr2) << std::endl;
    std::cout << "arr1 >= arr2: " << (arr1 >= arr2) << std::endl;
    
    // Test empty array
    Dynarray empty;
    std::cout << "empty array: " << empty << std::endl;
    std::cout << "empty < arr1: " << (empty < arr1) << std::endl;
    
    // Test iterator range constructor
    int data[] = {10, 20, 30};
    Dynarray arr3(data, data + 3);
    std::cout << "arr3 from array: " << arr3 << std::endl;
    
    // Test different sizes
    Dynarray short_arr(2, 1);
    Dynarray long_arr(3, 1);
    std::cout << "short_arr: " << short_arr << std::endl;
    std::cout << "long_arr: " << long_arr << std::endl;
    std::cout << "short_arr < long_arr: " << (short_arr < long_arr) << std::endl;
    
    std::cout << "=== All tests completed ===" << std::endl;
    return 0;
}