#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n; cout << "n: "; cin >> n;
    int k = log2(n);
    for (int i = k; i >= 0; --i) {
        int ed = 1 << i;
        int c = ed & n;
        if (c == 0) cout << '0';
        else cout << '1';
    }
}