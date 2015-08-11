#include<iostream>
#include<cstdio>
using namespace std;
int a[1111111];
int s[1111111][2];
int now[11];
int n, m, k;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] %= 2;
		s[(i - 1) % k + 1][a[i]]++;
	}
	now[0] = 0;
	now[1] = 100000000;
	for (int i = 1; i <= k; i++)
	{
		int p = min(now[0] + s[i][1], now[1] + s[i][0]);
		int q = min(now[1] + s[i][1], now[0] + s[i][0]);
		now[0] = p, now[1] = q;
	}
	printf("%d\n", now[0]);
}
