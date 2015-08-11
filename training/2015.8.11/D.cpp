#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[55][55];
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= n + 1; ++ i)
			for (int j = 0; j <= n + 1; ++ j)
				s[i][j] = '0';
		for (int i = 1; i <= n; ++ i) scanf("%s", s[i] + 1);
		int m = strlen(s[1] + 1);
		int ans = 0;
		for (int i = 1; i <= n; ++ i)
		{
			for (int j = 1; j <= m; ++ j)
			{
				if (s[i][j] == 'R' || s[i][j] == 'G')
				{
					if (s[i - 1][j - 1] != 'R' && s[i - 1][j - 1] != 'G') ans ++;
				}
				if (s[i][j] == 'B' || s[i][j] == 'G')
				{
					if (s[i - 1][j + 1] != 'B' && s[i - 1][j + 1] != 'G') ans ++;
				}
			}
		}
		printf("%d\n", ans);
	}
}

