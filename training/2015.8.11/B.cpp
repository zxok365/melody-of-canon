#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000000;
int f[N + 5], cnt[8][N + 5];
bool P[N + 5];
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	memset(P, true, sizeof(P));
	for (int i = 2; 2 * i <= N; ++ i)
	{
		if (P[i])
		{
			f[i] = 1;
			for (int j = 2 * i; j <= N; j += i)
			{
				P[j] = false;
				f[j] ++;
			}
		}
	}
	for (int i = 2; i <= N; ++ i)
	{
		for (int j = 1; j <= 7; ++ j)
		{
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[f[i]][i] ++;
	}
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int L, R;
		scanf("%d%d", &L, &R);
		int tmp[8];
		for (int i = 1; i <= 7; ++ i) tmp[i] = cnt[i][R] - cnt[i][L - 1];
		int ans = 1;
		for (int x = 1; x <= 7; ++ x)
		{
			if (tmp[x] == 0) continue;
			tmp[x] --;
			for (int y = x; y <= 7; ++ y)
			{
				if (tmp[y] == 0) continue;
				ans = max(ans, gcd(x, y));
			}
			tmp[x] ++;
		}
		printf("%d\n", ans);
	}
}

