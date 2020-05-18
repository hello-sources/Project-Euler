#include <iostream>
#include <cmath>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1, 1, 0};

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!is_prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	return ;
}

bool is_circlenumber(int n) {
	if (is_prime[n]) return false;
	int x = n, num;
	while (x) {
		if (is_prime[x]) return false;
		x /= 10;
	}
	int y = n;
	num = (int)pow(10, floor(log10(n)));
	while (y) {
		if (is_prime[y]) return false;
		y %= num;
		num /= 10;		 
	}
	return true;
}

int solve() {
	int sum = 0;
	for (int i = 1; i <= prime[0]; i++) {
		if (prime[i] < 10) continue;
		if (!is_circlenumber(prime[i])) continue;
		sum += prime[i];
	}
	return sum;
}

int main() {
	init();
	int ans = solve();
	cout << prime[0] << endl;
	cout << ans << endl;
	return 0;
} 
