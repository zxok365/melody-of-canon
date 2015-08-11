#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int n, l;
int x[3][1005], y[3][1005], z[3][1005];
int pre[500005], other[500005], last[500005];
int col[500005];
double mid;

int dl[511111];
int tail;
const double eps = 1e-8;

double sqr(double x) {
	return x * x;
}

void add(int u, int v) {
	l++;
	pre[l] = last[u];
	last[u] = l;
	other[l] = v;
	l++;
	pre[l] = last[v];
	last[v] = l;
	other[l] = u;
}

bool check(int i, int j, int k, int l) {
	if (sqrt(sqr(x[j][i] - x[l][k]) + sqr(y[j][i] - y[l][k]) + sqr(z[j][i] - z[l][k])) < mid - eps) return true;
	return false;
}

bool dfs(int x, int c) {
	dl[++tail] = x;
	col[x] = c;
	if (c == 1){
		for (int p = last[x]; p != 0; p = pre[p]) {
			int q = other[p];
			if (!col[q]) {
				if (!dfs(q, 3 - c)) {
					return false;
				}
			}
			else if (col[q] == col[x]) return false;
		}
	} else
	{
		int t = x;
		if (x % 2 == 1) t++; else t--;
		if (col[t] == col[x]) return false;
		return dfs(t, 3 - c);
	}
	return true;
}

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i ++) scanf("%d%d%d%d%d%d", &x[1][i], &y[1][i], &z[1][i], &x[2][i], &y[2][i], &z[2][i]);
		double left = 0;
		double right = 50000;
		while (right > left + eps) {
			mid = (left + right) / 2.0;
			for (int i = 1; i <= 2 * n; i ++) last[i] = 0;
			l = 0;
			for (int i = 1; i <= n; i ++) {
				add(2 * i - 1, 2 * i);
				col[2 * i - 1] = col[2 * i] = 0;
			}
			for (int i = 1; i <= n; i ++) 
				for (int j = i + 1; j <= n; j ++) if (i != j) {
					if (check(i, 1, j, 1)) add(2 * i - 1, 2 * j - 1);
					if (check(i, 1, j ,2)) add(2 * i - 1, 2 * j);
					if (check(i, 2, j, 1)) add(2 * i, 2 * j - 1);
					if (check(i, 2, j, 2)) add(2 * i, 2 * j);
				}
			bool f = true;
			for (int i = 1; i <= n; i ++)
			if (col[2 * i - 1] == 0){
				tail = 0;
				if (dfs(2 * i - 1, 1)) continue;
				for (int j = 1; j <= tail; j++) col[dl[j]] = 0;
				if (dfs(2 * i - 1, 2)) continue;
				right = mid;
				f = false;
				break;
			}
			if (f) left = mid;
		}
		double p = mid / 2.0;
		p = (double)((int)(p * 1000)) / 1000.0;
		printf("%.3f\n", p);
	}
	return 0;
}
