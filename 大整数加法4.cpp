#include <stdio.h>
#include <string.h> 
#define max_n 50

char num[max_n + 5];
int ans[max_n + 5] = {0};

int main() {
	for (int i = 0; i < 100; i++) {
		scanf("%s",num);
		int len = strlen(num);
		if (ans[0] < len) ans[0] = len;
		for (int i = 0; i < len; i++) {
			ans[len  - i] += num[i] - '0';
		}
		for (int i = 1;i <= ans[0]; i++) {
			if (ans[i] < 10) continue;
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
			ans[0] += (ans[0] == i);
		}
	}
	for (int i = ans[0];i > ans[0] - 10; i--) {
		printf("%d",ans[i]);
	}
	printf("\n");
	
	return 0;
}
