#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int numx[5005], numy[5005];
bool flag[105][105];
int sumx[105][105], sumy[105][105];
int lmax[150], x[150], y[150];

int main() {
	int tot = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d", &x[i], &y[i]);
			numx[i] = x[i];
			numy[i] = y[i];
		}
		sort(numx + 1, numx + n + 1);
		sort(numy + 1, numy + n + 1);
		for (int i = 1; i <= n; i ++) {
			x[i] = lower_bound(numx + 1, numx + n + 1, x[i]) - numx;
			y[i] = lower_bound(numy + 1, numy + n + 1, y[i]) - numy;
		}
		for (int i = 1; i <= n; i ++) 
			for (int j = 1; j <= n; j ++) flag[i][j] = sumx[i][j] = sumy[i][j] = 0;
		for (int i = 1; i <= n; i ++) flag[x[i]][y[i]] = 1;
	/*	for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << flag[i][j] << ' ';
			cout << endl;
		}*/
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) {
				sumx[i][j] = sumx[i][j - 1] + flag[i][j];
				sumy[i][j] = sumy[i - 1][j] + flag[i][j];
			}
		int ans = 1;
		for (int down = 1; down <= n; down ++) 
			for (int up = down + 1; up <= n; up ++) {
				for (int right = 0; right <= n; right ++) lmax[right] = -500;
				for (int right = 1; right <= n; right ++) {
					ans = max(ans, sumx[down][right] + sumx[up][right] + sumy[up - 1][right] - sumy[down][right] + lmax[right - 1]);
					lmax[right] = max(lmax[right - 1], -sumx[up][right - 1] - sumx[down][right - 1] + sumy[up - 1][right] - sumy[down][right]);
				}
			}
		tot++;
		printf("Case %d: %d\n", tot, ans);
	}
	return 0;
}
