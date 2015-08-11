#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
/*struct query
{
	int s, t, id;
	query() {s = t = id;}
	query(int s, int t, int id) : s(s), t(t), id(id) {}
};
bool operator < (const query &a, const query &b)
{
	return a.s > b.s;
}*/
//query Q[2000005];
pair<int, int> t[2000005];
int a[2000005], zzz[2000005], last[2222222], ans[2000005];
/*
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
	while (x)
	{
		if (tree[x]) return tree[x];
		x -= lowbit(x);
	}
	return 0;
}*/
int las[2000010];
int main()
{
	int n, m;
	while (1)
	{
		scanf("%d%d", &n, &m);
		
		if (n == 0 && m == 0) break;
	//	n = 1000000;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			zzz[i] = a[i];
			a[i] ++;
			t[i].first = a[i];
			t[i].second = i;
		}
		sort(t + 1, t + n + 1);
		t[0].second = 0;
		t[0].first = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp = t[i - 1].second;
			int tmp2 = t[i].second;
			if (t[i].first == t[i - 1].first)
				a[tmp2] = a[tmp];
			else
				a[tmp2] = a[tmp] + 1;
		}
/*

		for (i = 0; i <= n + 1; ++ i)
			las[i] = 0;

		N = n;
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
		int cur = m;
		for (i = 1; i <= m; ++ i)
		{
			while (cur >= Q[i].s)
			{
				add(nex[cur], a[cur]);
				cur --;
			}
			ans[Q[i].id] = get(Q[i].t);
		}
		for (i = 1; i <= m; ++ i)
		{
			if (ans[i] == 0) puts("OK"); else printf("%d\n", zzz[ans[i]] - 1);
		}*/
		for (int i = 0; i <= 2 * n; i++) last[i] = 2 * n;
		ans[n + 1] = 2 * n;
		for (int i = n ; i >= 1; i--)
		{
			ans[i] = ans[i + 1];	
			ans[i] = min(ans[i], last[a[i]]);
			last[a[i]] = i;
		}
	//	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
		for (int i = 1; i <= m; i++)
		{
			int p, q;
			scanf("%d%d", &p, &q);
			if (ans[p] <= q) printf("%d\n", zzz[ans[p]]); else printf("OK\n");
		}
		puts("");
	}
}

