#include <stdio.h>
#include <string.h>
#define max_n 105

char m[max_n + 5] = {'0'};
char n[max_n + 5] = {'0'};
int a[max_n + 5],b[max_n + 5],ans[max_n + 5];

void solve() {
	int i,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int len1 = strlen(m);
	int len2 = strlen(n);
	for (int i = 0; i < len1; i++) {
		a[i] = m[len1 - i - 1] - '0';
	}
	for (i = 0; i < len2; i++) {
		b[i] = n[len2 - i - 1] - '0';
	}
	for (i = 0;i < max_n; i++) {
		ans[i] = a[i] + b[i];
	}
	for (j = 0;j < max_n; j++) {
		if (ans[j] < 10) continue;
		ans[j + 1] += ans[j] / 10;
		ans[j] %= 10; 
	} 
	for (i = max_n; i >= 0; i--) {
		if (ans[i] != 0)
			break;
	}
	for (j = i; j >= 0; j--) {
		printf("%d",ans[j]);
	}
	printf("\n");
}

int main() {
	
	while (~scanf("%s%s",m,n))
	solve();
	
	return 0;
} 
