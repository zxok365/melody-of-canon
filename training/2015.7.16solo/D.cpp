#include<cstdio>
#include<iostream>
using namespace std;
int n, m;
int a[1111],b[1111];
int f[1111][1111], dp[1111][1111];
pair<int, int> p, from[1111][1111];
int now_ans[1111];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int j = 1; j <= m; j++) scanf("%d", &b[j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j]) f[i][++f[i][0]] = j;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= f[i][0]; j++)
			dp[i][j] = max(dp[i][j], 1);
		for (int j = i + 1; j <= n; j++)
		if (a[i] < a[j])
		{
			int now = 1;
			for (int k = 1; k <= f[i][0]; k++)
			{
				while (now <= f[j][0] && f[j][now] <= f[i][k]) now++;
				if (now > f[j][0]) break;
				if (dp[j][now] < dp[i][k] + 1){
				//	cout << i << ' ' << k << ' ' << j << ' ' << now << endl;
					dp[j][now] = dp[i][k] + 1;
					from[j][now] = make_pair(i, k);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= f[i][0]; j++)
		{
			if (ans < dp[i][j]){
				ans = max(ans, dp[i][j]);
				p = make_pair(i, j);
			}
		}
	}
	printf("%d\n", ans);
	now_ans[1] = a[p.first];
	for (int i = 2; i <= ans; i++)
	{
		p = from[p.first][p.second];
		now_ans[i] = a[p.first];
	}
	for (int i = ans; i > 1; i--) printf("%d ", now_ans[i]);
	printf("%d\n", now_ans[1]);
}
