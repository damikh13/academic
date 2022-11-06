#include "my_lib.h"

int main()
{
    size_t N; std::cout << "[N x N]" << std::endl;
    std::cout << "N: "; std::cin >> N;

    int** arr = new int*[N];
    initialize_2d_arr_using_heap(arr, N, N, true);
    fill_squared_2d_array_snakely_up(arr, N);
    fill_downside_of_squared_2d_array_symmetrically(arr, N);
    print_2d_array(arr, N, N);
    std::cout << (is_symmetric(arr, N) ? "symmetric!" : "non-symmetric :c") << std::endl;

    delete_subarrays(arr, N);
    delete arr;

    return 0;    
}