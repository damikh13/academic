#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned short int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << '*';
        }
        cout << endl;
    }
}