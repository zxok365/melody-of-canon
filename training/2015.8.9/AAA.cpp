#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[2][45][1605], c[45], l[45];
int main()
{
	int n, K;
	scanf("%d%d", &n, &K);
	K = min(K, 1600);
	for (int i = 1; i <= n; ++ i) scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++ i) scanf("%d", &l[i]);
	memset(f, 0, sizeof(f));
	for (int i = 0; i < 2; ++ i)
	{
		for (int j = 0; j <= 40; ++ j)
		{
			for (int k = 0; k <= K; ++ k)
			{
				f[i][j][k] = -INF;
			}
		}
	}
	int cur = 0, cur_max = 0;
	f[cur][0][0] = 0;
	for (int i = n; i >= 1; -- i)
	{
		for (int j = 0; j <= 40; ++ j)
		{
			for (int k = 0; k <= K; ++ k)
			{
				f[cur ^ 1][j][k] = -INF;
			}
		}
		for (int j = 0; j <= 40; ++ j)
		{
			for (int k = 0; k <= K; ++ k)
			{
				f[cur ^ 1][j][k] = f[cur][j][k];
			}
		}
		for (int j = 0; j <= 40; ++ j)
		{
			for (int k = 0; k <= K; ++ k)
			{
				for (int jj = 0; jj <= l[i]; ++ jj)
				{
					if (jj + j > 40) continue;
					int money = k + jj * c[i];
					if (money > K) continue;
					f[cur ^ 1][jj + j][money] = max(f[cur ^ 1][jj + j][money], f[cur][j][k]);
				}
			}
		}
		cur_max = min(40, l[i] + cur_max);
		//printf("***\n");
		for (int j = 0; j <= cur_max; ++ j)
		{
			for (int k = 0; k <= K; ++ k)
			{
				f[cur ^ 1][j][k] += c[i] * min(j, l[i]);
				//printf("j = %d k = %d   =   %d\n", j, k, f[cur ^ 1][j][k]);
			}
		}
		cur = cur ^ 1;
	}
	int ans = 0;
	for (int j = 1; j <= cur_max; ++ j)
	{
		for (int k = 0; k <= K; ++ k)
		{
			ans = max(ans, f[cur][j][k]);
		}
	}
	printf("%d\n", ans);
}

