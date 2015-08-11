#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10][10], st[10], ans, n;
void dfs(int x)
{
	if (x < 0)
	{
		int cnt[10] = {0};
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < n; ++ j)
			{
				cnt[(st[i] + j) % n] += a[i][j];
			}
		}
		int tmp = -100000000;
		for (int i = 0; i < n; ++ i) tmp = max(tmp, cnt[i]);
		//printf("%d\n", tmp);
		ans = min(ans, tmp);
		return;
	}
	for (int i = 0; i < n; ++ i)
	{
		st[x] = i;
		dfs(x - 1);
	}
}
int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == -1) break;
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < n; ++ j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		ans = 100000000;
		st[n - 1] = 0;
		dfs(n - 2);
		printf("%d\n", ans);
	}
}

