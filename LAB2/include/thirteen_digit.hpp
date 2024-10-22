#pragma once

#include "array.hpp"

class ThirteenDigit {
  private:
    unsigned char c;
    int charToValue(unsigned char ch) const;
    unsigned char valueToChar(int value) const;

  public:
    ThirteenDigit();

    ThirteenDigit(unsigned char new_sign);

    ThirteenDigit(const ThirteenDigit &other);

    ThirteenDigit &operator=(const ThirteenDigit &other);

    ThirteenDigit operator+(const ThirteenDigit &other) const;

    ThirteenDigit operator-(const ThirteenDigit &other) const;

    ThirteenDigit &operator+=(const ThirteenDigit &other);

    ThirteenDigit &operator-=(const ThirteenDigit &other);

    ThirteenDigit operator+(unsigned char ch) const;

    ThirteenDigit operator-(unsigned char ch) const;

    ThirteenDigit &operator+=(unsigned char ch);

    ThirteenDigit &operator-=(unsigned char ch);

    bool sumBiggerOrEqualTwelve(const ThirteenDigit &other);

    bool diffLessThanZero(const ThirteenDigit &subtrahend);

    bool operator==(const ThirteenDigit &other) const;

    bool operator!=(const ThirteenDigit &other) const;

    bool operator<(const ThirteenDigit &other) const;

    bool operator<=(const ThirteenDigit &other) const;

    bool operator>(const ThirteenDigit &other) const;

    bool operator>=(const ThirteenDigit &other) const;

    friend std::ostream &operator<<(std::ostream &out, const ThirteenDigit &d);

    void setChar(unsigned char c);

    unsigned char getChar() const;
};