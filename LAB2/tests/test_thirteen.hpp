#include <gtest/gtest.h>
#include "thirteen.hpp"

TEST(ThirteenDigitTest, CharToValueTest) {
    ThirteenDigit d1('A');
    ThirteenDigit d2('C');
    EXPECT_EQ(d1.charToValue('A'), 10);
    EXPECT_EQ(d2.charToValue('C'), 12);
}

TEST(ThirteenDigitTest, ValueToCharTest) {
    ThirteenDigit d1;
    EXPECT_EQ(d1.valueToChar(10), 'A');
    EXPECT_EQ(d1.valueToChar(12), 'C');
}

TEST(ThirteenDigitTest, ArithmeticTest) {
    ThirteenDigit d1('A');
    ThirteenDigit d2('3');
    ThirteenDigit sum = d1 + d2;
    EXPECT_EQ(sum.getChar(), 'D'); 

    ThirteenDigit d3('C');
    ThirteenDigit d4('2');
    ThirteenDigit diff = d3 - d4;
    EXPECT_EQ(diff.getChar(), 'A');
}

TEST(ThirteenTest, InitializationTest) {
    Thirteen num1(123); 
    Thirteen num2("A5");

    EXPECT_EQ(num1.toString(), "96");
    EXPECT_EQ(num2.toString(), "A5");
}

TEST(ThirteenTest, ArithmeticTest) {
    Thirteen num1(123); 
    Thirteen num2("A5");

    Thirteen sum = num1 + num2;
    Thirteen diff = num1 - num2;

    EXPECT_EQ(sum.toString(), "142"); 
    EXPECT_EQ(diff.toString(), "2E");
}

TEST(ThirteenTest, ComparisonTest) {
    Thirteen num1(100);
    Thirteen num2("7C");

    EXPECT_TRUE(num1 == num2);   // 100 в 13-ричной системе должно быть равно 7C
    EXPECT_FALSE(num1 != num2);
    EXPECT_TRUE(num1 <= num2);
    EXPECT_FALSE(num1 > num2);
}
