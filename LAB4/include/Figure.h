#pragma once
#include "Point.h"

template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
class Figure {
public:
    virtual ~Figure() = default;

    virtual T area() const = 0;                      // Площадь фигуры
    virtual Point<T> center() const = 0;             // Центр фигуры
    virtual void printVertices() const = 0;          // Печать координат вершин
    virtual bool operator==(const Figure<T>& other) const = 0;
};