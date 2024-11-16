#include <gtest/gtest.h>
#include <memory>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Vector.h"

TEST(RectangleTests, AreaAndCenter) {
    Rectangle<double> rect(0, 0, 4, 3);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
    EXPECT_EQ(rect.center().getX(), 2.0);
    EXPECT_EQ(rect.center().getY(), 1.5);
}

TEST(TrapezoidTests, AreaAndCenter) {
    Trapezoid<double> trap(0, 0, 6, 4, 4, 6, 3);
    EXPECT_DOUBLE_EQ(trap.area(), 15.0);
    EXPECT_EQ(trap.center().getX(), 3.0);
    EXPECT_EQ(trap.center().getY(), 1.5);
}

TEST(RhombusTests, AreaAndCenter) {
    Rhombus<double> rhomb(0, 0, 6, 8);
    EXPECT_DOUBLE_EQ(rhomb.area(), 24.0);
    EXPECT_EQ(rhomb.center().getX(), 0.0);
    EXPECT_EQ(rhomb.center().getY(), 0.0);
}

TEST(VectorTests, PushBackAndAccess) {
    Vector<std::shared_ptr<Figure<double>>> figures;
    figures.push_back(std::make_shared<Rectangle<double>>(0, 0, 4, 3));
    figures.push_back(std::make_shared<Trapezoid<double>>(0, 0, 6, 4, 4, 6, 3));
    figures.push_back(std::make_shared<Rhombus<double>>(1, 1, 6, 8));

    EXPECT_EQ(figures.size(), 3);
    EXPECT_DOUBLE_EQ(figures[0]->area(), 12.0);
    EXPECT_DOUBLE_EQ(figures[1]->area(), 15.0);
    EXPECT_DOUBLE_EQ(figures[2]->area(), 24.0);
}

TEST(VectorTests, EraseElement) {
    Vector<std::shared_ptr<Figure<double>>> figures;
    figures.push_back(std::make_shared<Rectangle<double>>(0, 0, 4, 3));
    figures.push_back(std::make_shared<Trapezoid<double>>(0, 0, 6, 4, 4, 6, 3));
    figures.push_back(std::make_shared<Rhombus<double>>(1, 1, 6, 8));

    figures.erase(1); // Удаляем трапецию
    EXPECT_EQ(figures.size(), 2);
    EXPECT_DOUBLE_EQ(figures[0]->area(), 12.0);
    EXPECT_DOUBLE_EQ(figures[1]->area(), 24.0);
}