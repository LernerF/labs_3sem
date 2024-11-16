#pragma once
#include "Figure.h"
#include <memory>

template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
class Rectangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> bottomLeft;
    std::unique_ptr<Point<T>> topRight;

public:
    Rectangle(T x1, T y1, T x2, T y2)
        : bottomLeft(std::make_unique<Point<T>>(x1, y1)),
          topRight(std::make_unique<Point<T>>(x2, y2)) {}

    T area() const override {
        return std::abs(topRight->getX() - bottomLeft->getX()) *
               std::abs(topRight->getY() - bottomLeft->getY());
    }

    Point<T> center() const override {
        return Point<T>(
            (bottomLeft->getX() + topRight->getX()) / 2,
            (bottomLeft->getY() + topRight->getY()) / 2
        );
    }

    void printVertices() const override {
        std::cout << "Rectangle vertices: (" << bottomLeft->getX() << ", " << bottomLeft->getY()
                  << "), (" << topRight->getX() << ", " << bottomLeft->getY() << "), ("
                  << topRight->getX() << ", " << topRight->getY() << "), ("
                  << bottomLeft->getX() << ", " << topRight->getY() << ")\n";
    }

    bool operator==(const Figure<T>& other) const override {
        const Rectangle<T>* otherRect = dynamic_cast<const Rectangle<T>*>(&other);
        if (!otherRect) return false;
        return *bottomLeft == *(otherRect->bottomLeft) &&
               *topRight == *(otherRect->topRight);
    }
};