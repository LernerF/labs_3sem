// Square.cpp
#include "Square.h"
#include <iostream>

Square::Square(double side, std::pair<double, double> center)
    : side_length(side), center_point(center) {}

std::pair<double, double> Square::center() const {
    return center_point;
}

void Square::printVertices(std::ostream& os) const {
    double half_side = side_length / 2;
    os << "Square vertices: ";
    os << "(" << center_point.first - half_side << ", " << center_point.second - half_side << "), ";
    os << "(" << center_point.first + half_side << ", " << center_point.second - half_side << "), ";
    os << "(" << center_point.first + half_side << ", " << center_point.second + half_side << "), ";
    os << "(" << center_point.first - half_side << ", " << center_point.second + half_side << ")\n";
}

void Square::readVertices(std::istream& is) {
    std::cout << "Enter side length and center (x y): ";
    is >> side_length >> center_point.first >> center_point.second;
}

double Square::area() const {
    return side_length * side_length;
}