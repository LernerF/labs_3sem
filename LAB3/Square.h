// Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure {
    double side_length;
    std::pair<double, double> center_point;

public:
    Square(double side = 1.0, std::pair<double, double> center = {0, 0});

    std::pair<double, double> center() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    double area() const override;
};

#endif // SQUARE_H