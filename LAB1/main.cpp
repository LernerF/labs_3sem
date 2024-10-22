#include <cmath>
#include <tuple>
#include <algorithm>
#include <iostream>

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

int main() {
    int upper_limit = 9;
    auto result = closest_pair_tonum(upper_limit);
    std::cout << "Best pair: (" << std::get<0>(result) << ", " << std::get<1>(result) << ")\n";
    return 0;
}
