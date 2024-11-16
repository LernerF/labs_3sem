#include "Rectangle.h"

template <std::floating_point T>
Rectangle<T>::Rectangle(T x1, T y1, T x2, T y2)
    : bottomLeft(std::make_unique<Point<T>>(x1, y1)),
      topRight(std::make_unique<Point<T>>(x2, y2)) {}

template <std::floating_point T>
T Rectangle<T>::area() const {
    return (topRight->getX() - bottomLeft->getX()) *
           (topRight->getY() - bottomLeft->getY());
}

template <std::floating_point T>
Point<T> Rectangle<T>::center() const {
    T centerX = (bottomLeft->getX() + topRight->getX()) / 2;
    T centerY = (bottomLeft->getY() + topRight->getY()) / 2;
    return Point<T>(centerX, centerY);
}

template <std::floating_point T>
void Rectangle<T>::printVertices() const {
    std::cout << "Rectangle vertices: "
              << *bottomLeft << ", "
              << "(" << topRight->getX() << ", " << bottomLeft->getY() << "), "
              << *topRight << ", "
              << "(" << bottomLeft->getX() << ", " << topRight->getY() << ")\n";
}

template <std::floating_point T>
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    const auto* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (!otherRect) return false;
    return *bottomLeft == *(otherRect->bottomLeft) &&
           *topRight == *(otherRect->topRight);
}