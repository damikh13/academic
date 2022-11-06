#include "my_lib.h"

int main()
{
    size_t N, M; std::cout << "[N x N]" << std::endl;
    std::cout << "N: "; std::cin >> N;

    int** arr = new int*[N];
    initialize_2d_arr_using_heap(arr, N, N, true);
    fill_upside_of_squared_2d_array_diagonally(arr, N);
    print_2d_array(arr, N, N);

    delete_subarrays(arr, N);
    delete arr;
}