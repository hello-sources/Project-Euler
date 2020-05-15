#include <iostream>
using namespace std;
typedef long long ll;

ll Pentagonal(ll n) {
	return n * (n * 3 - 1) >> 1;
}

bool binary_search (ll n, ll x) {
	int head = 1, tail = n, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (Pentagonal(mid) == x) return true;
		else if(Pentagonal(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return false;
}

int main() {
	ll min = INT_MAX;
	ll n = 2, m, p1, p2;
	while (Pentagonal(n) - Pentagonal(n - 1) < min) {
		p1 = Pentagonal(n);
		for (int m = n - 1; m >= 1; m--) {
			p2 = Pentagonal(m);
			if (p1 - p2 >= min) break;
			int flag = 1;
			flag = binary_search(2 * n, p1 + p2);
			flag = flag && binary_search(n, p1 - p2);
			if (flag) min = p1 - p2;
		}
		n++;
	}
	cout << min << endl;
	return 0;
} 
