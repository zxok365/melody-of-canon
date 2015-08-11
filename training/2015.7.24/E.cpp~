#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define PII pair<int, int>
using namespace std;
int h[55], p[55], f[505], ff[505], ind[105];
int hh[55], pp[55];
bool cmp(int i, int j)
{
	return p[i] < p[j];
}
PII q[505];
int main()
{
	int T, n, H, W, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d %d %d", &n, &H, &W);
		int TOP = 0, RM = 0, i, j, k, LM;
		bool first = 1;
		for (i = 1; i <= n; ++ i)
		{
			scanf("%d%d", &p[i], &h[i]);
			TOP = max(TOP, h[i]);
		}
		if (TOP <= H)
		{
			printf("Case #%d: 0\n", ++ z);
			continue;
		}
		h[0] = 0;
		int ans = -1;
eee:
		RM = 0, LM = 0x3f3f3f3f;
		for (i = 1; i <= n; ++ i) ind[i] = i, RM = max(RM, p[i]), LM = min(LM, p[i]);
		sort(ind + 1, ind + 1 + n, cmp);
		for (i = 1; i <= n; ++ i)
		{
			hh[i] = h[ind[i]];
			pp[i] = p[ind[i]];
		}
		for (i = 1; i <= n; ++ i)
		{
			h[i] = hh[i];
			p[i] = pp[i];
			//printf("*** %d %d\n", h[i], p[i]);
		}
		memset(f, 0x3f, sizeof(f));
		for (i = 1; i <= n; ++ i)
		{
			//for (j = 1; j <= RM; ++ j) printf("%20d", f[j]);
			//printf("\n");
			if (h[i] <= H)
			{
				memset(f, 0x3f, sizeof(f));
				for (j = p[i]; j <= RM; ++ j) f[j] = (j - p[i]) * h[i];
				continue;
			}
			if (h[i] - h[i - 1] > H)
			{
				memset(f, 0x3f, sizeof(f));
				continue;
			}
			if (h[i] == TOP)
			{
				//printf("###%d %d\n", max(1, p[i] - W), p[i] - 1);
				int tmp = 0x3f3f3f3f;
				for (j = max(LM, p[i] - W); j < p[i]; ++ j)
				{
					tmp = min(tmp, f[j]);
				}
				if (tmp < 0x3f3f3f3f && (ans == -1 || ans > tmp))
				{
					ans = tmp;
				}
				memset(f, 0x3f, sizeof(f));
				continue;
			}
			memset(ff, 0x3f, sizeof(ff));
			/*
			for (k = LM; k <= RM; ++ k)
			{
				for (j = max(LM, k - W); j < k; ++ j)
				{
					ff[k] = min(ff[k], abs(p[i] - k) * h[i] + f[j]);
				}
			}*/
			int head = 0, tail = 0;
			for (k = LM + 1; k <= RM; ++ k)
			{
				while (head < tail && q[tail - 1].second >= f[k - 1]) tail --;
				q[tail ++] = PII(k - 1, f[k - 1]);
				while (head < tail && q[head].first < k - W) head ++;
				if (head < tail)
				{
					ff[k] = abs(p[i] - k) * h[i] + q[head].second;
				}
			}
			for (j = LM; j <= RM; ++ j) f[j] = ff[j];
		}
		if (first)
		{
			for (i = 1; i <= n; ++ i)
			{
				p[i] = RM - p[i] + 1;
			}
			first = 0;
			goto eee;
		}
		printf("Case #%d: %d\n", ++ z, ans);
	}
}

