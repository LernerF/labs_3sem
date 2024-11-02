// Trapezoid.h
#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

class Trapezoid : public Figure {
    double top_base, bottom_base, height;
    std::pair<double, double> center_point;

public:
    Trapezoid(double tb = 1.0, double bb = 1.0, double h = 1.0, std::pair<double, double> center = {0, 0});

    std::pair<double, double> center() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    double area() const override;
};

#endif // TRAPEZOID_H