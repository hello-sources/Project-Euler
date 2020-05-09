#include <iostream>
#include <cmath>
using namespace std;

int is_val(int year, int mon, int day) {
	if (mon == 1 || mon == 2) {
		--year;
		mon += 12;
	}
	int w;
	w = (int)(day + 2 * mon + 3 * (mon + 1) / 5 +year + floor(year / 4)
	- floor(year / 100) + floor(year / 400)) % 7;
	return w; 
}

int main() {
	int sum = 0;
	for (int i =1901; i <= 2000; i++) {
		for (int j = 1; j <= 12; j++){
			if (is_val(i, j, 1) != 6) continue;
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
} 
