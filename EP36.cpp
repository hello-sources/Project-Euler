#include <iostream>
using namespace std;
#define max_n 1000000

bool is_val(int n, int m) {
	int sum = 0, x = n, temp = 0;
	while (n) {
		temp = temp * m + n % m;
		n /= m;
	}
	return x == temp;
}

int main() {
	int sum = 0;
	for (int i = 1; i < max_n; i++) {
		if (!(is_val(i, 2) && is_val(i, 10))) continue;
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
