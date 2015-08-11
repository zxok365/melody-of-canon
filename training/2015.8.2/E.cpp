#include <cstdio>
#include <iostream>

using namespace std;

int n, m, ans, flow, s, t, l;
int last[5005], pre[5005], other[5005], len[5005], cost[5005], que[5005], d[5005], father[5005];
bool vis[5005];

void add(int u, int v, int r, int w) {
	l++;
	pre[l] = last[u];
	last[u] = l;
	other[l] = v;
	len[l] = r;
	cost[l] = w;
	l++;
	pre[l] = last[v];
	last[v] = l;
	other[l] = u;
	len[l] = 0;
	cost[l] = -w;
}

bool spfa() {
	int head = 0;
	int tail = 1;
	que[1] = s;
	for (int i = 1; i <= n; i ++) d[i] = 10000000;
	d[t] = 10000000;
	d[s] = 0;
	while (head != tail) {
		head = head % 5000 + 1;
		int cur = que[head];
		vis[cur] = false;
		for (int p = last[cur]; p != 0; p = pre[p]) {
			if (len[p] <= 0) continue;
			int q = other[p];
			if (d[q] > d[cur] + cost[p]) {
				d[q] = d[cur] + cost[p];
				father[q] = p;
				if (!vis[q]) {
					vis[q] = true;
					tail = tail % 5000 + 1;
					que[tail] = q;
				}
			}
		}
	}
	if (d[t] == 10000000) return false;
	return true;
}

void update() {
	int cur = t;
	int mini = 10000000;
	while (cur != s) {
		int p = father[cur];
		mini = min(mini, len[p]);
		cur = other[p ^ 1];
	}
	cur = t;
	flow += mini;
	ans += mini * d[t];
	while (cur != s) {
		int p = father[cur];
		len[p] -= mini;
		len[p ^ 1] += mini;
		cur = other[p ^ 1];
	}
}

int main() {
	s = 101;
	t = 102;
	while (scanf("%d%d", &n, &m) == 2) {
		l = 1;
		for (int i = 1; i <= n; i ++) last[i] = 0;
		last[s] = 0;
		last[t] = 0;
		int tot1 = 0;
		int tot2 = 0;
		int u, v, a, b;
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &a, &b);
			if (a < b) {
				add(i, t, b - a, 0);
				tot1 += b - a;
			} else if (a > b) {
				add(s, i, a - b, 0);
				tot2 += a - b;
			}
		}
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v, 100000, 1);
			add(v, u, 100000, 1);
		}
		int all = max(tot1, tot2);
		ans = 0;
		flow = 0;
		while (spfa()) update();
		if (flow != all) puts("-1");
			else printf("%d\n", ans);
	}
	return 0;
}
