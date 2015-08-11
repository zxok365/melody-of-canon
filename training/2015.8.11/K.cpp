#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int n, K, ans;
vector<int> G[105];
bool top[105];
int dfs(int x)
{
	int cnt = 0;
	for (int i = 0; i < G[x].size(); ++ i)
	{
		cnt += dfs(G[x][i]);
	}
	if (cnt == K) ans ++;
	return cnt + 1;
}
int main()
{
	while (scanf("%d%d", &n, &K) == 2)
	{
		for (int i = 1; i <= n; ++ i) G[i].clear(), top[i] = true;
		for (int i = 2; i <= n; ++ i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			top[b] = false;
		}
		ans = 0;
		for (int i = 1; i <= n; ++ i)
		{
			if (top[i])
			{
				dfs(i);
			}
		}
		printf("%d\n", ans);
	}
}

