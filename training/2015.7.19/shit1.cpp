#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long int64;

#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

#define x first
#define y second

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;

template<class T> T abs(T x){return x < 0 ? -x : x;}

struct node
{
	node(){}
	node(int len, int u, int v):l(len),u(u),v(v){}
	int l, u, v;
	bool operator<(const node &b) const
	{
		return l < b.l;
	}
};

int sqr(int x) {return x * x;}

const int N = 5005;

node a[N * N];
int f[N][N], g[N], s[N], edge[N], fa[N], x[N], y[N];

int find(int i)
{
	if (fa[i] != i) fa[i] = find(fa[i]);
	return fa[i];
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0) break;
		int m = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &x[i], &y[i]);
			for (int j = 0; j < i; ++j)
				a[m++] = node(sqr(x[i] - x[j]) + sqr(y[i] - y[j]), i, j);

			fa[i] = i;
			s[i] = 1;
			edge[i] = 0;
			for (int j = 1; j <= n; ++j)
				f[i][j] = 0;
			f[i][1] = 1;
		}
		sort(a, a + m);
		for (int l = 0; l < m; ++l)
		{
			int r = l;
			while (r + 1 < m && a[r + 1].l == a[r].l) ++r;
			for (int i = l; i <= r; ++i)
			{
				int u = find(a[i].u);
				int v = find(a[i].v);
				if (u == v)
				{
					++edge[u];
					continue;
				}
				for (int j = 1; j <= s[u]; ++j)
					g[j] = f[u][j];
				for (int j = 1; j <= s[u] + s[v]; ++j)
					f[u][j] = 0;
				for (int j = 1; j <= s[u]; ++j)
					for (int k = 1; k <= s[v]; ++k)
						if (g[j] && f[v][k])
							f[u][j + k] = 1;
				fa[v] = u;
				s[u] += s[v];
				edge[u] += edge[v] + 1;
			}
			for (int i = 1; i <= n; ++i)
				if (find(i) == i && edge[i] == s[i] * (s[i] - 1) / 2)
					f[i][1] = 1;
			l = r;
		}
		int u = find(1);
		for (int i = 1; i <= n; ++i)
			printf("%d", f[u][i]);
		printf("\n");
	}
	return 0;
}

