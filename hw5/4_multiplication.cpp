#include "my_lib.h"

int main()
{
    size_t A_n, A_m; std::cout << "A[A_n x A_m]" << std::endl;
    std::cout << "A_n: "; std::cin >> A_n;
    std::cout << "A_m: "; std::cin >> A_m;
    int** A = new int*[A_n];
    initialize_2d_arr_using_heap(A, A_n, A_m, false);
    print_2d_array(A, A_n, A_m);

    print_border('-', 100);

    size_t B_n, B_m; std::cout << "B[B_n x B_m]" << std::endl;
    std::cout << "B_n: "; std::cin >> B_n;
    std::cout << "B_m: "; std::cin >> B_m;
    if (A_m != B_n)
    {
        std::cerr << "wrong size of matrixes" << std::endl;
        return 1;
    }
    int** B = new int*[B_n];
    initialize_2d_arr_using_heap(B, B_n, B_m, false);
    print_2d_array(B, B_n, B_m);

    print_border('-', 100);

    int** C = new int*[A_n];
    int C_n = A_n, C_m = B_m;
    initialize_2d_arr_using_heap(C, C_n, C_m, true);
    multiply(A, A_n, A_m, B, B_n, B_m, C);

    print_2d_array(C, A_n, B_m);

    delete_subarrays(A, A_n);
    delete A;
    delete_subarrays(B, B_n);
    delete B;
    delete_subarrays(C, C_n);
    delete C;

    return 0;
}