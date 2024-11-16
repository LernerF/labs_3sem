#include "Vector.h"
#include <utility> // Для std::move

template <typename T>
Vector<T>::Vector() : data(nullptr), size_(0), capacity_(1) {
    data = std::make_shared<T[]>(capacity_);
}

template <typename T>
void Vector<T>::grow() {
    capacity_ *= 2;
    auto newData = std::make_shared<T[]>(capacity_);
    for (std::size_t i = 0; i < size_; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        grow();
    }
    data[size_++] = value;
}

template <typename T>
void Vector<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    for (std::size_t i = index; i < size_ - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size_;
}

template <typename T>
T& Vector<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Необходимая строка для явной инстанциации шаблонов
template class Vector<std::shared_ptr<Figure<double>>>;