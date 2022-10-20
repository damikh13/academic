#include <iostream>

int main()
{
    int N; std::cin >> N;
    int arr[N];
    arr[0] = 0;
    
    // generating array with 0 (a hole) at 0_idx
    srand(time(0));
    bool used[N + 1];
    for (int i = 1; i < N; ++i) {
        int rand_val = rand() % N + 1;
        if (!used[rand_val]) {
            arr[i] = rand_val;
            used[rand_val] = true;
        } else --i;
    }

    // printing out the array
    for (int i = 1; i < N; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    // finding a hole
    int S = N * (N + 1) / 2;
    for (int i = 1; i < N; ++i) {
        S -= arr[i];
    }

    std::cout << "hole is: " << S << std::endl;
}