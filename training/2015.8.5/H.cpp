#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int vis[15][105][2];
int www[15][105], n, d;
int should(int x)
{
	if (x <= n / 2) return 0;
	return 1;
}
int dfs(int t, int i, int j, int sig)
{
	if (i == d)
	{
		if (j == min(n / 2, t - 1) && sig == should(t))
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	int *w = www[i];
	if (vis[i][j][sig]) return vis[i][j][sig];
	int pos;
	if (sig == 0) pos = j + 1; else pos = n / 2 + t - j;
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	for (int k = 1; k <= j; ++ k) cnt[should(w[k])] ++;
	for (int k = n / 2 + 1; k <= n / 2 + t - 1 - j; ++ k) cnt[should(w[k])] ++;
	return vis[i][j][sig] = dfs(t, i + 1, cnt[0], should(w[pos]));
}
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = d - 1; i >= 1; -- i)
	{
		int k;
		for (int j = 1; j <= n; ++ j) scanf("%d", &k), www[i][k] = j;
	}
	bool ans = 1;
	for (int t = 1; t <= n && ans; ++ t)
	{
		for (int sig = 0; sig <= 1 && ans; ++ sig)
		{
			int M, L;
			if (sig == 0) M = n / 2 - 1; else M = n / 2;
			if (sig == 0) L = n / 2 - n + t - 1; else L = n / 2 - n + t;
			for (int j = max(0, L); j <= min(M, t - 1); ++ j)
			{
				memset(vis, 0, sizeof(vis));
				if (dfs(t, 1, j, sig) == 2)
				{
					//printf("%d %d %d\n", t, sig, j);
					ans = 0;
					break;
				}
			}
		}
	}
	if (ans) puts("Yes"); else puts("No");
}

