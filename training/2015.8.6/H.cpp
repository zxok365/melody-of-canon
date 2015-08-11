#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(const int &a, const int &b){
	return a > b;
}
int a[1111], b[1111];
int n, m;
int f[1111][1111];
int Big[1111], Equal[1111];
int main(){
	while (1){
		scanf("%d", &n);
		if (n == 0) return 0;
		for (int i = 1; i <= n;i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		a[n + 1] = b[n + 1] = 0;
		int now = 0;
		for (int i = 1; i <= n; i++)
		{
			while (b[i] < a[now + 1]) now++;
			Big[i] = now;
		}
		now = 0;
		for (int i = 1; i <= n; i++){
			while(b[i] <= a[now + 1]) now++;
			Equal[i] = now;
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				f[i][j] = -200 * n;
		f[0][0] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++){
				int t = i - j;
				f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] - 200);
				if (t < Big[i + 1])
					f[i + 1][j] = max(f[i + 1][j], f[i][j] + 200);
				else
				if (t < Equal[i + 1])
					f[i + 1][j] = max(f[i + 1][j], f[i][j]);
				else
					f[i + 1][j] = max(f[i + 1][j], f[i][j] - 200);				
			}
		}
		int ans = -200 * n;
		for (int i = 0; i <= n; i++) ans = max(ans, f[n][i]);
		printf("%d\n", ans);			
	}

}
