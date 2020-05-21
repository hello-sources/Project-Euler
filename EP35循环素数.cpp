#include <stdio.h> 
#include <math.h> 
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

int is_val(int n) {
	int digit = floor(log10(n)) + 1;
	int x = n;
	for (int i = 1; i < digit; i++) {
		x = x / 10 + x % 10 * (int)pow(10,digit - 1);
		if (is_prime[x])
			return 0;
	}
	return 1;
}

int main() {
	init();
	int sum = 0;
	for (int i = 1; i <= prime[0]; i++) {
		if (!is_val(prime[i])) continue ;
		sum++;
		printf("%d\n",prime[i]);
	}
	printf("%d\n",sum);
	
	return 0;
}
