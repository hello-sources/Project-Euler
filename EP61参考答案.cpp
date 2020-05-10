#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int Triangle(int n) {
	return n * (n + 1) / 2;
} 

int Square(int n) {
	return n * n;
}

int Pentagonal(int n) {
	return n * (3 * n - 1) / 2;
} 

int Hexagonal(int n) {
	return n * (2 * n - 1);
}

int Heptagonal(int n) {
	return n * (5 * n - 3) / 2; 
}

int Octagonal(int n) {
	return n * (3 * n - 2);
}

int binary_search(int (*func)(int), int y) {
    int head = 1, tail = y, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1; 
        int temp = func(mid);
        if (temp == y) return 1;
        if (temp < y) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int (*FuncList[6])(int) = {
    Triangle, Square, Pentagonal,
    Hexagonal, Heptagonal, Octagonal
};

int check(int *num) {
    sort(num, num + 6);
    do {
        int flag = 1;
        for (int i = 0; i < 6; i++) {
            if (binary_search(FuncList[i], num[i])) continue;
            flag = 0;
            break;
        }
        if (flag) return 1;
    } while (next_permutation(num, num + 6));
    return 0;
}

vector<int> g[100];
int ans[6] = {0};
int vis[10000] = {0};

void init_graph() {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        int k = 1;
        while (FuncList[i](k) < 1000) ++k;
        while (FuncList[i](k) < 10000) {
            int num = FuncList[i](k++);
            g[num / 100].push_back(num);
            cnt += 1;
        }
    }
    cout << "graph has " << cnt << " nodes" << endl;
    return ;
}

int dfs(int x, int k) {
    ans[k - 1] = x;
    if (k == 6) {
        if (x % 100 != ans[0] / 100) return 0;
        return check(ans);
    }
    int ind = x % 100;
    for (int i = 0; i < g[ind].size(); i++) {
        int now = g[ind][i];
        if (vis[now]) continue;
        vis[now] = 1;
        if (dfs(now, k + 1)) return 1;
        vis[now] = 0;
    }
    return 0;
}

int main() {
    init_graph();
    int flag = 1;
    for (int i = 0; i < 100 && flag; i++) {
        for (int j = 0; j < g[i].size() && flag; j++) {
            vis[g[i][j]] = 1;
            if (dfs(g[i][j], 1)) flag = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        cout << ans[i] << " ";
        sum += ans[i];
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
