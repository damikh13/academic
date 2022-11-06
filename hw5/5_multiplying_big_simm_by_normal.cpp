#include "my_lib.h"

int main()
{
    size_t A_n; std::cout << "A[A_n x A_n]" << std::endl;
    std::cout << "A_n: "; std::cin >> A_n;
    int** A = new int*[A_n];
    initialize_2d_arr_using_heap(A, A_n, A_n, false);
    fill_downside_of_squared_2d_array_symmetrically(A, A_n);
    // print_2d_array(A, A_n, A_n);
    // print_border('-', 100);

    size_t B_n, B_m; std::cout << "B[B_n x B_m]" << std::endl;
    std::cout << "B_n: "; std::cin >> B_n;
    std::cout << "B_m: "; std::cin >> B_m;
    if (A_n != B_n)
    {
        std::cerr << "wrong size of matrixes" << std::endl;
        return 1;
    }
    int** B = new int*[B_n];
    initialize_2d_arr_using_heap(B, B_n, B_m, false);
    // print_2d_array(B, B_n, B_m);
    // print_border('-', 100);

    int** C = new int*[A_n];
    int C_n = A_n, C_m = B_m;
    initialize_2d_arr_using_heap(C, C_n, C_m, true);
    // print_2d_array(C, A_n, B_m);
    // print_border('-', 100);

    // normal indexes
    clock_t start = clock();
    multiply(A, A_n, A_n, B, B_n, B_m, C, false);
    clock_t end = clock();

    // inverted indexes
    clock_t start1 = clock();
    multiply(A, A_n, A_n, B, B_n, B_m, C, true);
    clock_t end1 = clock();

    std::cout << "multiplying normally takes " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    std::cout << "multiplying invertedly it takes " << (double)(end1 - start1) / CLOCKS_PER_SEC << std::endl;

    delete_subarrays(A, A_n);
    delete A;
    delete_subarrays(B, A_n);
    delete B;
    delete_subarrays(C, A_n);
    delete C;

    return 0;
}