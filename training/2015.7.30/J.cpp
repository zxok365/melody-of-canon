#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MOD = (int) (1e9 + 7);
int dp[100005], P[100005];
int main()
{
	int n, m;
	P[0] = 1;
	for (n = 1; n <= 100000; ++ n) P[n] = (2LL * P[n - 1]) % MOD;
	while (scanf("%d%d", &n, &m) == 2)
	{
		int tmp, i, j, k;
		tmp = dp[0] = 1;
		for (i = 1; i <= n; ++ i)
		{
			dp[i] = tmp;
			(tmp += dp[i]) %= MOD;
			if (i >= m) tmp = (1LL * tmp - dp[i - m] + MOD) % MOD;
		}
		int ans = 0;
		for (i = 1; i + m - 1 <= n; ++ i)
		{
			(ans += (1LL * dp[i - 1] * P[n - i - m + 1]) % MOD) %= MOD;
		}
		printf("%d\n", ans);
	}
}

