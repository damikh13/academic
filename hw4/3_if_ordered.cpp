#include <iostream>

int* make_random_array_of_size(int N, int* arr)
{
    srand(time(0));
    for (int i = 0; i < N; ++i) arr[i] = rand() % 10 + 1;
    return arr;
}

void check_if_ordered(int sz, int* arr)
{
    bool descending = true, ascending = true;

    // checking descending order
    for (int i = 0; i < sz - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            descending = false;
            break;
        }
    }

    // checking ascending order
    for (int i = 0; i < sz - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            ascending = false;
            break;
        }
    }

    if (!(descending || ascending)) std::cout << "nikakoy" << std::endl;
    else if (ascending) std::cout << "ascending" << std::endl;
    else std::cout << "descending" << std::endl;
}

void print_array(int sz, int* arr)
{
    for (int i = 0; i < sz; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int N; std::cout << "N: "; std::cin >> N;
    int arr[N];
    make_random_array_of_size(N, arr);

    print_array(N, arr);
    check_if_ordered(N, arr);
}