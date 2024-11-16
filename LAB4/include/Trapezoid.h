#pragma once
#include "Figure.h"

template <std::floating_point T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> bottomLeft;
    std::unique_ptr<Point<T>> topRight;
    T topBase, bottomBase, height;

public:
    Trapezoid(T x1, T y1, T x2, T y2, T topBase, T bottomBase, T height);

    T area() const override;
    Point<T> center() const override;
    void printVertices() const override;

    bool operator==(const Figure<T>& other) const override;
};