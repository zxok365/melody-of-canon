#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505, MOD = 1e9 + 9;
int x[N], cnt[N], rsum[N], a[N], b[N], C[N][N], P[N], Right[N];
int f[N][N];
int main()
{
	int n, K, i, j, k;
	scanf("%d%d", &n, &K);
	if ((n + K) % 2 != 0)
	{
		puts("0");
		return 0;	
	}
	P[0] = 1;
	for (i = 1; i <= n; ++ i) P[i] = (1LL * P[i - 1] * i) % MOD;
	for (i = 0; i <= n; ++ i) C[i][0] = 1;
	for (i = 1; i <= n; ++ i)
	{
		for (j = 1; j <= i; ++ j)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	K = (n + K) / 2;
	for (i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	for (i = 1; i <= n; ++ i) scanf("%d", &b[i]);
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	Right[0] = 0;
	for (i = 1; i <= n; ++ i)
	{
		int cur = Right[i - 1];
		while (cur + 1 <= n && b[cur + 1] < a[i]) cur ++;
		Right[i] = cur;
	}
	int tot = 0;
	for (i = 1; i <= n; i = j)
	{
		for (j = i; j <= n && Right[j] == Right[i] ; ++ j);
		tot ++;
		x[tot] = Right[i];
		cnt[tot] = j - i;
	}
	rsum[tot + 1] = 0;
	for (i = tot; i >= 1; -- i) rsum[i] = rsum[i + 1] + cnt[i];
	f[tot + 1][0] = 1;
	for (i = tot; i >= 1; -- i)
	{
		for (j = 0; j <= K + 1; ++ j)
		{
			if (j > rsum[i]) break;
			for (k = 0; k <= j; ++ k)
			{
				int tmp = 1;
				tmp = (1LL * tmp * f[i + 1][k]) % MOD;
				tmp = (1LL * tmp * C[rsum[i] - k][j - k]) % MOD;
				tmp = (1LL * tmp * C[x[i] - x[i - 1]][j - k]) % MOD;
				tmp = (1LL * tmp * P[j - k]) % MOD;
				(f[i][j] += tmp) %= MOD;
			}
		}
	}
	int s1 = 0;
	if (K < n) s1 = (1LL * f[1][K + 1] * P[n - K - 1]) % MOD;
	int s2 = (1LL * f[1][K] * P[n - K]) % MOD;
	int ans = ((s2 - s1) % MOD + MOD) % MOD;
	//printf("%d %d\n", s1, s2);
	printf("%d\n", ans);
}

