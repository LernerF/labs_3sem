#include "Trapezoid.h"

template <std::floating_point T>
Trapezoid<T>::Trapezoid(T x1, T y1, T x2, T y2, T topBase, T bottomBase, T height)
    : bottomLeft(std::make_unique<Point<T>>(x1, y1)),
      topRight(std::make_unique<Point<T>>(x2, y2)),
      topBase(topBase), bottomBase(bottomBase), height(height) {}

template <std::floating_point T>
T Trapezoid<T>::area() const {
    return ((topBase + bottomBase) / 2) * height;
}

template <std::floating_point T>
Point<T> Trapezoid<T>::center() const {
    T centerX = (bottomLeft->getX() + topRight->getX()) / 2;
    T centerY = bottomLeft->getY() + height / 2;
    return Point<T>(centerX, centerY);
}

template <std::floating_point T>
void Trapezoid<T>::printVertices() const {
    std::cout << "Trapezoid vertices: "
              << *bottomLeft << ", "
              << "(" << bottomLeft->getX() + bottomBase << ", " << bottomLeft->getY() << "), "
              << "(" << bottomLeft->getX() + (bottomBase - topBase) / 2 << ", " << bottomLeft->getY() + height << "), "
              << "(" << bottomLeft->getX() + (bottomBase + topBase) / 2 << ", " << bottomLeft->getY() + height << ")\n";
}

template <std::floating_point T>
bool Trapezoid<T>::operator==(const Figure<T>& other) const {
    const auto* otherTrap = dynamic_cast<const Trapezoid*>(&other);
    if (!otherTrap) return false;
    return *bottomLeft == *(otherTrap->bottomLeft) &&
           *topRight == *(otherTrap->topRight) &&
           topBase == otherTrap->topBase &&
           bottomBase == otherTrap->bottomBase &&
           height == otherTrap->height;
}

// Необходимая строка для явной инстанциации шаблонов
template class Trapezoid<double>;