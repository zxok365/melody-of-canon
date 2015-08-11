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

bool cmp1(typ2 a, typ2 b) {
	return a.key < b.key;
}

void check(int st1, int ed1, int st2, int ed2) {
	int cnt = 0;
	for (int i = st1; i <= ed2; i ++) {
		++cnt;
		tmp[cnt].x = a[i].x;
		tmp[cnt].y = a[i].y;
		tmp[cnt].key = a[i].x + a[i].y;
		if (i <= ed1) tmp[cnt].id = 1;
			else tmp[cnt].id = 2;
	}
	
	
	sort(tmp + 1, tmp + cnt + 1, cmp1);

	long long max_s = 0;
	for (int i = 1; i <= cnt; i ++) {
		int j;
		for (j = i; j <= cnt && tmp[j].key == tmp[i].key; j ++) {
			if (tmp[j].id == 1) max_s = max(max_s, - tmp[j].key + key[tmp[j].x][tmp[j].y]);
		}
		for (int k = i; k < j; k ++) {
			if (tmp[k].id == 1) continue;
			key[tmp[k].x][tmp[k].y] = max(key[tmp[k].x][tmp[k].y], max_s + tmp[k].key + c[tmp[k].x][tmp[k].y]);
		}
		i = j - 1;
	}

	max_s = 0;
	for (int i = cnt; i >= 1; i --) {
		int j;
		for (j = i; j >= 1 && tmp[j].key == tmp[i].key; j --){
			if (tmp[j].id == 1) max_s = max(max_s, + tmp[j].key + key[tmp[j].x][tmp[j].y]);
		}
		for (int k = i; k > j; k --) {
			if (tmp[k].id == 1) continue;
			key[tmp[k].x][tmp[k].y] = max(key[tmp[k].x][tmp[k].y], max_s - tmp[k].key + c[tmp[k].x][tmp[k].y]);
		}
		i = j + 1;
	}

	cnt = 0;
	for (int i = st1; i <= ed2; i ++) {
		cnt++;
		tmp[cnt].x = a[i].x;
		tmp[cnt].y = a[i].y;
		tmp[cnt].key = a[i].x - a[i].y;
		if (i <= ed1) tmp[cnt].id = 1;
			else tmp[cnt].id = 2;
	}

	sort(tmp + 1, tmp + cnt + 1, cmp1);
	max_s = 0;
	for (int i = 1; i <= cnt; i ++) {
		int j;
		for (j = i; j <= cnt && tmp[j].key == tmp[i].key; j ++) {
			if (tmp[j].id == 1) max_s = max(max_s, - tmp[j].key + key[tmp[j].x][tmp[j].y]);
		}
		for (int k = i; k < j; k ++) {
			if (tmp[k].id == 1) continue;
			key[tmp[k].x][tmp[k].y] = max(key[tmp[k].x][tmp[k].y], max_s + tmp[k].key + c[tmp[k].x][tmp[k].y]);
		}
		i = j - 1;
	}

	max_s = 0;
	for (int i = cnt; i >= 1; i --) {
		int j;
		for (j = i; j >= 1 && tmp[j].key == tmp[i].key; j --) {
			if (tmp[j].id == 1) max_s = max(max_s, + tmp[j].key + key[tmp[j].x][tmp[j].y]);
		}
		for (int k = i; k > j; k --) {
			if (tmp[k].id == 1) continue;
			key[tmp[k].x][tmp[k].y] = max(key[tmp[k].x][tmp[k].y], max_s - tmp[k].key + c[tmp[k].x][tmp[k].y]);
		}
		i = j + 1;
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
		for (int j = 1; j <= m; j ++) {
			ans = max(ans, key[i][j]);	
		}
	}
	cout << ans << endl;
	return 0;
}
