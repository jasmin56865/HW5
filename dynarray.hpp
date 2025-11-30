#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <cstddef>
#include <stdexcept>


class Dynarray {
private:
    int* data;
    std::size_t length;

public:
    Dynarray() : data(nullptr), length(0) {}
    
    explicit Dynarray(std::size_t n) : data(n >= 1 ? new int[n]() : nullptr), length(n) {}
    
    Dynarray(std::size_t n, int x) : data(n >= 1 ? new int[n] : nullptr), length(n) {
        for (std::size_t i = 0; i < length; ++i) {
            data[i] = x;
        }
    }
    
    Dynarray(const int* begin, const int* end) : data(( end - begin > 0) ? new int[end - begin] : nullptr), length(begin <= end ? end - begin : 0) {
        for (std::size_t i = 0; i < length; ++i) {
            data[i] = begin[i];
        }
    }
    
    Dynarray(const Dynarray& other) : data(other.length > 0 ? new int[other.length] : nullptr), length(other.length) {
        for (std::size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    
    Dynarray(Dynarray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }
    
    ~Dynarray() {
        delete[] data;
    }
    
    Dynarray& operator=(const Dynarray& other) {
        if (this == &other) {
            return *this;
        }
        int* new_data = nullptr;
        if (other.length > 0) {
            new_data = new int[other.length]; 
        }
        for (std::size_t i = 0; i < other.length; ++i) {
            new_data[i] = other.data[i];
        }
        delete[] data;
        data = new_data;
        length = other.length;
        return *this;
    }
    
    Dynarray& operator=(Dynarray&& other) noexcept {
        if (this != &other) {  
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    
    std::size_t size() const {
        return length;
    }
    
    bool empty() const {
        return length == 0;
    }
    
    int& at(std::size_t n) {
        if (n >= length) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return data[n];
    }
    
    const int& at(std::size_t n) const {
        if (n >= length) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return data[n];
    }
};

#endif 