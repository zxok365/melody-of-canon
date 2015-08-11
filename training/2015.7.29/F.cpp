#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[10005];
int f[10005], xcnt, ycnt;
char M[105][105];
int newx[105][105], newy[105][105];
bool v[10005];
bool match(int x)
{
	for (int i = 0; i < G[x].size(); ++ i)
	{
		int u = G[x][i];
		if (!v[u])
		{
			v[u] = 1;
			if (f[u] == -1 || match(f[u]))
			{
				f[u] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int n, m, i, j, k, l, q, w;
		scanf("%d%d", &n, &m);
		scanf("%d", &q);
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= m; ++ j) M[i][j] = '.';
		}
		for (i = 1; i <= q; ++ i)
		{
			scanf("%d%d", &j, &k);
			M[j][k] = '*';
		}
		scanf("%d", &w);
		for (i = 1; i <= w; ++ i)
		{
			scanf("%d%d", &j, &k);
			M[j][k] = '#';
		}
		xcnt = ycnt = 0;
		for (i = 1; i <= n; ++ i)
		{
			for (int L = 1; L <= m; ++ L)
			{
				if (M[i][L] == '#') continue;
				xcnt ++;
				int R;
				for (R = L; R <= m && M[i][R] != '#'; ++ R) newx[i][R] = xcnt;
				//printf("hang %d %d\n", L, R);
				L = R;
			}
		}
		for (i = 1; i <= m; ++ i)
		{
			for (int U = 1; U <= n; ++ U)
			{
				if (M[U][i] == '#') continue;
				ycnt ++;
				int D;
				for (D = U; D <= n && M[D][i] != '#'; ++ D) newy[D][i] = ycnt;
				U = D;
			}
		}
		//printf("%d %d\n", xcnt, ycnt);
		for (i = 1; i <= xcnt; ++ i) G[i].clear();
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= m; ++ j)
			{
				if (M[i][j] == '*')
				{
					//printf("* %d %d\n", newx[i][j], newy[i][j]);
					G[newx[i][j]].push_back(newy[i][j]);
				}
			}
		}
		int ans = 0;
		memset(f, -1, sizeof(f));
		for (i = 1; i <= xcnt; ++ i)
		{
			for (j = 1; j <= ycnt; ++ j) v[j] = 0;
			if (match(i)) ans ++;
		}
		printf("%d\n", ans);
	}
}

