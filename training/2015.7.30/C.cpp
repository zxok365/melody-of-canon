#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int vec[50005];
int n, k, x, y;
int f[105][105][130];
int b[105], c[105], d[105], a[105], tool[105];

int main() {
	while (scanf("%d%d", &k, &n) == 2) {
		for (int i = 1; i <= k; i ++) {
			scanf("%d%d%d", &b[i], &c[i], &d[i]);
		}
		for (int i = 1; i <= n; i ++) {
			tool[i] = 0;
			int sum;
			scanf("%d%d", &a[i], &sum);
			while (sum--) {
				int p;
				scanf("%d", &p);
				tool[i] |= (1 << (p - 1));
			}
		}
		scanf("%d%d", &x, &y);
		y = min(y, n);
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= y; j ++)
				for (int mask = 0; mask < (1 << k); mask ++) f[i][j][mask] = -(1 << 25);
		f[0][0][0] = 0;
		for (int j = 0; j <= y; j ++)
			for (int i = 0; i < n; i ++) 
				for (int mask = 0; mask < (1 << k); mask ++) {
					if (f[i][j][mask] < 0) continue;
					if (j < y) f[i + 1][j + 1][mask | tool[i + 1]]	= max(f[i + 1][j + 1][mask | tool[i + 1]], f[i][j][mask] + a[i + 1]);
					f[i + 1][j][mask] = max(f[i + 1][j][mask], f[i][j][mask]);
				}
		int ans = 0;
		for (int mask1 = 0; mask1 < (1 << k); mask1 ++)
			for (int mask2 = 0; mask2 < (1 << k); mask2 ++) {
				int sum = 0;
				int power_now = - 1;
				for (int p = 0; p <= y; p ++) power_now = max(power_now, f[n][p][mask2]);
				if (power_now < 0) continue;
				int rest = x;
				for (int i = 1; i <= k; i ++) {
					int num1 = (mask1 & (1 << (i - 1)));
					int num2 = (mask2 & (1 << (i - 1)));
					if (num1 != 0 && num2 != 0) {
						power_now += b[i] * c[i] + d[i];
						rest -= b[i] - 1;
					}
					if (num1 != 0 && num2 == 0) {
						power_now += b[i] * c[i] + d[i];
						rest -= b[i];
					}
					if (num1 == 0 && num2 != 0) {
						for (int t = 1; t <= b[i] - 1; t ++) vec[++sum] = c[i];
						power_now += c[i];
					}
					if (num1 == 0 && num2 == 0) {
						for (int t = 1; t <= b[i]; t ++) vec[++sum] = c[i];
					}
				}
				if (rest < 0) continue;
				sort(vec + 1, vec + sum + 1);
				for (int i = sum; i >= 1; i --) {
					if (rest == 0) break;
					power_now += vec[i];
					rest--;
				}
				if (ans < power_now) {
					ans = power_now;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
