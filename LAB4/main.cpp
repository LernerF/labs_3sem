#include <iostream>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Vector.h"
#include <memory>

int main() {
    Vector<std::shared_ptr<Figure<double>>> figures;

    figures.push_back(std::make_shared<Rectangle<double>>(0, 0, 4, 3));
    figures.push_back(std::make_shared<Trapezoid<double>>(0, 0, 5, 5, 4, 6, 3));
    figures.push_back(std::make_shared<Rhombus<double>>(1, 1, 6, 8));

    for (size_t i = 0; i < figures.size(); ++i) {
        figures[i]->printVertices();
        std::cout << "Area: " << figures[i]->area() << "\n";
    }

    return 0;
}