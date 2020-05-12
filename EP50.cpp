#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000
int32_t isPrime[MAX_N + 5] = {0};
int32_t prime[MAX_N + 5] = {0};
int64_t sum[MAX_N + 5] = {0};
 
void InitPrime() {
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) {
            prime[++prime[0]] = i;
        }
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            isPrime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
 
int32_t main() { 
    InitPrime(); // 初始化100万以内的素数表
    sum[0] = 0;
    for (int32_t i = 1; i <= prime[0]; i++) {
        sum[i] = sum[i - 1] + prime[i];
    }
    int32_t maxN = 21, maxP = 953;
    for (int32_t i = 0; i <= prime[0]; i++) {
        for (int32_t j = i + maxN + 1; j <= prime[0]; j++) {
            if (sum[j] - sum[i] >= MAX_N) break;
            if (isPrime[sum[j] - sum[i]] == 0) {
                maxN = j - i;
                maxP = sum[j] - sum[i];
            }
        }
    }
    printf("(%d, %d)\n", maxN, maxP);
    return 0;
}
