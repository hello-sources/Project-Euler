#include <stdio.h>

int get_letters(int n) {
	static int arr[20] = {
		0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
		6, 6, 8, 8, 7, 7, 9, 8, 8
	};
	static int arr2[10] = {
		0, 0, 6, 6, 5, 5, 5, 7, 6, 6
	};
	if (n < 20) return arr[n];
	else if (n < 100) return arr[n % 10] + arr2[n  / 10];
	else if (n < 1000) {
		if (n % 100 == 0)
			return arr[n / 100] + 7;
		return arr[n / 100] + 10 + get_letters(n % 100); 
	} else return 11;
}

int main() {
	int sum = 0;
	for (int i = 1;i <= 1000; i++) {
		sum += get_letters(i); 
	}
	printf("%d\n",sum);
	
	return 0;
}
