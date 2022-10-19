#include <iostream>

int main()
{
    int N; std::cin >> N;
    int arr[N]; 
    for (int i = 0; i < N; ++i) std::cin >> arr[i];

    int left = arr[0], right = arr[2];
    for (int i = 1; i < N - 1; ++i) {
        if (left < arr[i] && arr[i] > right) {
            std::cout << "local max idx: " << i;
            break;
        }
        left = arr[i];
        right = arr[i + 2];
    }
    return 0;
}