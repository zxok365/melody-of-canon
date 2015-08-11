#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct road
{
	int a, b, d;
	road() {a = b = d = 0;}
	road(int a, int b, int d) : a(a), b(b), d(d) {}
};
struct query
{
	int u, v, id;
	long long ans;
	query() {u = v = id = ans = 0;}
	query(int u, int v, int id, long long ans) : u(u), v(v), id(id), ans(ans) {}
};
bool operator < (const road &a, const road &b)
{
	return a.b < b.b;
}
bool cmp0(const road &a, const road &b)
{
	return a.b < b.b;
}
bool cmp1(const query &a, const query &b)
{
	return a.b < b.b;
}
long long tree[100005];
long long sum[100005];
road list[200005];
query qlist[200005];
int n;
inline lowbit(int x) {return x & -x;}
int get(int x)
{
	long long res = 0;
	while (x)
	{
		res = max(res, tree[x]);
		x -= lowbit(x);
	}
	return res;
}
void add(int x, long long c)
{
	while (x <= n)
	{
		tree[x] = max(x, c);
		x += lowbit(x);
	}
}
int main()
{
	int m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		int i, j, k, l;
		sum[1] = 0;
		for (i = 2; i <= n; ++ i)
		{
			scanf("%d", &j);
			sum[i] = sum[i - 1] + j;
		}
		for (i = 1; i <= m; ++ i)
		{
			scanf("%d%d%d", &j, &k, &l);
			list[i] = road(j, k, l);
		}
		sort(list + 1, list + 1 + m, cmp0);
		int Q;
		scanf("%d", &Q);
		for (i = 1; i <= Q; ++ i)
		{
			scanf("%d%d", &j, &k);
			qlist[i] = query(j, k, i, 0);
		}
		sort(qlist + 1, qlist + 1 + Q, cmp1);
		j = 1;
		memset(tree, 0, sizeof(tree));
		for (i = 1; i <= Q; ++ i)
		{
			if (qlist[i].u > qlist[i].v) continue;
			while (j <= m && list[j].b <= qlist[i].b)
			{
				if (list[j].a < list[j].v)
				{
					add(list[j].a, (sum[list[j].b] - sum[list[j].a]) - list[j].d);
				}
				++ j;
			}
			long long tmp =  sum[qlist[i].v] - sum[qlist[i].u] - get(qlist[i].u);
			qlist[i].ans = tmp;
		}
	}
}

