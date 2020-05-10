#include <iostream>
using namespace std;
#define max_n 12000

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
} 

int main() {
	int sum = 0;
	for (int i = 2; i <= max_n; i++) {
		for (int j = i / 3 + 1; 2 * j < i; j++) {
			sum += (gcd(i, j) == 1);
		} 
	}
	cout << sum << endl;	
	return 0;
} 
