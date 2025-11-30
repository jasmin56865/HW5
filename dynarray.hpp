#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>

class Dynarray {
private:
    int* data;
    std::size_t length;

public:
    Dynarray() : data(nullptr), length(0) {}
    
    // Explicit constructor with size - creates array of given size with value-initialized elements
    explicit Dynarray(std::size_t n) : data(n > 0 ? new int[n]() : nullptr), length(n) {}
    
    // Constructor with size and initial value
    Dynarray(std::size_t n, int x) : data(n > 0 ? new int[n] : nullptr), length(n) {
        for (std::size_t i = 0; i < length; ++i) {
            data[i] = x;
        }
    }
    
    // Constructor with iterator range
    Dynarray(const int* begin, const int* end) : data((begin <= end && end - begin > 0) ? new int[end - begin] : nullptr), length(begin <= end ? end - begin : 0) {
        for (std::size_t i = 0; i < length; ++i) {
            data[i] = begin[i];
        }
    }
    
    // Copy constructor
    Dynarray(const Dynarray& other) : data(other.length > 0 ? new int[other.length] : nullptr), length(other.length) {
        for (std::size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    
    // Move constructor (noexcept)
    Dynarray(Dynarray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }
    
    // Destructor
    ~Dynarray() {
        delete[] data;
    }
    
    // Copy assignment operator (exception-safe using copy-and-swap idiom)
    Dynarray& operator=(const Dynarray& other) {
        if (this != &other) {  // Self-assignment check
            // Create temporary copy
            Dynarray temp(other);
            // Swap with temporary (noexcept operations)
            std::swap(data, temp.data);
            std::swap(length, temp.length);
            // temp destructor will clean up old resources
        }
        return *this;
    }
    
    // Move assignment operator (noexcept, self-assignment safe)
    Dynarray& operator=(Dynarray&& other) noexcept {
        if (this != &other) {  // Self-assignment check
            // Clean up current resources
            delete[] data;
            
            // Move from other
            data = other.data;
            length = other.length;
            
            // Reset other
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    
    // Returns the size of the array
    std::size_t size() const {
        return length;
    }
    
    // Returns whether the array is empty
    bool empty() const {
        return length == 0;
    }
    
    // Element access with bounds checking (non-const version)
    int& at(std::size_t n) {
        if (n >= length) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return data[n];
    }
    
    // Element access with bounds checking (const version)
    const int& at(std::size_t n) const {
        if (n >= length) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return data[n];
    }
};

#endif // DYNARRAY_HPP