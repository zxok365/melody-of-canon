#include <cstdio>
#include <iostream>

using namespace std;

int n, m, u, v, r, l, l2;
int d1[2005], d2[2005], last[2005];
int pre[120005], other[120005], len[120005];
int last2[2005], d[2005], que[5005];
int pre2[120005], other2[120005], len2[120005];
bool vis[2005];

void Init() {
	l = 0;
	l2 = 1;
	for (int i = 1; i <= n; i++) d1[i] = (1<<29);
	for (int i = 1; i <= n; i++) d2[i] = (1<<29);
	for (int i = 1; i <= n; i++) last[i] = 0;
	for (int i = 1; i <= n; i++) last2[i] = 0;
	for (int i = 1; i <= n; i++) vis[i] = 0;
}

void add(int u, int v, int r) {
	l++;
	pre[l] = last[u];
	last[u] = l;
	other[l] = v;
	len[l] = r;
}

void add2(int u, int v, int r) {
	l2++;
	pre2[l2] = last2[u];
	last2[u] = l2;
	other2[l2] = v;
	len2[l2] = r;
	l2++;
	pre2[l2] = last2[v];
	last2[v] = l2;
	other2[l2] = u;
	len2[l2] = 0;
}

void SPFA() {
	int head = 0;
	int tail = 1;
	que[1] = 1;
	d1[1] = 0;
	d2[1] = 0;
	while (head != tail) {
		head = head % 5000 + 1;
		int cur = que[head];
		vis[cur] = false;
		int p = last[cur];
		while (p != 0) {
			int q = other[p];
			if (d1[q] == d1[cur] + len[p]) {
				if (d2[q] > d2[cur] + 1) {
					d2[q] = d2[cur] + 1;
					if (!vis[q]) {
						vis[q]=true;
						tail = tail % 5000 + 1;
						que[tail] = q;
					}
				}
			}
			if (d1[q] > d1[cur] + len[p]) {
				d1[q] = d1[cur] + len[p];
				d2[q] = d2[cur] + 1;
				if (!vis[q]) {
					vis[q] = true;
					tail = tail % 5000 + 1;
					que[tail] = q;
				}
			}
			p = pre[p];
		}
	}
}

void find_G() {
	int head = 0;
	int tail = 1;
	que[1] = n;
	vis[n] = true;
	while (head != tail) {
		head = head % 5000 + 1;
		int cur = que[head];
		int p = last[cur];
		while (p != 0) {
			int q = other[p];
			if (d1[q] == d1[cur] - len[p]) {
				if (!vis[q]) {
					vis[q] = true;
					tail = tail % 5000 + 1;
					que[tail] = q;
				}
				add2(q, cur, 1);
			}
			p = pre[p];
		}
	}
}

bool BFS() {
	int head = 0;
	int tail = 1;
	que[1] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; i++) d[i] = 0;
	while (head != tail) {
		head = head % 5000 + 1;
		int cur = que[head];
		int p = last2[cur];
		while (p != 0) {
			if (len2[p] > 0) {
				int q = other2[p];
				if (d[q] == 0) {
					d[q] = d[cur] + 1;
					if (q == n) return true;
					tail = tail % 5000 + 1;
					que[tail] = q;
				}
			}
			p = pre2[p];
		}
	}
	return false;
}

int dinic(int x, int flow) {
	if (x == n) return flow;
	int tmp = flow;
	int p = last2[x];
	while (p != 0) {
		int q = other2[p];
		if (len2[p] > 0 && d[q] == d[x] + 1 && tmp > 0) {
			int res = dinic(q, min(tmp, len2[p]));
			len2[p] -= res;
			len2[p ^ 1] += res;
			tmp -= res;
		}		
		p = pre2[p];
	}
	return flow-tmp;
}

int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		Init();
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d", &u, &v, &r);
			add(u, v, r);
			add(v, u, r);
		}
		SPFA();
		int ans2 = m - d2[n];
		find_G();
		int ans1=0;
		while (BFS()) 
			ans1 += dinic(1, (1<<29));
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
