#include <iostream> 
using namespace std;

int prime(int n) {
	if (n <= 1) return 0;
	for (int j = 2; j * j <= n; j++) {
		if (n % j == 0) return 0;
	}
	return 1;
}

int main() {
	int n = 0, sum = 1, len;
	for (len = 3; ;len += 2) {
		int a = len * len;
		int b = a - len + 1;
		int c = b - len + 1;
		int d = c - len + 1;
		if (prime(a)) n += 1;
		if (prime(b)) n += 1;
		if (prime(c)) n += 1;
		if (prime(d)) n += 1;
		sum += 4;
		if (n * 10 < sum) break;
	}	
	cout << len << endl;
	return 0;
}
