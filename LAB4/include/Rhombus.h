#pragma once
#include "Figure.h"

template <std::floating_point T>
class Rhombus : public Figure<T> {
private:
    std::unique_ptr<Point<T>> centerPoint;
    T diag1, diag2;

public:
    Rhombus(T x, T y, T diag1, T diag2);

    T area() const override;
    Point<T> center() const override;
    void printVertices() const override;

    bool operator==(const Figure<T>& other) const override;
};