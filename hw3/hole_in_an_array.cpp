#include <iostream>

int main()
{
    int N; std::cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i) std::cin >> arr[i];

    int S = (N + 1) * (2 + N) / 2;
    for (int i = 0; i < N; ++i) {
        S -= arr[i];
    }

    std::cout << S << std::endl;
}