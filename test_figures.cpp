// test_figures.cpp
#include <gtest/gtest.h>
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

// Тест для класса Square
TEST(SquareTest, AreaCalculation) {
    Square square(4);
    EXPECT_DOUBLE_EQ(square.area(), 16.0);
}

TEST(SquareTest, CenterCalculation) {
    Square square(4, {2, 2});  // Указываем центр (2, 2)
    auto center = square.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

// Тест для класса Rectangle
TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle(3, 5);
    EXPECT_DOUBLE_EQ(rectangle.area(), 15.0);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle rectangle(3, 5, {1.5, 2.5});  // Указываем центр (1.5, 2.5)
    auto center = rectangle.center();
    EXPECT_DOUBLE_EQ(center.first, 1.5);
    EXPECT_DOUBLE_EQ(center.second, 2.5);
}

// Тест для класса Trapezoid
TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid(3, 5, 4);
    EXPECT_DOUBLE_EQ(trapezoid.area(), 16.0);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid(3, 5, 4, {4, 2});  // Указываем центр (4, 2)
    auto center = trapezoid.center();
    EXPECT_DOUBLE_EQ(center.first, 4.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}