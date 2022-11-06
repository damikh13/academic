#include "my_lib.h"

int main()
{
    size_t A_n, A_m; std::cout << "A[A_n x A_m]" << std::endl;
    std::cout << "A_n: "; std::cin >> A_n;
    std::cout << "A_m: "; std::cin >> A_m;

    int** arr = new int*[A_n];
    initialize_2d_arr_using_heap(arr, A_n, A_m, false);
    print_2d_array(arr, A_n, A_m);

    print_border('-', 100);

    int** arr_T = new int*[A_m];
    initialize_2d_arr_using_heap(arr_T, A_m, A_n, true);
    transpose(arr, arr_T, A_n, A_m);
    print_2d_array(arr_T, A_m, A_n);

    delete_subarrays(arr, A_n);
    delete arr;
    delete_subarrays(arr_T, A_m);
    delete arr_T;

    return 0;
}