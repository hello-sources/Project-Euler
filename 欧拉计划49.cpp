#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 10000

struct sint{
	int num;
	int rnum;
};

int prime[max_n + 5] = {0};
int psint[max_n + 5] = {0};
int dlen = 0;
sint d[max_n + 5] = {0};

/*
*下面这个函数就是把一个十进制表示数转换为另一种表示即二进制下的表示
*参数解释 rnum就是转换之后的次数表示数 
*/
int inttosint(int n) {
	int rnum = 0, x = n;
	while (n) {
		rnum += 1 << (2 * (n % 10));//核心代码 
		n /= 10;
	}
	return rnum;
}

bool cmp(sint a, sint b) {
	if (a.rnum < b.rnum) return true;
	if (a.rnum == b.rnum && a.num < b.num) return true;
	return false; 
}

void init() {
	for (int i = 2; i <= max_n; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			//找到所有的四位数素数，并且存储次数表示数到数组中 
			if (i >= 1000) {
				d[dlen].num = i;
				d[dlen].rnum = inttosint(i);
				psint[i] = d[dlen].rnum;
				dlen++;
			}
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
	init();
	sort(d, d + dlen, cmp);
	for (int i = 0; i < dlen - 2; i++) {
		int j = i + 1, nextNum;
		while (d[j].rnum == d[i].rnum) {
			nextNum = 2 * d[j].num - d[i].num;
			if (nextNum >= 10000) break;
			if (psint[nextNum] == d[i].rnum) {
				cout << d[i].num << d[j].num << nextNum << endl;
			}
			j++;
		}
	}
	return 0;
} 
