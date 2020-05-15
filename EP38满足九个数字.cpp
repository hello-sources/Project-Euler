#include <stdio.h>
#include <math.h>

int digits(int n) {
	if (n == 0) return 1;
	return floor(log10(n)) + 1;
}

int calc(int x) {
	long long n = 1,ans = 0;
	while (digits(ans) < 9) {
		ans *= (int)pow(10,digits(x * n));
		ans += n * x;
		n += 1; 
	}
	if (digits(ans) - 9) return 0;
	int num[10] = {0};
	int tmp = ans;
	while (tmp) {
		if (num[tmp % 10]) return 0;
		num[tmp % 10] += 1;
		tmp /= 10;
	}
	return ans;
}

int main() {
	long long ans = 0;
	for (int i = 1; i < 10000; i++) {
		int tmp = calc(i);
		if (tmp > ans) ans = tmp;
	}
	printf("%lld\n",ans);
	
	return 0;
} 
