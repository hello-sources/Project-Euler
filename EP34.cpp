#include <iostream>
using namespace std;
#define max_n 400000
int num[10] = {0};

void init() {
	num[0] = 1;
	for (int i = 1; i < 10; i++) {
		num[i] = num[i - 1] * i;
	}
	return ;
}

bool is_val(int n) {
	int sum = 0, x = n;
	while (x) {
		sum += num[x % 10];
		x /= 10;
	}
	return sum == n;
}

int main() {
	init();
	int sum = 0;
	for (int i = 2; i <= max_n; i++) {
		if (!is_val(i)) continue;
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
