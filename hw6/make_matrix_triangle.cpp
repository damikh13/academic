
#include "my_lib.h"

int main()
{
    srand(time(0));
    size_t A_n; std::cout << "A[A_n x A_n]" << std::endl;
    std::cout << "A_n: "; std::cin >> A_n;
    double** A = new double*[A_n];
    initialize_2d_arr_using_heap(A, A_n, A_n, false);
    print_2d_array(A, A_n, A_n);
    print_sep();

    make_matrix_triangle(A, A_n);
    print_2d_array(A, A_n, A_n);

    destruct_matrix(A, A_n);
    delete A;
}