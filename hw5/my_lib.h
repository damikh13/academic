#ifndef _used_

#define _used_
#include <iostream>
#include <time.h>

typedef unsigned long long size_t;

template<typename matrix_element_type>
void print_2d_array(matrix_element_type** arr, size_t N, size_t M)
{
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template<typename matrix_element_type>
void fill_upside_of_squared_2d_array_diagonally(matrix_element_type** arr, size_t N)
{
    matrix_element_type number_to_be_put = 1;
    for (size_t curr_diag = 0; curr_diag < N; ++curr_diag)
    {
        long long i = curr_diag, j = 0;
        while (i >= 0)
        {
            arr[i][j] = number_to_be_put;
            ++number_to_be_put;
            --i;
            ++j;
        }
    }
}

template<typename matrix_element_type>
void initialize_2d_arr_using_heap(matrix_element_type** arr, size_t N, size_t M, bool with_zeros=true)
{
    srand(time(0));
    for (size_t i = 0; i < N; ++i)
    {
        if (with_zeros)
        {
            arr[i] = new matrix_element_type[M]{};
            continue;
        }
        arr[i] = new matrix_element_type[M]; // TODO
        for (size_t j = 0; j < M; ++j)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }
}

template<typename matrix_element_type>
bool is_symmetric(matrix_element_type** arr, size_t N)
{
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (arr[i][j] != arr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

template<typename matrix_element_type>
void fill_squared_2d_array_snakely_up(matrix_element_type** arr, size_t N)
{
    arr[0][0] = 1;
    matrix_element_type curr_value = 2;
    long long i = 1, j = 1;
    while ((N % 2 == 0) ? (!(i == 0 && j == N - 1)) : !(i == N - 1 && j == N - 1)) {
        while(i != -1) {
            arr[i][j] = curr_value;
            ++curr_value;
            --i;
        }
        ++i;

        if (N % 2 == 0 && j == N - 1) break;

        ++j;
        arr[i][j] = curr_value;
        ++curr_value;

        while (i != j) {
            ++i;
            arr[i][j] = curr_value;
            ++curr_value;
        }

        if (N % 2 != 0)
            if (i == N - 1 && j == N - 1) break;

        ++i;
        ++j;
        arr[i][j] = curr_value;
        --i;
        ++curr_value;
    }
}

template<typename matrix_element_type>
void fill_downside_of_squared_2d_array_symmetrically(matrix_element_type** arr, size_t N)
{
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (i < j) arr[j][i] = arr[i][j];
        }
    }
}

template<typename matrix_element_type>
void transpose(matrix_element_type** arr, matrix_element_type** arr_T, size_t N, size_t M) // TODO
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
            arr_T[j][i] = arr[i][j];
    }
}

template<typename matrix_element_type>
void multiply(matrix_element_type** A, size_t A_n, size_t A_m, matrix_element_type** B, size_t B_n, size_t B_m, matrix_element_type** product, bool invertedly=false)
{
    size_t Prod_n = A_n, Prod_m = B_m;
    for (size_t i = 0; i < Prod_n; ++i)
    {
        for (size_t j = 0; j < Prod_m; ++j)
        {
            for (size_t inner = 0; inner < A_m; ++inner)
                if (!invertedly) product[i][j] += A[i][inner] * B[inner][j];
                else product[i][j] += A[inner][i] * B[inner][j];
        }
    }
}

void print_border(char ch, size_t length)
{
    std::cout << std::endl;
    for (size_t i = 0; i < length; ++i)
        std::cout << ch;
    std::cout << std::endl;
}


template<typename matrix_element_type>
void delete_subarrays(matrix_element_type** arr, size_t N)
{
    for (size_t i = 0; i < N; ++i)
        delete arr[i];
}


#endif