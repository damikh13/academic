#include <iostream>

int main()
{
    int n; std::cout << "n: "; std::cin >> n;
    bool flag = true;
    short int first_sum{};
    short int second_sum{};
    for (int i = 0; i < 6; ++i) {
        if (flag) first_sum += n % 10; 
        else second_sum += n % 10;
        n /= 10;
        flag ? flag = false : flag = true;
    }

    if (first_sum == second_sum) {
        std::cout << "lucky" << std::endl;
    } else {
        std::cout << "unlucko" << std::endl;
    }
}