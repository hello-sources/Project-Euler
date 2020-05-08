#include <iostream>
using namespace std;

int get_val(int n) {
	if (n <= 9) return n;
	n -= 10;
	int cur	= 10, j = 2, num;
	while (n >= j * (cur * 10 - cur)) {
		n -= j * (cur * 10 - cur);
		cur *= 10;
		j += 1;
	}
	num = n / j + cur;
	for (int i = 0; i < j - n % j - 1; i++) num /= 10;
	return num % 10;
}
 
int main() {
	int a = 1, ans = 1;
	for (int i = 0; i < 7; i++){
		a *= get_val(ans);
		ans *= 10;
	}
	cout << a << endl;
	return 0;
}
