#include "Rhombus.h"

template <std::floating_point T>
Rhombus<T>::Rhombus(T x, T y, T diag1, T diag2)
    : centerPoint(std::make_unique<Point<T>>(x, y)),
      diag1(diag1), diag2(diag2) {}

template <std::floating_point T>
T Rhombus<T>::area() const {
    return (diag1 * diag2) / 2;
}

template <std::floating_point T>
Point<T> Rhombus<T>::center() const {
    return *centerPoint;
}

template <std::floating_point T>
void Rhombus<T>::printVertices() const {
    std::cout << "Rhombus vertices: "
              << "(" << centerPoint->getX() - diag1 / 2 << ", " << centerPoint->getY() << "), "
              << "(" << centerPoint->getX() + diag1 / 2 << ", " << centerPoint->getY() << "), "
              << "(" << centerPoint->getX() << ", " << centerPoint->getY() - diag2 / 2 << "), "
              << "(" << centerPoint->getX() << ", " << centerPoint->getY() + diag2 / 2 << ")\n";
}

template <std::floating_point T>
bool Rhombus<T>::operator==(const Figure<T>& other) const {
    const auto* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    if (!otherRhombus) return false;
    return *centerPoint == *(otherRhombus->centerPoint) &&
           diag1 == otherRhombus->diag1 &&
           diag2 == otherRhombus->diag2;
}

// Необходимая строка для явной инстанциации шаблонов
template class Rhombus<double>;