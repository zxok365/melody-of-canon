#include<iostream>
#include<cstdio>
using namespace std;
long long f[2111][2111][3];
int  g[2111], h[2111];
int n, k;
int tot;
long long tot_ans;

void clear(){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			f[i][j][0] = f[i][j][1] = -2e9;
}
void ttry(int l, int r, long long now_ans){
	clear();
	f[l - 1][0][0] = f[l - 2][0][0] = now_ans;
	for (int i = l; i <= r; i++)
		f[i][0][0] = now_ans;
	for (int i = l; i <= r; i++)
		for (int j = 1;j <= k; j++)
		{
			f[i][j][0] = max(f[i - 1][j][1], f[i - 1][j][0]);
			f[i][j][1] = max(f[i - 2][j - 1][1] + h[i - 1] + h[i], f[i - 2][j - 1][0] + h[i]);
			now_ans = max(now_ans, max(f[i][j][0], f[i][j][1]));
		}
	tot_ans = max(now_ans, tot_ans);	
}
int main(){
	scanf("%d%d", &n, &k);
	tot = 0;
	tot_ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &g[i]);
		h[i] = g[i];
		tot += g[i];
	}
	if (k * 2 >= n)
		printf("%d\n", tot);
	else
	{
		ttry(3, n, 0);
		k--;
		h[3] += h[2];h[2] = 0;h[1] = 0; h[n - 1] += g[n]; h[n] = 0;
		ttry(3, n, g[1]);
		h[1] = h[2] = h[3] = 0; h[n - 1] = g[n - 1]; h[4] = g[3] + g[4]; h[n] = g[n] + g[1];
		ttry(4, n, g[2]);
//		h[1] = h[n] = h[n - 1] = 0; h[2] = g[2] + g[1]; h[3] = g[3], h[4] = g[4], h[n - 2] = g[n - 2] + g[n - 1];
//		ttry(2, n - 2, g[n]);
		cout << tot_ans << endl;
	}

}
