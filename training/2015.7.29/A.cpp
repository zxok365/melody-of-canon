#include <cstdio>
#include <iostream>

using namespace std;

int n, m, l, ans;
int last[50005], pre[50005], other[50005], d[50005], father[50005], que[50005];
int ok[50006];

void add(int u, int v) {
	l++;
	pre[l]= last[u];
	last[u] = l;
	other[l] = v;
}

void BFS(int x) {
	int head = 0;
	int tail = 1;
	que[1] = x;
	for (int i = 0; i < n; i ++) d[i] = 1 << 20;
	for (int i = 0; i < n; i ++) father[i] = -1;
	d[x] = 1;
	while (head != tail) {
		int cur = que[++head];
		if (d[cur] >= ans) continue;
		for (int p = last[cur]; p != 0; p = pre[p]) {
			int q = other[p];
			if (d[q] == (1<<20)) {
				d[q] = d[cur] + 1;
				father[q] = cur;
				que[++tail] = q;
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= tail; i ++) {
		int cur = que[i];
		for (int p = last[cur]; p != 0; p = pre[p]) {
			int q = other[p];
			if (q != father[cur] && cur != father[q]) {
				flag = true;
				ans = min(ans, d[cur] + d[q] - 1);
			}
		}
	}
	if (!flag) {
		for (int i = 1; i <= tail; i ++) ok[que[i]] = false;
	}
}

int main() {
	int test;
	scanf("%d", &test);
	int tot = 0;
	while (test--) {
		tot++;
		int u, v;
		scanf("%d%d", &n, &m);
		l = 0;
		ans = (1 << 20);
		for (int i = 0; i < n; i ++) last[i] = 0;
		for (int i = 0; i < n; i ++) ok[i] = true;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		for (int i = 0; i < n; i ++) {
			if (!ok[i]) continue;
			BFS(i);
		}
		printf("Case %d: ", tot);
		if (ans == (1<<20)) puts("impossible");
			else printf("%d\n", ans);
	}
}
