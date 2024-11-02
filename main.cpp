// main.cpp
#include <iostream>
#include <vector>
#include <memory>
#include "Figure.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    int choice;

    // Добавление фигур
    while (true) {
        std::cout << "Choose figure to add (1-Square, 2-Rectangle, 3-Trapezoid, 0-Exit): ";
        std::cin >> choice;

        if (choice == 1) {
            auto square = std::make_unique<Square>();
            std::cin >> *square; // Чтение параметров квадрата
            figures.push_back(std::move(square));
        } else if (choice == 2) {
            auto rectangle = std::make_unique<Rectangle>();
            std::cin >> *rectangle; // Чтение параметров прямоугольника
            figures.push_back(std::move(rectangle));
        } else if (choice == 3) {
            auto trapezoid = std::make_unique<Trapezoid>();
            std::cin >> *trapezoid; // Чтение параметров трапеции
            figures.push_back(std::move(trapezoid));
        } else if (choice == 0) {
            break;
        }
    }

    // Вывод информации о каждой фигуре
    for (const auto& figure : figures) {
        std::cout << *figure; // Вывод вершин фигуры
        std::cout << "Center: (" << figure->center().first << ", " << figure->center().second << ")\n";
        std::cout << "Area: " << static_cast<double>(*figure) << "\n";
    }

    // Удаление фигуры по индексу
    int index;
    std::cout << "Enter index to delete: ";
    std::cin >> index;
    if (index >= 0 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    }

    // Вычисление общей площади всех фигур
    double total_area = 0;
    for (const auto& figure : figures) {
        total_area += static_cast<double>(*figure); // Использование приведения к double для площади
    }
    std::cout << "Total area of all figures: " << total_area << "\n";

    return 0;
}