#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int BN = 65537;
bool v[BN];
int f[BN], n;
char s[2][10];
bool get(int B, int x, int y)
{
	int ind = x * n + y;
	if (B & (1 << ind)) return 1;
	return 0;
}
int set(int B, int x, int y)
{
	int ind = x * n + y;
	return B - (1 << ind);
}
int dfs(int B)
{
	if (B == 0) return 0;
	if (v[B]) return f[B];
	v[B] = 1;
	int ans = 10000000;
	for (int i = 0; i < 2; ++ i)
	{
		for (int j = 0 ; j < n; ++ j)
		{
			int cnt = 0;
			char c = '*';
			int BB = B;
			for (int k = j; k < n; ++ k)
			{
				if (get(B, i, k))
				{
					if (c == '*' || s[i][k] == c)
					{
						c = s[i][k];
						cnt ++;
						BB = set(BB, i, k);
					}
					else
					{
						break;
					}
				}
				if (cnt) ans = min(ans, dfs(BB) + 1);
			}
			if (i == 1) continue;
			BB = B;
			c = '*';
			cnt = 0;
			for (int k = j; k < n; ++ k)
			{
				if (get(B, i, k))
				{
					if (c == '*' || s[i][k] == c)
					{
						c = s[i][k];
						cnt ++;
						BB = set(BB, i, k);
					}
					else
					{
						break;
					}
				}
				if (get(B, i + 1, k))
				{
					if (c == '*' || s[i + 1][k] == c)
					{
						c = s[i + 1][k];
						cnt ++;
						BB = set(BB, i + 1, k);
					}
					else
					{
						break;
					}
				}
				//if (i == 0 && j == 0 && k == 2)
				//printf("* %d %d   %d %d %d\n", B, BB, i, j, k);
				if (cnt) ans = min(ans, dfs(BB) + 1);
			}
		}
	}
	return f[B] = ans;
}
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d", &n);
		scanf("%s%s", s[0], s[1]);
		for (int i = 0; i < (1 << n + n); ++ i) v[i] = 0;
		printf("Case #%d: %d\n", ++ z, dfs((1 << n + n) - 1));
	}
}

