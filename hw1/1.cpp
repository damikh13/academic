#include <iostream>
#include <algorithm>

std::string bin(int x)
{
    std::string output = "";
    while (x > 0) {
        unsigned short int ost = x % 2;
        output += std::to_string(ost);
        x /= 2;
    }
    std::reverse(output.begin(), output.end());
    return output;
}

int main()
{
    unsigned short int x;
    std::cout << "x = "; std::cin >> x;
    std::cout << bin(x) << std::endl;
}