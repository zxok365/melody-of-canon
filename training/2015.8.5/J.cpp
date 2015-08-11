#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int f[1005][1005], x[1005], y[1005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d%d", &x[i], &y[i]);
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; ++ i) f[i][i] = 0;
	for (int len = 2; len <= n; ++ len)
	{
		for (int i = 1; i + len - 1 <= n; ++ i)
		{
			int j = i + len - 1;
			for (int k = i; k <= j; ++ k)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + x[k + 1] - x[i] + y[k] - y[j]);
			}
		}
	}
	printf("%d\n", f[1][n]);
}

