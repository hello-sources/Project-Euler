#include <iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int cal[max_n + 5] = {0};

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			cal[i] = i - 1;
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				cal[i * prime[j]] = cal[i] * prime[j];
				break;
			} else {
				cal[i * prime[j]] = cal[i] * cal[prime[j]];
			}
		} 
	}
	return ;
}

int main() {
	init();
	long long sum = 0;
	for (int i = 2; i <= max_n; i++) sum += cal[i];
	cout << sum << endl;
	return 0;
}
