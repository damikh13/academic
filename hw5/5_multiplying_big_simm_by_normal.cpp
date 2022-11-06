#include "my_lib.h"

int main()
{
    size_t N; std::cin >> N;
    size_t A_n; std::cout << "A[A_n x A_n]" << std::endl;
    // std::cout << "A_n: "; std::cin >> A_n;
    A_n = N;
    int** A = new int*[A_n];
    initialize_2d_arr_using_heap(A, A_n, A_n, false);
    fill_downside_of_squared_2d_array_symmetrically(A, A_n);
    // print_2d_array(A, A_n, A_n);
    // print_border('-', 100);

    size_t B_n, B_m; std::cout << "B[B_n x B_m]" << std::endl;
    B_n = B_m = N;
    // std::cout << "B_n: "; std::cin >> B_n;
    // std::cout << "B_m: "; std::cin >> B_m;
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

    double sum_of_diffs = 0.;
    int n = 50;

    using namespace std::chrono;
    for (int i = 1; i <= n; ++i)
    {
        // normal indexes
        high_resolution_clock::time_point start1 = high_resolution_clock::now();
        multiply(A, A_n, A_n, B, B_n, B_m, C, false);
        high_resolution_clock::time_point end1 = high_resolution_clock::now();
        duration<double> time_span_1 = duration_cast<duration<double>>(end1 - start1);

        // inverted indexes
        high_resolution_clock::time_point start2 = high_resolution_clock::now();
        multiply(A, A_n, A_n, B, B_n, B_m, C, true);
        high_resolution_clock::time_point end2 = high_resolution_clock::now();
        duration<double> time_span_2 = duration_cast<duration<double>>(end2 - start2);

        double diff_1 = time_span_1.count();
        double diff_2 = time_span_2.count();
        sum_of_diffs += (diff_2 - diff_1);
    }
    std::cout << sum_of_diffs / n;

    delete_subarrays(A, A_n);
    delete A;
    delete_subarrays(B, A_n);
    delete B;
    delete_subarrays(C, A_n);
    delete C;

    return 0;
}
