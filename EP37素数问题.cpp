#include <stdio.h>
#include <math.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1, 1, 0};
 
void init() {
	for (int i = 2;i <= max_n; i++) {
		if (!is_prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	return ;
}

int is_val(int x) {
	int digit = floor(log10(x)) + 1;
	int n1 = x,n2 = x;
	for (int i = 1; i < digit; i++) {
		n1 /= 10;
		n2 %= (int)pow(10,digit - i);
		if (is_prime[n1] || is_prime[n2])
			return 0;
	}
	return 1;
}


int main() {
	int sum = 0;
	init();
	for (int i = 1; i <= prime[0]; i++) {
		if (!is_val(prime[i])) continue;
		sum += prime[i];
		printf("%d\n",prime[i]);
	}	
	printf("%d\n",sum - 17);
	
	return 0;
} 
