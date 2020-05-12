#include <stdio.h>
#include <algorithm>
#include <inttypes.h> 
#define MAX_N 10000

typedef struct {
    int32_t num;
    int32_t rnum;
} sInt;
 
int32_t prime[MAX_N + 5] = {0};
int32_t pSint[MAX_N + 5] = {0};
int32_t dLen = 0;
sInt d[MAX_N + 5] = {0};
 
int32_t IntToSint(int32_t n) {
    int32_t rnum = 0, x = n;
    while (n) {
        rnum += 1 << (2 * (n % 10));
        n /= 10;
    }
    return rnum;
}
 
bool cmp(sInt a, sInt b) {
    if (a.rnum < b.rnum) return true;
    if (a.rnum == b.rnum && a.num < b.num) return true;
    return false;
}
 
void InitData() {
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            if (i >= 1000) {
                d[dLen].num = i;
                d[dLen].rnum = IntToSint(i);
                pSint[i] = d[dLen].rnum;
                dLen++;
            }
        }
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
 
int32_t main() {
    InitData();
    std::sort(d, d + dLen, cmp);
    for (int32_t i = 0; i < dLen - 2; i++) {
        int32_t j = i + 1, nextNum;
        while (d[j].rnum == d[i].rnum) {
            nextNum = 2 * d[j].num - d[i].num;
            if (nextNum >= 10000) break;
            if (pSint[nextNum] == d[i].rnum) {
                printf("%d%d%d\n", d[i].num, d[j].num, nextNum);
            }
            j++;
        }
    }
    return 0;
}

