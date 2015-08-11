#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, m;
int e[N], succ[N], last[N], val[N], sum;
int f[N][20];
int dis[N], level[N];

void dfs(int i) {
	for (int j = 1; j <= 18; j++) {
		f[i][j] = f[f[i][j - 1]][j - 1];			
	}

	for (int x = last[i]; x; x = succ[x]) {
		if (e[x] == f[i][0]) {
			continue;
		}

		f[e[x]][0] = i;
		level[e[x]] = level[i] + 1;
		dis[e[x]] = dis[i] + val[x];
		dfs(e[x]);
	}

	/*for (int j = 1; j <= 18; j++) {
		f[i][j] = f[f[i][j - 1]][j - 1];
	}*/
}

int lca(int a, int b) {
	if (level[a] < level[b]) {
		swap(a, b);
	}

	for (int i = 18; i >= 0; i--) {
		if (level[f[a][i]] >= level[b]) {
			a = f[a][i];
		}
	}

	for (int i = 18; i >= 0; i--) {
		if (f[a][i] != f[b][i]) {
			a = f[a][i], b = f[b][i];
		}
	}

	if (a == b) {
		return a;
	} else {
		return f[a][0];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a++, b++;
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		val[sum] = val[sum - 1] = c;
	}

	dfs(1);
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a++, b++;
		printf("%d\n", dis[a] + dis[b] - dis[lca(a, b)] * 2);
	}

	return 0;
}

