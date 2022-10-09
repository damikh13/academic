#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russiаn");
    int n; std::cout << "n: "; std::cin >> n;
    n *= 2;
    for (int i = n/4; i >= 0; --i) {
        std::cout << i << " rabbits, " << (n - i*4) / 2 << " gooses" << std::endl;
    }
}