#include "my_lib.h"

int main()
{
    std::srand(time(0));
    size_t N, M; std::cout << "work with matrixes [N x M]" << std::endl;
    std::cout << "N: ";std::cin >> N;
    std::cout << "M: ";std::cin >> M;
    int** A = new int* [N];
    initialize_2d_arr_using_heap(A, N, M, false);
    print_2d_array(A, N, M);
    print_sep(50);

    int** B = new int* [N];
    initialize_2d_arr_using_heap(B, N, M, false);
    print_2d_array(B, N, M);
    print_sep(50);

    int** res = new int* [N];
    initialize_2d_arr_using_heap(res, N, M, true);

    combine_matrixes(A, B, res, N, M, false);

    print_2d_array(res, N, M);

    // TODO delete
    return 0;
}