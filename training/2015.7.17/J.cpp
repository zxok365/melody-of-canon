#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct ad
{
	int ind, cl, len;
	ad(int a, int b, int c) {ind = a; cl = b; len = c;}
	ad() {ind = cl = len = 0;}
};
bool operator < (const ad &a, const ad &b)
{
	if (a.ind != b.ind) return a.ind < b.ind;
	return a.cl > b.cl;
}
ad A[500005];
long long sum[500005], ans[500005];
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		int n, m, i, j, k, l, Q;
		scanf("%d %d %d", &n, &m, &Q);
		for (int i = 1; i <= m; i++) ans[i] = 0;
		for (i = 1; i <= m; ++ i)
		{
			scanf("%d %d %d", &j, &k, &l);
			A[i] = ad(j, k, l);
		}
		sort(A + 1, A + 1 + m);
		A[0] = ad();
		j = 0;
		l = 0;
		for (i = 1; i <= m; ++ i)
		{
			if (A[i].ind != A[i - 1].ind)
			{
				j = 1;
				ans[j] += A[i].len;
			}
			else
			{
				++ j;
				ans[j] += A[i].len;
			}
		//	printf("*** %d %lld\n", j, sum[i]);
			l = max(l, j);
		}
		for (int i = 1; i <= l; i++)
			ans[i] = ans[i - 1] + ans[i];
		printf("Case #%d:\n", ++ z);
		for (i = 1; i <= Q; ++ i)
		{
			scanf("%d", &k);
			k = min(k, l);
			printf("%lld\n", ans[k]);
		}
	}
}

