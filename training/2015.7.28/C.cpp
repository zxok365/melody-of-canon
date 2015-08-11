#include <cstdio>
#include <iostream>

using namespace std;

int last[100005], pre[500005], other[500005];
bool vis[100005];
int n, m, l;
long long ans;
long long size[500005];

long long abs(long long x) {
	if (x < 0) x = -x;
	return x;
}

void add(int u, int v) {
	l++;
	pre[l] = last[u];
	last[u] = l;
	other[l] = v;
}

void dfs(int x) {
	vis[x] = true;
	for (int p = last[x]; p != 0; p = pre[p]) {
		int q = other[p];
		if (!vis[q]) {
			dfs(q);
			size[x] += size[q];
		}
	}
}

void DP(int x, int fa) {
	for (int p = last[x]; p != 0; p = pre[p]) {
		int q = other[p];
		if (q != fa) {
			DP(q, x);
			if (abs(size[q] - (size[1] - size[q])) < ans) 
				ans = abs(size[q] - (size[1] - size[q]));
		}
	}
}

int main() {
	int tot = 0;
	while (1) {
		tot ++;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i ++) {
			last[i] = 0;
			vis[i] = 0;
		}
		l = 0;
		int tmp;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &tmp);
			size[i] = tmp;
		}
		int u, v;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		dfs(1);
		ans = 1ll<<60ll;
		DP(1, 0);
		printf("Case %d: ", tot);
		cout << ans << endl;
	}
	return 0;
}
