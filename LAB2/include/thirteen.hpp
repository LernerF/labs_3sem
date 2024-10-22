#pragma once

#include "array.hpp" 
#include "thirteen_digit.hpp"
#include <string>
#include <iostream>

class Thirteen {
  private:
    Array<ThirteenDigit> digits; 

  public:
    Thirteen() = default;

    Thirteen(unsigned int n) {
        while (n > 0) {
            digits.push_back(ThirteenDigit(n % 13));
            n /= 13;
        }
        if (digits.size() == 0) {
            digits.push_back(ThirteenDigit('0')); 
        }
    }

    Thirteen(size_t size, const ThirteenDigit &digit) : digits(size, digit) {}

    Thirteen(const std::initializer_list<ThirteenDigit> &t) : digits(t) {}

    Thirteen(const std::string &str) { initializeFromString(str); }

    Thirteen(const Thirteen &other) { copy(other); }

    Thirteen(Thirteen &&other) noexcept : digits(std::move(other.digits)) {}

    size_t length() const { return digits.size(); }

    std::string toString() const {
        std::string result;
        for (int i = digits.size() - 1; i >= 0; --i) {
            result += digits[i].getChar();  
        }
        return result;
    }

    void initializeFromString(const std::string &str) {
        digits.clear();
        for (int i = str.length() - 1; i >= 0; --i) {
            digits.push_back(ThirteenDigit(str[i]));  
        }
    }

    void copy(const Thirteen &other) {
        digits = other.digits;
    }

    void removeInsignificantZeros(Thirteen &num) {
        while (num.length() > 1 && num.digits.back() == ThirteenDigit('0')) {
            num.digits.pop_back();
        }
    }

    Thirteen &operator=(const Thirteen &other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    }

    Thirteen &operator=(Thirteen &&other) {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }



    Thirteen operator+(const Thirteen &other) const {
        Thirteen result;
        size_t maxLength = std::max(length(), other.length());
        ThirteenDigit carry('0'); // Перенос
        for (size_t i = 0; i < maxLength || carry != ThirteenDigit('0'); ++i) {
            ThirteenDigit digit1 = (i < length()) ? digits[i] : ThirteenDigit('0');
            ThirteenDigit digit2 = (i < other.length()) ? other.digits[i] : ThirteenDigit('0');
            ThirteenDigit sum = digit1 + digit2 + carry;
            carry = (digit1 + digit2).sumBiggerOrEqualThirteen(carry) ? ThirteenDigit('1') : ThirteenDigit('0');
            result.digits.push_back(sum);
        }
        removeInsignificantZeros(result);
        return result;
    }

    Thirteen &operator+=(const Thirteen &other) {
        *this = *this + other;
        return *this;
    }

    Thirteen operator-(const Thirteen &other) const {
        Thirteen result;
        ThirteenDigit borrow('0');
        for (size_t i = 0; i < length(); ++i) {
            ThirteenDigit digit1 = digits[i];
            ThirteenDigit digit2 = (i < other.length()) ? other.digits[i] : ThirteenDigit('0');
            if (digit1.diffLessThanZero(digit2 + borrow)) {
                result.digits.push_back(digit1 - digit2 - borrow + ThirteenDigit('D'));
                borrow = ThirteenDigit('1');
            } else {
                result.digits.push_back(digit1 - digit2 - borrow);
                borrow = ThirteenDigit('0');
            }
        }
        removeInsignificantZeros(result);
        return result;
    }

    Thirteen &operator-=(const Thirteen &other) {
        *this = *this - other;
        return *this;