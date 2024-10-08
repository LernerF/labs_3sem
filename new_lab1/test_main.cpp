#include <gtest/gtest.h>
#include <cmath>
#include <tuple>
#include <algorithm>


bool is_perfect_square(int x) {
    int root = static_cast<int>(sqrt(x));
    return root * root == x;
}


std::tuple<int, int> closest_pair_tonum(int upper_limit) {
    std::tuple<int, int> best_pair = {0, 0};

    for (int m = upper_limit; m > 0; --m) {
        for (int n = m - 1; n > 0; --n) {
            if (10 > m && m > n) {
                int sum = m + n;
                int diff = m - n;

                if (is_perfect_square(sum) && is_perfect_square(diff)) {
                    if (best_pair == std::tuple<int, int>{0, 0} || 
                        m > std::get<0>(best_pair) || 
                        (m == std::get<0>(best_pair) && n > std::get<1>(best_pair))) {
                        best_pair = {m, n};
                    }
                }
            }
        }
    }

    return best_pair;
}

TEST(PerfectSquareTest, BasicAssertions) {
    EXPECT_TRUE(is_perfect_square(4)); 
    EXPECT_TRUE(is_perfect_square(9));
    EXPECT_TRUE(is_perfect_square(16));
    EXPECT_FALSE(is_perfect_square(5));
    EXPECT_FALSE(is_perfect_square(10));
}

TEST(ClosestPairTest, BasicAssertions) {

    std::tuple<int, int> result1 = closest_pair_tonum(9);
    EXPECT_EQ(result1, std::make_tuple(5, 4));

 
    std::tuple<int, int> result2 = closest_pair_tonum(6);
    EXPECT_EQ(result2, std::make_tuple(5, 4)); 

    std::tuple<int, int> result3 = closest_pair_tonum(3);
    EXPECT_EQ(result3, std::make_tuple(0, 0));
}