#pragma once
#include <memory>
#include <stdexcept>

template <typename T>
class Vector {
private:
    std::shared_ptr<T[]> data;
    std::size_t size_;
    std::size_t capacity_;

    void grow();

public:
    Vector();
    ~Vector() = default;

    void push_back(const T& value);
    void erase(std::size_t index);
    std::size_t size() const { return size_; }
    T& operator[](std::size_t index);
};