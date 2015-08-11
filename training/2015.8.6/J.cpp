#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
struct edge
{
	int to, f, r;
	edge() {to = f = r = 0;}
	edge(int to, int f, int r) : to(to), f(f), r(r) {}
};
vector<edge> old_G[2005];
vector<edge> G[2005];
char str[5000];
int S, T, st[2005], d[2005];
const int INF = 0x3f3f3f3f;
void ae_G(int i, int j, int f)
{
	G[i].push_back(edge(j, f, G[j].size()));
	G[j].push_back(edge(i, 0, G[i].size() - 1));
}
void ae_old_G(int i, int j, int f)
{
	old_G[i].push_back(edge(j, f, old_G[j].size()));
	old_G[j].push_back(edge(i, 0, old_G[i].size() - 1));
}
int bfs()
{
	memset(d, 0, sizeof(d));
	d[S] = 1;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int p = q.front(); q.pop();
		for (int i = 0; i < G[p].size(); ++ i)
		{
			int v = G[p][i].to;
			if (d[v] == 0 && G[p][i].f > 0)
			{
				d[v] = d[p] + 1;
				q.push(v);
			}
		}
	}
	return d[T];
}
int dfs(int x, int arg)
{
	if (x == T) return arg;
	for (int &i = st[x]; i < G[x].size(); ++ i)
	{
		int v = G[x][i].to;
		if (G[x][i].f > 0 && d[x] + 1 == d[v])
		{
			int d = dfs(v, min(arg, G[x][i].f));
			if (d)
			{
				G[x][i].f -= d;
				G[v][G[x][i].r].f += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow()
{
	int ans = 0;
	while (bfs())
	{
		memset(st, 0, sizeof(st));
		int tmp;
		while (tmp = dfs(S, INF)) ans += tmp;
	}
	return ans;
}
int main()
{
	while (true)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n + m + 2; ++ i) G[i].clear(), old_G[i].clear();
		gets(str);
		map<string, int> M;
		int name_cnt = 0;
		S = n + m + 1;
		T = n + m + 2;
		for (int i = 1; i <= n; ++ i)
		{
			gets(str);
			istringstream sin(str);
			string name;
			sin >> name;
			if (M[name] == 0) M[name] = ++ name_cnt;
			int index = M[name], tmp;
			ae_G(S, i, 1);
			ae_old_G(S, i, 1);
			while (sin >> tmp)
			{
				ae_G(index, n + tmp + 1, 1);
				ae_old_G(index, n + tmp + 1, 1);
			}
		}
		int L = 1, R = n, ans = n;
		while (L <= R)
		{
			int mid = (L + R) / 2;
			for (int i = 1; i <= m; ++ i) ae_G(n + i, T, mid);
			if (max_flow() == n)
			{
				ans = mid;
				R = mid - 1;
			}
			else
			{
				L = mid + 1;
			}
			G[T].clear();
			for (int i = 1; i <= m; ++ i) G[n + i].pop_back();
			for (int i = 1; i <= T; ++ i)
			{
				for (int j = 0; j < G[i].size(); ++ j)
				{
					G[i][j].f = old_G[i][j].f;
				}
			}
		}
		printf("%d\n", ans);
	}
}

