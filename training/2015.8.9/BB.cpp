#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct typ{
	int x, y, c, w;
} a[1000005];

struct typ2 {
	int x, y, key, id;
} tmp[1000005];

int n, m, tot, st1, ed1, st2, ed2;
int w[1005][1005], c[1005][1005];
long long key[1005][1005];

bool cmp(typ a, typ b) {
	return a.w < b.w;
}


void check(int st1, int ed1, int st2, int ed2) {
	long long max1 = -2e15;
	long long max2 = -2e15;
	long long max3 = -2e15;
	long long max4 = -2e15;
	for (int i = st1; i <= ed1; i ++) {
		max1 = max(max1, 0LL + a[i].x + a[i].y + key[a[i].x][a[i].y]);
		max2 = max(max2, 0LL + a[i].x - a[i].y + key[a[i].x][a[i].y]);
		max3 = max(max3, 0LL - a[i].x + a[i].y + key[a[i].x][a[i].y]);
		max4 = max(max4, 0LL - a[i].x - a[i].y + key[a[i].x][a[i].y]);
	}
	for (int i = st2; i <= ed2; i ++) {
		int x = a[i].x;
		int y = a[i].y;
		key[x][y] = 0;
		key[x][y] = max(key[x][y], max1 - x - y + a[i].c);
		key[x][y] = max(key[x][y], max2 - x + y + a[i].c);
		key[x][y] = max(key[x][y], max3 + x - y + a[i].c);
		key[x][y] = max(key[x][y], max4 + x + y + a[i].c);
	}
}

void solve() {
	for (int i = 1; i <= tot; i ++) {
		if (a[i].w == a[1].w) key[a[i].x][a[i].y] = a[i].c;
		else break;
	}
	for (int i = 1; i <= tot; i ++) {
		int j;
		for (j = i; j <= tot && a[j].w == a[i].w; j ++);
		if (j > tot) break;
		st1 = i;
		ed1 = j - 1;
		for (; j <= tot && a[j].w == a[ed1 + 1].w; j ++);
		st2 = ed1 + 1;
		ed2 = j - 1;
		check(st1, ed1, st2, ed2);
		i = ed1;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) scanf("%d", &w[i][j]);
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= m; j ++) scanf("%d", &c[i][j]);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			if (w[i][j] == 0) continue;
			++tot;
			a[tot].x = i;
			a[tot].y = j;
			a[tot].w = w[i][j];
			a[tot].c = c[i][j];
		}
	sort(a + 1, a + tot + 1, cmp);
	solve();
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++)
			ans = max(ans, key[i][j]);	
	}
	cout << ans << endl;
	return 0;
}

