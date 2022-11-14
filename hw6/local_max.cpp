#include "my_lib.h"

int main()
{
    size_t A_n, A_m; std::cout << "A[A_n x A_m]" << std::endl;
    std::cout << "A_n: ";std::cin >> A_n;
    std::cout << "A_m: ";std::cin >> A_m;
    int** A = new int* [A_n];
    initialize_2d_arr_using_heap(A, A_n, A_m, false);
    
    std::map<size_t, size_t> local_maxs_positions = get_local_maxs_positions(A, A_n, A_m);
    print_2d_array(A, A_n, A_m, local_maxs_positions);
}