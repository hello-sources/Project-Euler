#include <stdio.h>
#define max_n 1000000
int a[max_n] = {0};
void prime() {
	for(int i = 2;i * i <= max_n;i++)  {
		if(a[i]) {
			for(int j = i * i;j <= max_n;j += i) {
				a[j] = 1;
			}	
		}
	}
}
int main() {
	int num = 0;
	int i; 
	for(i = 0; i < max_n;i++) {
		if(a[i] == 0)
			num += 1;
		if(num == 1001)
			break;
	}
	printf("%d\n",i);
	
	return 0;
}
