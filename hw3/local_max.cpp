#include <iostream>

int main()
{
    int N; std::cin >> N;
    int arr[N]; 
    for (int i = 0; i < N; ++i) std::cin >> arr[i];

    for (int curr_idx = 1; curr_idx < (N - 1); ++curr_idx) { // элемент посередине дойдёт до предпоследнего --> правый -- до последнего
        int left = arr[curr_idx - 1], curr = arr[curr_idx], right = arr[curr_idx + 1];
        if (left < curr && curr > right) {
            std::cout << "local max index: " << curr_idx << std::endl;
            break;
        }
    }

    return 0;
}