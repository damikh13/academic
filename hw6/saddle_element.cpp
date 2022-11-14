#include "my_lib.h"

int main()
{
    size_t A_n, A_m; std::cout << "A[A_n x A_m]" << std::endl;
    std::cout << "A_n: ";std::cin >> A_n;
    std::cout << "A_m: ";std::cin >> A_m;
    int** A = new int* [A_n];
    initialize_2d_arr_using_heap(A, A_n, A_m, false);
    // A[0][0] = 5;
    // A[0][1] = 6;
    // A[0][2] = 7;
    // A[1][0] = 4;
    // A[1][1] = 2;
    // A[1][2] = 2;
    // A[2][0] = 3;
    // A[2][1] = 2;
    // A[2][2] = 2;

    // print_2d_array(A, A_n, A_m);
    std::map<size_t, size_t> saddle_elements_positions = get_saddle_elements_positions(A, A_n, A_m);
    print_2d_array(A, A_n, A_m, saddle_elements_positions);
}