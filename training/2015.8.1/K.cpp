#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ULL unsigned long long
#define PUU pair<unsigned long long, unsigned long long>
#define MOD1 137
#define MOD2 139
using namespace std;
PUU list[3000005];
int sz = 0;
char s[100];
PUU tmp[5];
PUU operator + (PUU a, PUU b)
{
	return PUU(a.first + b.first, a.second + b.second);
}
PUU operator * (PUU a, PUU b)
{
	return PUU(a.first * b.first, a.second * b.second);
}
PUU hash(char *s)
{
	int n = strlen(s);
	PUU res = PUU(0, 0);
	for (int i = 0; i < n; ++ i)
	{
		res = res * PUU(MOD1, MOD2) + PUU(s[i], s[i]);
	}
	return res;
}
int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; ++ i)
	{
		int m;
		scanf("%d", &m);
		for (j = 1; j <= m; ++ j)
		{
			scanf("%s", s);
			tmp[j] = hash(s);
		}
		for (j = 1; j < (1 << m); ++ j)
		{
			PUU H = PUU(1, 1);
			for (k = 0; k < m; ++ k) if (j & (1 << k)) H = H * tmp[k + 1];
			list[sz ++] = H;
			//cout << H.first << " " << H.second << endl;
		}
		//cout << "***" << endl;
	}
	sort(list, list + sz);
	scanf("%d", &n);
	for (i = 1; i <= n; ++ i)
	{
		int m;
		scanf("%d", &m);
		PUU H = PUU(1, 1);
		for (j = 1; j <= m; ++ j)
		{
			scanf("%s", s);
			H = H * hash(s);
		}
		//cout << "###" << H.first << " " << H.second << endl;
		int ans = upper_bound(list, list + sz, H) - lower_bound(list, list + sz, H);
		printf("%d\n", ans);
	}
}

