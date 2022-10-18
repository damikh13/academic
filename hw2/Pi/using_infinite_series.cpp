#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;


int main() {
	long long n = 1e9;
	double Pi = 0;
	for (int i = 1; i <= n; ++i) {
		int sign = -1;
		if (i % 2 != 0) {
			sign *= (-1);
		}
		Pi += sign * (1.0 / (2 * i - 1));
	}

	cout <<  "Pi = " << std::setprecision(16) << Pi * 4 << endl;
}