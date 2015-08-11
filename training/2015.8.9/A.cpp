#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int c[64000], num[64000], f[100][70005], sum[64000];

int main() {
	scanf("%d%d", &n, &m);
	int max_c = 0;
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &num[i]);
		max_c = max(max_c, num[i]);
	}
//	for (int i = 0; i <= max_c; i ++)
//		for (int j = 0; j <= m; j ++) f[i][j] = - (1 << 20);
	f[0][0] = 0;
	for (int i = 1; i <= max_c; i ++) {
		for (int j = 0; j <= m; j++)
			f[i][j] = f[i - 1][j];
		for (int k = m; k >= 0; k --) {
			int tot = 0;
			for (int j = 1; j <= n; j ++) {
				if (num[j] >= i) {
					tot += c[j];
				if (k >= c[j])
					f[i][k] = max(f[i][k], f[i - 1][k - c[j]] + tot);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i ++) ans = max(ans, f[max_c][i]);
	printf("%d\n", ans);
	return 0;
}
