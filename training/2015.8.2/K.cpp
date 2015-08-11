#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[50005];
long long dp[2][32], ans[32];
int main()
{
	ios::sync_with_stdio(false);
	int k;
	while (cin >> s >> k)
	{
		int i, j, len = strlen(s), cur = 0;
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		bool flag = 0;
		for (i = 0; i < len; ++ i)
		{
			if (s[i] == '0') flag = 1;
			cur ^= 1;
			memset(dp[cur], 0, sizeof(dp[cur]));
			for (j = 0; j < k; ++ j) dp[cur][(j * 10 + s[i] - '0') % k] += dp[cur ^ 1][j];
			if (s[i] != '0') dp[cur][(s[i] - '0') % k] ++;
			for (j = 0; j < k; ++ j) ans[j] += dp[cur][j];
		}
		if (flag) ans[0] ++;
		for (i = 0; i < k; ++ i) cout << ans[i] << " \n"[i == k - 1];
	}
}

