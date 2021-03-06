#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
double f[2][1005];
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		int m, i, j, k, l = 0;
		scanf("%d %d", &m, &k);
		memset(f, 0, sizeof(f));
		f[0][0] = 1.0;
		for (i = 1; i <= m * k + 1 + k; ++ i)
		{
			for (j = 0; j <= min(i, k) ; ++ j)
			{
				double Pbad = 1.0 * (k - j + 1) / (m * k + 1 + k - i + 1);
				double Pgood = 1.0 - Pbad;
				f[1 - l][j] = 0;
				if (i - j > m * j)
				{
					if (j) f[1 - l][j] += Pbad * f[l][j - 1];
					f[1 - l][j] += Pgood * f[l][j];
				}
			}
			l = 1 - l;
		}
		printf("Case #%d: %.8f\n", ++ z, f[l][k]);
	}
}

