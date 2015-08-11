#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 200005;
int ps[N], sum[N];
int main()
{
	int n, m, i, j, k;
	scanf("%d%d%d", &n, &m, &k);
	sum[0] = ps[0] = 0;
	for (i = 1; i <= n; ++ i)
	{
		int w, p;
		scanf("%d%d", &w, &p);
		sum[i] = sum[i - 1] + w;
		ps[i] = ps[i - 1] + p;
	}
	int ans = 0, ansi = n, ansf;
	for (i = n; i > m; -- i)
	{
		int tmp = sum[i] - sum[i - m];
		int s1 = sum[i - m];
		int f = upper_bound(sum + 1, sum + i - m, s1 - (int) ceil(1.0 * tmp / k)) - sum - 1;
		if (tmp > k * (s1 - sum[f])) break;
		tmp = ps[f] + ps[n] - ps[i];
		if (tmp > ans)
		{
			ans = tmp;
			ansi = i;
			ansf = f;
		}
	}
	if (ans)
	{
		printf("%d %d\n", ansf + n - ansi, ans);
		for (i = 1; i <= n - ansi; ++ i) putchar('H');
		for (i = 1; i <= ansf; ++ i) putchar('T');
		puts("");
	}
	else
	{
		puts("0 0");
	}
}

