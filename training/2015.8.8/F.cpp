#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int num[50][50];
char s[50][50];
int last[50005], pre[50005], other[50005], d[50005], len[50005], que[50005], ans, l;
bool vis[50005];

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

void add(int u, int v, int r) {
	l++;
	pre[l] = last[u];
	last[u] = l;
	other[l] = v;
	len[l] = r;
}

void BFS(int x) {
	int head = 5000;
	int tail = 5001;
	que[tail] = x;
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= m; j ++) vis[num[i][j]] = false;
	d[x] = 0;
	vis[x] = true;
	while (head != tail) {
		int cur = que[++head];
		for (int p = last[cur]; p != 0; p = pre[p]) {
			int q = other[p];
			if (!vis[q]) {
				vis[q] = true;
				if (len[p] == 0) {
					d[q] = d[cur];
					que[head] = q;
					head--;
				} else {
					d[q] = d[cur] + 1;
					if (d[q] >= ans) return;
					que[++tail] = q;
				}
			}
		}
	}
	int mx = -1;
	for (int i = 1; i <= num[n][m]; i ++) mx = max(mx, d[i]);
	ans = min(ans, mx);
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
		l = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++) {
				num[i][j] = (i - 1) * m + j;
				last[num[i][j]] = 0;
			}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				for (int k = 1; k <= 4; k ++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 1 || x > n || y < 1 || y > m) continue;
					int le;
					if (s[i][j] != s[x][y])
						le = 1;
					else
						le = 0;
					add(num[i][j], num[x][y], le);
					add(num[x][y], num[i][j], le);
				}
		ans = 100000;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if ((j == 1 || s[i][j] != s[i][j - 1]) && (i == 1 || s[i][j] != s[i - 1][j]))
					BFS(num[i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
