// Trapezoid.cpp
#include "Trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid(double tb, double bb, double h, std::pair<double, double> center)
    : top_base(tb), bottom_base(bb), height(h), center_point(center) {}

std::pair<double, double> Trapezoid::center() const {
    return center_point;
}

void Trapezoid::printVertices(std::ostream& os) const {
    double half_bottom = bottom_base / 2;
    double half_top = top_base / 2;
    os << "Trapezoid vertices: ";
    os << "(" << center_point.first - half_bottom << ", " << center_point.second - height / 2 << "), ";
    os << "(" << center_point.first + half_bottom << ", " << center_point.second - height / 2 << "), ";
    os << "(" << center_point.first + half_top << ", " << center_point.second + height / 2 << "), ";
    os << "(" << center_point.first - half_top << ", " << center_point.second + height / 2 << ")\n";
}

void Trapezoid::readVertices(std::istream& is) {
    std::cout << "Enter top base, bottom base, height, and center (x y): ";
    is >> top_base >> bottom_base >> height >> center_point.first >> center_point.second;
}

double Trapezoid::area() const {
    return 0.5 * (top_base + bottom_base) * height;
}