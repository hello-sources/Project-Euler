#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 300

int main() {
    int ans = 0;
    for (int i = 2; i < 100; i++) {
        int f[MAX_N + 5] = {0};
        f[0] = f[1] = 1;
        f[1] = i;
        for (int j = 2; j < 100; j++) {
            for (int k = 1; k <= f[0]; k++) f[k] *= i;
            for (int k = 1; k <= f[0]; k++) {
                if (f[k] < 10) continue;
                f[k + 1] += f[k] / 10;
                f[k] %= 10;
                f[0] += (f[0] == k);
            }
            int sum = 0;
            for (int k = 1; k <= f[0]; k++) sum += f[k];
            if (ans < sum) ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}
