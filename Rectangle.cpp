// Rectangle.cpp
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h, std::pair<double, double> center)
    : width(w), height(h), center_point(center) {}

std::pair<double, double> Rectangle::center() const {
    return center_point;
}

void Rectangle::printVertices(std::ostream& os) const {
    double half_width = width / 2;
    double half_height = height / 2;
    os << "Rectangle vertices: ";
    os << "(" << center_point.first - half_width << ", " << center_point.second - half_height << "), ";
    os << "(" << center_point.first + half_width << ", " << center_point.second - half_height << "), ";
    os << "(" << center_point.first + half_width << ", " << center_point.second + half_height << "), ";
    os << "(" << center_point.first - half_width << ", " << center_point.second + half_height << ")\n";
}

void Rectangle::readVertices(std::istream& is) {
    std::cout << "Enter width, height, and center (x y): ";
    is >> width >> height >> center_point.first >> center_point.second;
}

double Rectangle::area() const {
    return width * height;
}