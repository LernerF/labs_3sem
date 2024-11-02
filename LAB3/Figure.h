// Figure.h
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<double, double> center() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readVertices(std::istream& is) = 0;
    virtual double area() const = 0;

    // Оператор приведения к double для площади
    operator double() const {
        return area();
    }

    // Перегрузка операторов для ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.printVertices(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.readVertices(is);
        return is;
    }
};

#endif // FIGURE_H