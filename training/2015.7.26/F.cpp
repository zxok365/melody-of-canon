#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105][105], b[105][105];
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		int n, i, j, K, l, dif = 0;
		scanf("%d%d", &n, &K);
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j)
			{
				scanf("%d", &b[i][j]);
				if (b[i][j] != a[i][j]) dif ++;
			}
		}
		bool flag = 1;
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j)
			{
				if (a[i][j] != b[i][j])
				{
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag)
		{
			printf("Case %d: %d\n", ++ z, 0);
			continue;
		}
		flag = 1;
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j)
			{
				if (b[i][j] != b[j][i])
				{
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag)
		{
			printf("Case %d: %d\n", ++ z, -1);
			continue;
		}
		int last_i, last_j, cnt = 0;
		int aaaa = 0, abab = 0;
		for (i = 1; i <= n; ++ i)
		{
			for (j = i + 1; j <= n; ++ j)
			{
				if (a[i][j] != b[i][j] || a[j][i] !=b[j][i])
				{
					cnt ++;
					last_i = i;
					last_j = j;
				}
				else
				{
					if (a[i][j] == a[j][i])
					{
						aaaa ++;
					}
					else
					{
						abab ++;
					}
				}
			}
		}
		if (cnt >= 2)
		{
			printf("Case %d: %d\n", ++ z, dif);
			continue;
		}
		//printf("***%d\n", cnt);
		if (a[last_i][last_j] == b[last_j][last_i] && a[last_j][last_i] == b[last_i][last_j])
		{
			if (abab > 0)
			{
				printf("Case %d: %d\n", ++ z, dif);
			}
			else if (K >= 3)
			{
				printf("Case %d: %d\n", ++ z, dif + 1);
			}
			else
			{
				if (n <= 2)
				{
					printf("Case %d: %d\n", ++ z, -1);
				}
				else
				{
					printf("Case %d: %d\n", ++ z, dif + 2);
				}
			}
		}
		else
		{
			printf("Case %d: %d\n", ++ z, dif);
		}
	}
}

