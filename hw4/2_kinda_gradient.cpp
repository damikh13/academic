#include <iostream>

int* make_random_array_of_size(int N, int* arr)
{
    srand(time(0));
    for (int i = 0; i < N; ++i) arr[i] = rand() % 10 + 1;
    return arr;
}

void print_array(int sz, int* arr)
{
    for (int i = 0; i < sz; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void change_array_order(int sz, int* arr, int x)
{
    int i = 0, j = sz - 1;
    while (i < j) {
        while (arr[i] < x && i < sz - 1) ++i;
        while (arr[j] > x && j > 0) --j;
        std::swap(arr[i], arr[j]);
    }
}

int main()
{
    int N; std::cout << "N: "; std::cin >> N;
    int arr[N];
    make_random_array_of_size(N, arr);
    int x; std::cout << "x: "; std::cin >> x;
    // int N = 10, x = 5;
    // // int arr[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    // // int arr[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print_array(N, arr);

    change_array_order(N, arr, x);   

    print_array(N, arr);
}