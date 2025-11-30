#include "dynarray.hpp"
#include <iostream>

int main() {
    // Test basic functionality
    std::cout << "Testing basic functionality..." << std::endl;
    
    // Test empty array
    Dynarray empty;
    std::cout << "Empty array: " << empty << std::endl;
    
    // Test array with values
    int arr[] = {1, 2, 3};
    Dynarray a(arr, arr + 3);
    std::cout << "Array a: " << a << std::endl;
    
    // Test subscript operator
    a[0] = 10;
    std::cout << "After a[0] = 10: " << a << std::endl;
    
    // Test comparison
    Dynarray b(arr, arr + 3);
    b[0] = 10;
    std::cout << "Array b: " << b << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    
    // Test lexicographical comparison
    Dynarray c(2, 1);
    Dynarray d(3, 1);
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    
    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}