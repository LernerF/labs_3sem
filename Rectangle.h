// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
    double width, height;
    std::pair<double, double> center_point;

public:
    Rectangle(double w = 1.0, double h = 1.0, std::pair<double, double> center = {0, 0});

    std::pair<double, double> center() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    double area() const override;
};

#endif // RECTANGLE_H