#include <iostream>

void cyclic_shit_to_left(int sz, int* arr, int by=1)
{
    by %= sz;
    for (int j = 0; j < by; ++j) {
        std::swap(arr[0], arr[sz - 1]);
        for (int i = 0; i < sz - 2; ++i) {
            std::swap(arr[i], arr[i + 1]);
        }
    }
}

void cyclic_shift_to_right(int sz, int* arr, int by=1)
{
    by %= sz;
    for (int i = 0; i < by; ++i) {
        std::swap(arr[0], arr[sz - 1]);
        for (int j = 1; j < sz - 1; ++j) {
            std::swap(arr[sz - j], arr[sz - j - 1]);
        }
    }
}

void print_array(int sz, int* arr)
{
    for (int i = 0; i < sz; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int* make_random_array_of_size(int N, int* arr)
{
    srand(time(0));
    for (int i = 0; i < N; ++i) arr[i] = rand() % 100 + 1;
    return arr;
}

int main()
{
    int N; std::cout << "N: "; std::cin >> N;
    int arr[N];
    make_random_array_of_size(N, arr);

    print_array(N, arr);

    cyclic_shit_to_left(N, arr, 2);
    cyclic_shift_to_right(N, arr, 2);

    print_array(N, arr);
}