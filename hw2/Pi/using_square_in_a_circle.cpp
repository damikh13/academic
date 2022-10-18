#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main(){
	int R = RAND_MAX - 1;
	int r = R / 2;
	double count_s = 0, count_S = 0;
	for (int i = 0; i <= R; ++i) {
		for (int j = 0; j <= R; ++j) {
			if (((i - r) * (i - r) + (j - r) * (j - r)) <= r * r) count_s += 1;
			else count_S += 1;
		}
	}
	cout << "Pi = " << ((count_s * 4) / (count_s + count_S)) << endl;
}