#include <iostream>

void fill_2d_array_snakely(int arr[], int r, int c)
{
    for (int i = 0; i < r; i += 2) {
        for (int j = 0; j < c; ++j) {
            int idx = i * c + j;
            arr[idx] = idx + 1;
        }
    }

    for (int i = 1; i < r; i += 2) {
        for (int j = 0; j < c; ++j) {
            arr[i * c + j] = i * c + (r - j);
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
    std::cout << "[R x C]" << std::endl;
    int R, C; std::cout << "R: "; std::cin >> R;
    std::cout << "C: "; std::cin >> C;

    int arr[R][C]{};

    fill_2d_array_snakely(reinterpret_cast<int*>(arr), R, C);
    print_2d_array(reinterpret_cast<int*>(arr), R, C);
}