#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct query
{
	int s, t, id;
	query() {s = t = id;}
	query(int s, int t, int id) : s(s), t(t), id(id) {}
};
bool operator < (const query &a, const query &b)
{
	if (a.s != b.s) return a.s > b.s;
	return a.t > b.t;
}
query Q[2000005];
int a[2000005], tree[2000005], N, nex[2000005], ans[2000005];
inline int lowbit(int x) {return x & -x;}
void add(int x, int c)
{
	while (x <= N && tree[x] == 0)
	{
		tree[x] = c;
		x += lowbit(x);
	}
}
int get(int x)
{
	while (x > 0)
	{
		if (tree[x]) return tree[x];
		x -= lowbit(x);
	}
	return 0;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		int i, j, k;
		for (i = 1; i <= n; ++ i) scanf("%d", &a[i]), a[i] ++;
		N = n;
		map<int, int> las;
		for (i = n; i >= 1; -- i)
		{
			nex[i] = las[a[i]];
			if (nex[i] == 0) nex[i] = 2 * N;
			las[a[i]] = i;
		}
		for (i = 1; i <= m; ++ i)
		{
			scanf("%d%d", &j, &k);
			Q[i] = query(j, k, i);
		}
		for (i = 1; i <= n; ++ i) tree[i] = 0;
		sort(Q + 1, Q + 1 + m);
		int cur = n;
		for (i = 1; i <= m; ++ i)
		{
			//printf("in %d\n", i);
			while (cur >= Q[i].s && cur > 0)
			{
				add(nex[cur], a[cur]);
				cur --;
			}
			ans[Q[i].id] = get(Q[i].t);
		}
		for (i = 1; i <= m; ++ i)
		{
			if (ans[i] == 0) puts("OK"); else printf("%d\n", ans[i] - 1);
		}
		puts("");
	}
}
