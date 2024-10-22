#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

class Thirteen {
private:
    std::vector<unsigned char> digits;

public:
    Thirteen() : digits(1, 0) {}

    Thirteen(unsigned int value) {
        while (value > 0) {
            digits.push_back(value % 13);
            value /= 13;
        }
        if (digits.empty()) {
            digits.push_back(0);
        }
    }

    Thirteen(const Thirteen &other) : digits(other.digits) {}

    Thirteen(Thirteen &&other) noexcept : digits(std::move(other.digits)) {}

    Thirteen &operator=(const Thirteen &other) {
        if (this != &other) {
            digits = other.digits;
        }
        return *this;
    }

    Thirteen &operator=(Thirteen &&other) noexcept {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }

    ~Thirteen() = default;

    Thirteen operator+(const Thirteen &other) const {
        Thirteen result;
        result.digits.clear();
        size_t maxSize = std::max(digits.size(), other.digits.size());
        unsigned char carry = 0;

        for (size_t i = 0; i < maxSize || carry > 0; ++i) {
            unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
            unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;
            unsigned char sum = digit1 + digit2 + carry;
            carry = sum / 13;
            result.digits.push_back(sum % 13);
        }

        return result;
    }

    void print() const {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            std::cout << static_cast<int>(*it);
        }
        std::cout << std::endl;
    }
    
    void push_back(unsigned char digit) {
        if (digit >= 13) {
            throw std::out_of_range("Invalid digit for base-13 system");
        }
        digits.push_back(digit);
    }

    unsigned char operator[](size_t index) const {
        if (index >= digits.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return digits[index];
    }

    size_t size() const {
        return digits.size();
    }
};
