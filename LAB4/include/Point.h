#pragma once
#include <type_traits>

template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
class Point {
private:
    T x, y;

public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setX(T x_) { x = x_; }
    void setY(T y_) { y = y_; }

    bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
}
};