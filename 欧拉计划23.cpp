#include <iostream>
using namespace std;
#define max_n 28123

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};
int d[max_n + 5] = {0};
int num[max_n + 5] = {0};

void init() {
	for (int i = 2; i <= max_n ; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			f[i] = i + 1;
			cnt[i] = i * i;
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				f[i * prime[j]] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
				cnt[i * prime[j]] = cnt[i] * prime[j];
				break;
			} else {
				f[i * prime[j]] = f[i] * f[prime[j]];
				cnt[i * prime[j]] = prime[j] * prime[j];	
			}
		}
	}
	return ;
}

int main() {
	init();
	long long sum = 0;
	for (int i = 0; i <= max_n; i++) {
		f[i] -= i;
		if (f[i] > i) d[++d[0]] = i;
	}
	for (int i = 1; i <= d[0]; i++) {
		for (int j = i; j <= d[0]; j++) {
			if (d[i] + d[j] > max_n) break;
			num[d[i] + d[j]] = 1;
		} 
	}
	for (int i = 0; i <= max_n; i++) {
		if (num[i]) continue;
		sum += i;
	}
	cout << sum  << endl;
	return 0;
}
