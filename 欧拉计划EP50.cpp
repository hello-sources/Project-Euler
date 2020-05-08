#include <iostream> 
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
long long sum[max_n + 5] = {0};

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
int main() {
	init();
	for (int i = 1; i <= prime[0]; i++) {
		sum[i] = sum[i - 1] + prime[i];
	}
	int maxN = 21, maxP = 953; 
	for (int i = 0; i <= prime[0]; i++) {
		for (int j = i + maxN + 1; j <= prime[0]; j++) {
			if (sum[j] - sum[i] >= max_n) break;
			if (is_prime[sum[j] - sum[i]] == 0) {
				maxN = j - i;
				maxP = sum[j] - sum[i]; 
			}
		}
	}
	cout << "maxÏÂ±êÊÇ£º" << maxN << endl;
	cout << "max = " << maxP << endl; 
	return 0;
}
