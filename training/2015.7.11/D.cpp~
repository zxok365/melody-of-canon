#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 111;
bool f[10][N][N][11];
int d[10];
int main(){
	int task;
	scanf("%d",&task);
	while (task --){
		int sum = 0;
		for (int i = 1;i <= 9;i ++) scanf("%d",&d[i]),sum += d[i];
		int ans = sum;
		while (ans <= 2 * sum){
			int l = ans / 2;
			int r = (ans + 1) / 2;
			memset(f,false,sizeof f);
			int res = ans - sum;
			for (int i = 0;i <= min(l,res);i ++){
				int j = res - i;
				if (j <= r) f[0][i][j][0] = true;
			}
			for (int p = 1;p <= 9;p ++){
				for (int i = 0;i <= l;i ++)
					for (int j = 0;j <= r;j ++)
						for (int k = 0;k < 11;k ++){
							if (!d[p]){
								f[p][i][j][k] = f[p - 1][i][j][k];
								continue;
							}
							if (f[p - 1][i][j][k]){
								for (int x = 0;x <= min(d[p],l - i);x ++){
									int y = d[p] - x;
									if (j + y > r) continue;
									f[p][i + x][j + y][(k + (x - y) * p  + 1100) % 11] = true;
								}
							}
						}
			}
			if (f[9][l][r][0]) break;
			++ ans;
		}
		if (ans > 2 * sum) printf("-1\n"); else printf("%d\n",ans);
	}
	return 0;
}
