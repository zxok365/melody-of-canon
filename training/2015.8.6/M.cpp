#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define PII pair<int, int>
using namespace std;
PII st[60005];
int w[60005], h[60005];
int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == -1) break;
		w[0] = h[0] = 0;
		for (int i = 1; i <= n; ++ i) scanf("%d%d", &w[i], &h[i]);
		w[n + 1] = h[n + 1] = 0;
		int top = 1, x = 0, ans = 0;
		st[1] = PII(0, 0);
		for (int i = 1; i <= n + 1; ++ i)
		{
			int tmpx = x;
			while (h[i] < st[top].first)
			{
				ans = max(ans, (x - st[top].second) * st[top].first);
				tmpx = st[top].second;
				top --;
			}
			//printf("***%d\n", top);
			x += w[i];
			if (h[i] == st[top].first) continue;
			st[++ top] = PII(h[i], tmpx);
		}
		printf("%d\n", ans);
	}
}

