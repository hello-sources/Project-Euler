#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define max_n 100000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int func(int n) {
    return 2 * n * n;
}

bool binary_search(int (*f)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (f(mid) == x) return true;
    if (f(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(f, l, r, x);
}

bool is_val(int x) {
    for (int i = 1; i <= prime[0] && prime[i] < x; i++) {
        int val = x - prime[i];
        if (binary_search(func, 1, val, val)) return true;
    }
    return false;
}

int main() {
    init();
    for (int i = 9; i <= max_n; i += 2) {
        if (!is_prime[i]) continue;
        if (is_val(i)) continue;
        cout << i << endl;
        break;
    }
    return 0;
}
