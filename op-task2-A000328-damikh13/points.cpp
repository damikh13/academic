#include <iostream>
#include <cmath>

int main()
{
    long long R; std::cin >> R;
    long long x = floor(R), y = 1;
    long long points_cnt = 0;
    while (x != 0) {
        while ((x * x) + (y * y) <= R * R) {
            points_cnt += x;
            ++y;
        }
        --x;
    }

    std::cout << points_cnt * 4 + floor(R) * 4 + 1 << std::endl;
}