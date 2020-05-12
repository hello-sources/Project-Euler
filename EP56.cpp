#include <iostream>
using namespace std;
#define max_n 300


void result() {
	int sum1 = 0;
	for (int i = 2; i < 100; i++) {
		int ans[max_n + 5] = {0};
		ans[0] = 1, ans[1] = 1;
		for (int l = 2; l < 100; l++) {
			for (int j = 1; j <= ans[0]; j++) {
				ans[j] *= i;
			}
			for (int k = 1; k <= ans[0]; k++) {
				if (ans[k] < 10) continue;
				ans[k + 1] += ans[k] / 10;
				ans[k] %= 10;
				ans[0] += (ans[0] == k);
			}
			int sum = 0;
			for (int j = 1; j <= ans[0]; j++) sum += ans[j]; 
			if (sum > sum1) sum1 = sum;
		}
	}
	cout << sum1 << endl;
}

int main() {
	result();
	
	return 0;
} 
