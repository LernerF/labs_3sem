#include <iostream>
#include <stdexcept>

class ThirteenDigit {
private:
    unsigned char c; // символ для хранения цифры

public:
    // Конструкторы
    ThirteenDigit() : ThirteenDigit('0') {}
    ThirteenDigit(unsigned char c) { setChar(c); }
    ThirteenDigit(const ThirteenDigit &other) { *this = other; }

    // Преобразование символа в значение
    int charToValue(unsigned char ch) const {
        if (ch >= '0' && ch <= '9') {
            return ch - '0'; // '0' -> 0, ..., '9' -> 9
        } else if (ch == 'A') {
            return 10;       // 'A' -> 10
        } else if (ch == 'B') {
            return 11;       // 'B' -> 11
        } else if (ch == 'C') {
            return 12;       // 'C' -> 12
        } else {
            throw std::invalid_argument("Invalid character for base-13 system");
        }
    }

    // Преобразование значения в символ
    unsigned char valueToChar(int value) const {
        if (value >= 0 && value <= 9) {
            return '0' + value; // 0 -> '0', ..., 9 -> '9'
        } else if (value == 10) {
            return 'A';         // 10 -> 'A'
        } else if (value == 11) {
            return 'B';         // 11 -> 'B'
        } else if (value == 12) {
            return 'C';         // 12 -> 'C'
        } else {
            throw std::invalid_argument("Invalid value for base-13 system");
        }
    }

    // Операторы присваивания и арифметические операции
    ThirteenDigit &operator=(const ThirteenDigit &other) {
        setChar(other.c);
        return *this;
    }

    ThirteenDigit operator+(const ThirteenDigit &other) const {
        ThirteenDigit res = *this;
        return res += other;
    }

    ThirteenDigit operator-(const ThirteenDigit &other) const {
        ThirteenDigit res = *this;
        return res -= other;
    }

    ThirteenDigit &operator+=(const ThirteenDigit &other) {
        return *this += other.c;
    }

    ThirteenDigit &operator-=(const ThirteenDigit &other) {
        return *this -= other.c;
    }

    ThirteenDigit operator+(unsigned char ch) const {
        ThirteenDigit res = *this;
        return res += ch;
    }

    ThirteenDigit operator-(unsigned char ch) const {
        ThirteenDigit res = *this;
        return res -= ch;
    }

    ThirteenDigit &operator+=(unsigned char ch) {
        int current_value = charToValue(c);
        int add_value = charToValue(ch);
        int new_value = (current_value + add_value) % 13;
        c = valueToChar(new_value);
        return *this;
    }

    ThirteenDigit &operator-=(unsigned char ch) {
        int current_value = charToValue(c);
        int sub_value = charToValue(ch);
        int new_value = (current_value - sub_value + 13) % 13;
        c = valueToChar(new_value);
        return *this;
    }

    // Логические операторы
    bool sumBiggerOrEqualThirteen(const ThirteenDigit &other) {
        int digit1_value = charToValue(c);
        int digit2_value = charToValue(other.getChar());
        return (digit1_value + digit2_value) >= 13;
    }

    bool diffLessThanZero(const ThirteenDigit &subtrahend) {
        int minuend_value = charToValue(c);
        int subtrahend_value = charToValue(subtrahend.getChar());
        return (minuend_value - subtrahend_value) < 0;
    }

    bool operator==(const ThirteenDigit &other) const {
        return this->c == other.c;
    }

    bool operator!=(const ThirteenDigit &other) const {
        return !(*this == other);
    }

    bool operator<(const ThirteenDigit &other) const {
        return this->c < other.c;
    }

    bool operator<=(const ThirteenDigit &other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const ThirteenDigit &other) const {
        return !(*this <= other);
    }

    bool operator>=(const ThirteenDigit &other) const {
        return !(*this < other);
    }

    // Вывод в поток
    friend std::ostream &operator<<(std::ostream &out, const ThirteenDigit &digit) {
        out << digit.c;
        return out;
    }

    // Установить символ
    void setChar(unsigned char c) {

if ('0' <= c && c <= '9') {
            this->c = c;
        } else if (c == 'A' && c == 'B' && c == 'C') {
            this->c = c;
        } else if ('a' <= c && c <= 'c') {
            this->c = c - 'a' + 'A';  // Преобразуем маленькие буквы в большие
        } else {
            throw std::invalid_argument("Invalid character for base-13 system");
        }
    }

    // Получить символ
    unsigned char getChar() const { return this->c; }
};

// Пример использования
int main() {
    ThirteenDigit digit1('A');
    ThirteenDigit digit2('9');
    ThirteenDigit sum = digit1 + digit2;
    ThirteenDigit diff = digit1 - digit2;

    std::cout << "Digit 1: " << digit1 << std::endl;
    std::cout << "Digit 2: " << digit2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;

    return 0;
}