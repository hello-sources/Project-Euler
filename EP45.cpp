#include <iostream> 
using namespace std;

typedef long long ll;

ll Triangle(ll n) {
	return n * (n + 1) >> 1;
}

ll Pentagonal(ll n) {
	return n * (3 * n - 1) >> 1;
}

ll Hexagonal(ll n) {
	return n * (2 * n - 1);
}

bool binary_search(ll (*func)(ll), ll n, ll x) {
	ll head = 1, tail = n, mid;
	while (head <= tail) {
		mid = (tail + head) >> 1;
		if (func(mid) == x) return true;
		else if (func(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return false;
} 

int main() {
	ll n = 144;
	while (!binary_search(Pentagonal,2 * n, Hexagonal(n))) n++;
	cout << n << endl;
	cout << Hexagonal(n) << endl;
	return 0;
}
