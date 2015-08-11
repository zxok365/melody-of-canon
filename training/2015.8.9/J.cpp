#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define PII pair<int, int>
using namespace std;
PII a[1000005];
bool cmp(PII a, PII b)
{
	return a.second > b.second;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		a[i] = PII(s, t);
	}
	sort(a, a + n, cmp);
	int cur = 1e9 + 100;
	for (int i = 0; i < n; ++ i)
	{
		cur = min(a[i].second - a[i].first + 1, cur - a[i].first);
		//printf("**%d\n", cur);
	}
	printf("%d\n", cur - 1);
}

