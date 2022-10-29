#include <iostream>

void fill_2d_array_with_random_numbers(int arr[], int r, int c)
{
    srand(time(0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            arr[i * c + j] = rand() % 20 + 1;
        }
    }
}


void print_2d_array(int arr[], int r, int c)
{
    srand(time(0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << arr[i * c + j] << '\t';
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "[N x M]" << std::endl;
    int N, M; std::cout << "N: "; std::cin >> N;
    std::cout << "M: "; std::cin >> M;

    int arr[N][M]{};
    fill_2d_array_with_random_numbers(reinterpret_cast<int*>(arr), N, M);
    print_2d_array(reinterpret_cast<int*>(arr), N, M);
}