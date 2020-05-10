#include <stdio.h>
#include <string.h>
#define max_n 10000

int ans[max_n];
int result[max_n];

void  f(int x) {
    memset(ans,0,sizeof(ans));
    ans[0] = 1,ans[1] = 1;
    for (int k = x;k > 0;k--) {
        for (int i = 1;i <= ans[0];i++) {
            ans[i] *= k;
        }
        for (int i = 1;i <= ans[0];i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    memset(result,0,sizeof(result));
    result[0] = 1,result[1] = 1;
    for (int i = 1;i <= ans[0];i++) {
        if(!ans[i]) continue;
        for (int j = 1;j <= result[0]; j++) {
            result[j] *= ans[i];
        }
        for (int k = 1; k <= result[0]; k++) {
            if (result[k] < 10) continue;
            result[k + 1] += result[k] / 10;
            result[k] %= 10;
            result[0] += (k == result[0]);
        }
    }
    for (int i = result[0];i > 0;i++) {
        printf("%d",result[i]);
    }
    printf("\n");
}


int main() {
    int x;
    int sum = 1;
    while (~scanf("%d",&x)) {
        f(x);
    }

    return 0;
}
