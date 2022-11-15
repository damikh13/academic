#include <iostream>
#include <ctime>
#include <map>
#ifndef _used_
#define _used_

template<typename matrix_element_type>
inline void print_2d_array(matrix_element_type** arr, size_t N, size_t M, std::map<size_t, size_t> special_elements_coords = {})
{
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (special_elements_coords.count(i))
            {
                if (special_elements_coords[i] == j)
                {
                    std::cout << arr[i][j] << '_' << '\t';
                    continue;
                }
            }
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template<typename matrix_element_type>
inline void initialize_2d_arr_using_heap(matrix_element_type** arr, size_t N, size_t M, bool with_zeros=true)
{
    for (size_t i = 0; i < N; ++i)
    {
        if (with_zeros)
        {
            arr[i] = new matrix_element_type[M]{};
            continue;
        }
        arr[i] = new matrix_element_type[M];
        for (size_t j = 0; j < M; ++j)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }
}

template<typename matrix_element_type>
inline std::map<size_t, size_t> get_local_maxs_positions(matrix_element_type** arr, size_t N, size_t M)
{
    std::map<size_t, size_t> coords_of_local_maxs;

    // checking corners
    if (arr[0][0] > arr[0][1] && arr[0][0] > arr[1][0] && arr[0][0] > arr[1][1])
    {
        coords_of_local_maxs[0] = 0;
    }
    if (arr[N - 1][0] > arr[N - 2][0] && arr[N - 1][0] > arr[N - 1][1] && arr[N - 1][0] > arr[N - 2][1])
    {
        coords_of_local_maxs[N - 1] = 0;
    }
    if (arr[N - 1][M - 1] > arr[N - 2][M - 1] && arr[N - 1][M - 1] > arr[N - 1][M - 2] && arr[N - 1][M - 1] > arr[N - 2][M - 2])
    {
        coords_of_local_maxs[N - 1] = M - 1;
    }
    if (arr[0][M - 1] > arr[1][M - 1] && arr[0][M - 1] > arr[0][M - 2] && arr[0][M - 1] > arr[1][M - 2])
    {
        coords_of_local_maxs[0] = M - 1;
    }

    // checking borders
    for (size_t i = 1; i < N - 1; ++i) // upper and bottom border
    {
        if (arr[0][i - 1] < arr[0][i] && arr[0][i] > arr[0][i + 1] && arr[0][i] > arr[1][i] && arr[0][i] > arr[1][i - 1] && arr[0][i] > arr[1][i + 1])
        {
            coords_of_local_maxs[0] = i;
        }
        if (arr[N - 1][i - 1] < arr[N - 1][i] && arr[N - 1][i] > arr[N - 1][i + 1] && arr[N - 1][i] > arr[N - 2][i] && arr[N - 1][i] > arr[N - 2][i - 1] && arr[N - 1][i] > arr[N - 2][i + 1])
        {
            coords_of_local_maxs[N - 1] = i;
        }
    }

    for (size_t j = 1; j < N - 1; ++j) // left and right border
    {
        if (arr[j - 1][0] < arr[j][0] && arr[j][0] > arr[j + 1][0] && arr[j][0] > arr[j][1] && arr[j][0] > arr[j - 1][1] && arr[j][0] > arr[j + 1][1])
        {
            coords_of_local_maxs[j] = 0;
        }
        if (arr[j - 1][M - 1] < arr[j][M - 1] && arr[j][M - 1] > arr[j + 1][M - 1] && arr[j][M - 1] > arr[j][M - 2] && arr[j][M - 1] > arr[j - 1][M - 2] && arr[j][M - 1] > arr[j + 1][M - 2])
        {
            coords_of_local_maxs[j] = M - 1;
        }
    }

    // checking inner part
    for (size_t i = 1; i < N - 1; ++i)
    {
        for (size_t j = 1; j < M - 1; ++j)
        {
            bool max_vertical = arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j];
            bool max_horizontal = arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1];
            bool max_diagonal_main = arr[i][j] > arr[i - 1][j - 1] && arr[i][j] > arr[i + 1][j + 1];
            bool max_diagonal_side = arr[i][j] > arr[i - 1][j + 1] && arr[i][j] > arr[i + 1][j - 1];
            if (max_vertical && max_horizontal && max_diagonal_main && max_diagonal_side)
            {
                coords_of_local_maxs[i] = j;
            }
        }
    }

    return coords_of_local_maxs;
}

template<typename matrix_element_type>
inline std::map<size_t, size_t> get_saddle_elements_positions(matrix_element_type** arr, size_t N, size_t M)
{
    std::map<size_t, size_t> saddle_elements_positions;
    matrix_element_type min_of_row[N];
    matrix_element_type max_of_col[M];

    for (size_t curr_row = 0; curr_row < N; ++curr_row)
    {
        min_of_row[curr_row] = LONG_MAX;
        for (size_t curr_col = 0; curr_col < M; ++curr_col)
        {
            min_of_row[curr_row] = std::min(min_of_row[curr_row], arr[curr_row][curr_col]);
        }
    }

    for (size_t curr_col = 0; curr_col < M; ++curr_col)
    {
        max_of_col[curr_col] = LONG_MIN;
        for (size_t curr_row = 0; curr_row < N; ++curr_row)
        {
            max_of_col[curr_col] = std::max(max_of_col[curr_col], arr[curr_row][curr_col]);
        }
    }

    for (size_t curr_row = 0; curr_row < N; ++curr_row)
    {
        for (size_t curr_col = 0; curr_col < M; ++curr_col)
        {
            if (arr[curr_row][curr_col] == min_of_row[curr_col] && arr[curr_row][curr_col] == max_of_col[curr_col])
            {
                saddle_elements_positions[curr_row] = curr_col;
            }
        }
    }

    return saddle_elements_positions;
}

template<typename matrix_element_type>
inline void combine_two_strings(matrix_element_type** A, size_t A_n, size_t A_m, size_t S_1, size_t S_2, double quotient=1)
{
    for (size_t curr_col = 0; curr_col < A_m; ++curr_col)
    {
        double delta = 1e-7;
        A[S_1 - 1][curr_col] += A[S_2 - 1][curr_col] * quotient;
        if (-delta < A[S_1 - 1][curr_col] && A[S_1 - 1][curr_col] < delta)
        {
            A[S_1 - 1][curr_col] = 0;
        }
    }
}

template<typename matrix_element_type>
inline void combine_matrixes(matrix_element_type** A, matrix_element_type** B, matrix_element_type** result, size_t N, size_t M, bool addition=true)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            result[i][j] = (addition) ? (A[i][j] + B[i][j]) : (A[i][j] - B[i][j]);
        }
    }
}

template<typename matrix_element_type>
void make_unit_matrix_with_ones_shifted(matrix_element_type** A, size_t N, size_t first_one_to_shift_pos, size_t second_one_to_shift_pos)
{
    for (size_t i = 0; i < N; ++i)
    {
        if (i != first_one_to_shift_pos && i !=  second_one_to_shift_pos)
        {
            A[i][i] = 1;
        }
        else
        {
            if (i == first_one_to_shift_pos)
            {
                A[i][second_one_to_shift_pos] = 1;
            }
            else
            {
                A[i][first_one_to_shift_pos] = 1;
            }
        }
    }
}

template<typename matrix_element_type>
void multiply(matrix_element_type** A, size_t A_n, size_t A_m, matrix_element_type** B, size_t B_n, size_t B_m, matrix_element_type** product, bool invertedly=false)
{
    size_t Prod_n = A_n, Prod_m = B_m;
    for (size_t curr_row = 0; curr_row < Prod_n; ++curr_row)
    {
        for (size_t curr_col = 0; curr_col < Prod_m; ++curr_col)
        {
            for (size_t inner = 0; inner < A_m; ++inner)
                if (!invertedly) product[curr_row][curr_col] += A[curr_row][inner] * B[inner][curr_col];
                else product[curr_row][curr_col] += A[inner][curr_row] * B[inner][curr_col];
        }
    }
}

template<typename matrix_element_type>
void switch_two_strings(matrix_element_type** A, size_t A_n, size_t A_m, size_t S_1, size_t S_2)
{
    size_t T_n = A_n;
    matrix_element_type** T = new matrix_element_type* [T_n];
    initialize_2d_arr_using_heap(T, T_n, T_n);
    make_unit_matrix_with_ones_shifted(T, T_n, S_1 - 1, S_2 - 1);

    matrix_element_type** Tmp = new matrix_element_type* [A_n];
    initialize_2d_arr_using_heap(Tmp, A_n, A_m);

    // TODO remember T
    multiply(T, T_n, T_n, A, A_n, A_m, Tmp);
    
    for (size_t curr_row = 0; curr_row < A_n; ++curr_row)
    {
        for (size_t curr_col = 0; curr_col < A_m; ++curr_col)
        {
            A[curr_row][curr_col] = Tmp[curr_row][curr_col];
        }
    }
    destruct_matrix(Tmp, A_n);
    delete Tmp;
    
    // TODO
    // destruct_matrix(T, T_n);
    // delete T;
}

template<typename matrix_element_type>
inline void make_matrix_triangle(matrix_element_type** A, size_t N)
{
    for (size_t main_row = 0; main_row < N - 1; ++main_row)
    {
        if (A[main_row][main_row] != 0) // upper left corner isnt zero
        {
            for (size_t curr_row = main_row + 1; curr_row < N; ++curr_row)
            {
                double quotient = A[curr_row][main_row] / A[main_row][main_row];
                combine_two_strings(A, N, N, curr_row + 1, main_row + 1, -quotient);
            }
        }
        else
        {
            for (size_t curr_row = main_row + 1; curr_row < N; ++curr_row)
            {
                if (A[curr_row][main_row] != 0)
                {
                    switch_two_strings(A, N, N, curr_row + 1, main_row + 1);
                    // TODO remember T
                }
            }
        }
    }
}

template<typename matrix_element_type>
inline void destruct_matrix(matrix_element_type** A, size_t A_n)
{
    for (size_t i = 0; i < A_n; ++i)
    {
        delete A[i];
    }
}

inline void print_sep(size_t length=40, char ch='-')
{
    for (size_t i = 0; i < length; ++i)
    {
        std::cout << ch;
    }
    std::cout << std::endl;
}

#endif