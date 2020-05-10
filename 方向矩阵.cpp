 #include <stdio.h>
 #define max_n 20
 
 int grid[max_n + 5][max_n + 5];
 int dir[4][2] = {
 	{-1,-1},{-1,0},
 	{-1,1},{0,1}
 };
 
 int calc(int x,int y) {
 	int ans = 0; 
	 for (int k = 0;k < 4; k++) {
 		int p = 1;
 		for (int step = 0;step < 4; step++) {
 			int dx = x + dir[k][0] * step;
 			int dy = y + dir[k][1] * step;
 			if(dx < 0 || dx > max_n || dy < 0 || dy > max_n) break;
 			p *= grid[dx][dy];
		 }
		 if (p > ans) ans = p;
	 }
	 return ans;
 }
 
 int main() {
 	for (int i = 0;i < max_n; i++) {
 		for(int j = 0;j < max_n;j++) {
 			scanf("%d",&grid[i][j]);
		 }
	}
	int ans = 0;
	for (int i = 0;i < max_n;i++) {
		for(int j = 0;j < max_n;j++) {
			int p = calc(i,j);
			if (p > ans) ans = p;
		}
	}
 	printf("%d\n",ans);
 	
	return 0;
 } 
