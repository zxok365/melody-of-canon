#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = (int) 1e9 + 7;
int RIGHT[100005], LEFT[100005], near[100005], a[100005];
vector<int> pp[10005];
int main()
{
	int n, i, j, k, l;
	for (i = 1; i <= 10000; ++ i)
	{
		for (j = 1; j * j < i; ++ j)
		{
			if (i % j == 0)
			{
				pp[i].push_back(j);
				pp[i].push_back(i / j);
			}
		}
		if (i % j == 0)
		{
			pp[i].push_back(j);
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		memset(near, 0x3f, sizeof(near));
		for (i = n; i >= 1; -- i)
		{
			int tmp = n + 1;
			for (j = 0; j < pp[a[i]].size(); ++ j)
			{
				tmp = min(tmp, near[pp[a[i]][j]]);
			}
			RIGHT[i] = tmp - 1;
			near[a[i]] = i;
		}
		memset(near, -1, sizeof(near));
		for (i = 1; i <= n; ++ i)
		{
			int tmp = 0;
			for (j = 0; j < pp[a[i]].size(); ++ j)
			{
				tmp = max(tmp, near[pp[a[i]][j]]);
			}
			LEFT[i] = tmp + 1;
			near[a[i]] = i;
		}
		int ans = 0;
		for (i = 1; i <= n; ++ i)
		{
			//printf("%d : %d %d\n", i, LEFT[i], RIGHT[i]);
			(ans += 1LL * (i - LEFT[i] + 1) * (RIGHT[i] - i + 1) % MOD) %= MOD;
		}
		printf("%d\n", ans);
	}
}

