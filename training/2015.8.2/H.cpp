#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005, INF = 0x3f3f3f3f;
pair<int, int> link[N];
int ans[N];
int main()
{
	int n, m, q, i, j, k;
	while (scanf("%d%d%d", &n, &m, &q) == 3)
	{
		for (i = 1; i <= m; ++ i)
		{
			scanf("%d%d", &j, &k);
			link[i] = make_pair(j,k);
		}
		sort(link + 1, link + m + 1);
		int a = INF, b = INF, now = m;
		for (i = n; i >= 1; -- i)
		{
			while (link[now].first == i && now > 0)
			{
				int c = link[now].second;
				if (c <= a)
				{
					b = a;
					a = c;
				}
				else if (c <= b)
				{
					b = c;
				}
				now--;
			}
			ans[i] = b;
		}
		for (i = 1; i <= q; ++ i)
		{
			scanf("%d", &j);
			printf("%d\n", max(j - ans[j], 0));
		}
	}
}

