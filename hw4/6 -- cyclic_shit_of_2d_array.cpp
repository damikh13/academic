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

void print_2d_array(const int arr[], int r, int c)
{
    srand(time(0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << arr[i * c + j] << '\t';
        }
        std::cout << std::endl;
    }
}

void cyclic_shit(int arr[], int rows, int cols, int by=1, bool to_left=true)
{
    by %= (rows * cols);
    if (to_left) {
        for (int j = 0; j < by; ++j) {
            std::swap(arr[0], arr[rows * cols - 1]);
            for (int i = 0; i < rows * cols - 2; ++i) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    } else {
        for (int i = 0; i < by; ++i) {
            std::swap(arr[0], arr[rows * cols - 1]);
            for (int i = 0; i < by; ++i) {
                for (int j = 1; j < rows * cols - 1; ++j) {
                    std::swap(arr[rows * cols - j], arr[rows * cols -j - 1]);
                }
            }
        }
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

    std::cout << "------------------------------------" << std::endl;

    cyclic_shit(reinterpret_cast<int*>(arr), N, M, 1, false);
    print_2d_array(reinterpret_cast<int*>(arr), N, M);
}