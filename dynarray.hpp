#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Dynarray {
public:
    // Type alias members
    using size_type = std::size_t;
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    using const_pointer = const int*;
    using const_reference = const int&;

private:
    pointer data;
    size_type length;

public:
    Dynarray() : data(nullptr), length(0) {}
    
    explicit Dynarray(size_type n) : data(n > 0 ? new value_type[n]() : nullptr), length(n) {}
    
    Dynarray(size_type n, const value_type& x) : data(n > 0 ? new value_type[n] : nullptr), length(n) {
        for (size_type i = 0; i < length; ++i) {
            data[i] = x;
        }
    }
    
    Dynarray(const_pointer begin, const_pointer end) : data((end - begin > 0) ? new value_type[end - begin] : nullptr), length(begin <= end ? end - begin : 0) {
        for (size_type i = 0; i < length; ++i) {
            data[i] = begin[i];
        }
    }
    
    Dynarray(const Dynarray& other) : data(other.length > 0 ? new value_type[other.length] : nullptr), length(other.length) {
        for (size_type i = 0; i < length; ++i) {
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
        pointer new_data = nullptr;
        if (other.length > 0) {
            new_data = new value_type[other.length];
        }
        for (size_type i = 0; i < other.length; ++i) {
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
    
    size_type size() const {
        return length;
    }
    
    bool empty() const {
        return length == 0;
    }
    
    reference at(size_type n) {
        if (n >= length) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return data[n];
    }
    
    const_reference at(size_type n) const {
        if (n >= length) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return data[n];
    }
    
    // Subscript operator (no bounds checking)
    reference operator[](size_type n) {
        return data[n];
    }
    
    const_reference operator[](size_type n) const {
        return data[n];
    }
    
    // Friend declarations for relational operators
    friend bool operator==(const Dynarray& lhs, const Dynarray& rhs);
    friend bool operator<(const Dynarray& lhs, const Dynarray& rhs);
};

// Relational operators (using standard library algorithms)
bool operator==(const Dynarray& lhs, const Dynarray& rhs) {
    return std::equal(lhs.data, lhs.data + lhs.size(), rhs.data, rhs.data + rhs.size());
}

bool operator!=(const Dynarray& lhs, const Dynarray& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Dynarray& lhs, const Dynarray& rhs) {
    return std::lexicographical_compare(lhs.data, lhs.data + lhs.size(),
                                       rhs.data, rhs.data + rhs.size());
}

bool operator<=(const Dynarray& lhs, const Dynarray& rhs) {
    return !(rhs < lhs);
}

bool operator>(const Dynarray& lhs, const Dynarray& rhs) {
    return rhs < lhs;
}

bool operator>=(const Dynarray& lhs, const Dynarray& rhs) {
    return !(lhs < rhs);
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Dynarray& arr) {
    os << '[';
    if (!arr.empty()) {
        for (Dynarray::size_type i = 0; i + 1 < arr.size(); ++i) {
            os << arr[i] << ", ";
        }
        os << arr[arr.size() - 1];
    }
    os << ']';
    return os;
}

#endif