#pragma once

#include <stdexcept>

template <typename T, typename Allocator = std::allocator<T>> class Array {
  private:
    T *_data;
    size_t _size;
    size_t _capacity;
    Allocator allocator;
    using traits = std::allocator_traits<Allocator>;

    void reallocate(size_t newCapacity) {


        T *newData = traits::allocate(allocator, newCapacity);

        if (newCapacity < _size) {
            _size = newCapacity;
        }

        for (size_t i = 0; i < _size; ++i) {
            newData[i] = std::move(_data[i]);
        }

        for (size_t i = 0; i < _size; ++i) {
            _data[i].~T();
        }


        traits::deallocate(allocator, _data, _capacity);
        _data = newData;
        _capacity = newCapacity;
    }

  public:
    Array() : _data(nullptr), _size(0), _capacity(0) { reallocate(2); }
    Array(const Array &other) : _data(nullptr), _size(0), _capacity(0) {
        reallocate(other.capacity());
        for (size_t i = 0; i < other._size; ++i) {
            push_back(other._data[i]);
        }
    }
    Array(Array &&other) noexcept
        : _data(other._data), _size(other._size), _capacity(other._capacity) {
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }
    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }
        clear();
        reallocate(other.capacity());
        for (size_t i = 0; i < other._size; ++i) {
            push_back(other._data[i]);
        }
        return *this;
    }
    Array &operator=(Array &&other) noexcept {
        if (this == &other) {
            return *this;
        }
        clear();
        //::operator delete(_data, _capacity * sizeof(T));
        traits::deallocate(allocator, _data, _capacity);

        _data = other._data;
        _size = other._size;
        _capacity = other._capacity;

        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
        return *this;
    }
    ~Array() noexcept {
        clear();
        //::operator delete(_data, _capacity * sizeof(T));
        traits::deallocate(allocator, _data, _capacity);
    }

    void push_back(const T &value) {
        if (_size >= _capacity) {
            reallocate(_capacity + _capacity / 2);
        }
        _data[_size] = value;
        _size++;
    }

    void push_back(T &&value) {
        if (_size >= _capacity) {
            reallocate(_capacity + _capacity / 2);
        }

        //_data[_size] = std::move(value);
        traits::construct(allocator, &_data[_size], std::move(value));
        _size++;
    }

    template <typename... Args> T &emplace_back(Args &&...constructorArgs) {
        if (_size >= _capacity) {
            reallocate(_capacity + _capacity / 2);
        }

        traits::construct(allocator, &_data[_size],
                          std::forward<Args>(constructorArgs)...);
        return _data[_size++];
    }

    void pop_back() {
        if (_size > 0) {
            _size--;
            _data[_size].~T();
        }
    }

    void clear() {
        for (size_t i = 0; i < _size; ++i) {
            _data[i].~T();
        }
        _size = 0;
    }

    size_t size() const { return _size; }

    size_t capacity() const { return _capacity; }

    const T &operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }
    T &operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }
};