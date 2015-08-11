#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[4096];
int N, M, P[15][15], A, B, ans = 0;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
void dfs_A(int ind, int mask, int cur)
{
	if (ind == A)
	{
		G[mask].push_back(cur);
	}
	else
	{
		for (int x = 0; x < N; ++ x)
		{
			if ((mask & (1 << x)) == 0)
			{
				dfs_A(ind + 1, mask + (1 << x), cur + P[ind][x]);
			}
		}
	}
}
void dfs_B(int ind, int mask, int cur)
{
	if (ind == B)
	{
		vector<int> &g = G[(1 << N) - 1 - mask];
		//printf("--- %d   g : %d\n", M-cur, g[0]);
		ans += g.end() - lower_bound(g.begin(), g.end(), M - cur);
	}
	else
	{
		for (int x = 0; x < N; ++ x)
		{
			if ((mask & (1 << x)) == 0)
			{
				dfs_B(ind + 1, mask + (1 << x), cur + P[ind + A][x]);
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i)
		{
			for (int j = 0; j < N; ++ j) scanf("%d", &P[i][j]);
		}
		A = N / 2;
		B = N - A;
		for (int i = 0; i < (1 << N); ++ i) G[i].clear();
		dfs_A(0, 0, 0);
		ans = 0;
		for (int i = 0; i < (1 << N); ++ i) sort(G[i].begin(), G[i].end());
		/*for (int i = 0; i < (1 << N); ++ i)
		{
			for (int j = 0; j < G[i].size(); ++ j) printf("%d ", G[i][j]);
			puts("");
		}*/
		dfs_B(0, 0, 0);
		if (ans == 0)
		{
			puts("No solution");
		}
		else
		{
			int tmp = 1;
			for (int i = 1; i <= N; ++ i) tmp *= i;
			int g = gcd(tmp, ans);
			//printf("&&%d\n", ans);
			ans /= g;
			tmp /= g;
			printf("%d/%d\n", tmp, ans);
		}
	}
}

