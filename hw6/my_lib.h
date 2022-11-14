#include <iostream>
#include <ctime>
#include <map>

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
    srand(time(0));
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

