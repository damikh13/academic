#include <iostream>
#include <cmath>

double sin_x_times_n(double x, int n, int depth = 0)
{
    if (depth == n) return 0;
    return sin(x) + sin_x_times_n(sin(x), n, depth + 1);
}

int main()
{
    double x; std::cout << "x: "; std::cin >> x;
    int n; std::cout << "n: "; std::cin >> n;
    std::cout << sin_x_times_n(x, n) << std::endl;
}