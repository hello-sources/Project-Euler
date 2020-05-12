#include <iostream>
using namespace std;
#define max_n 100

int main() {
	int sum = 0, ans;
	for (int i = 100; i > 1; i--) {
		int temp = 1;
		for (int j = 1; j < i / 2; j++) {
			temp = temp * (i - j + 1) / j;
			if (temp > 1000000) {
				sum += (i - 2 * j + 1);
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
