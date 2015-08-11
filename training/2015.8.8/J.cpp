#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
const int MOD = 7;
int ex(int x)
{
	if (x <= n % 7) return 1;
	return 0;
}
int mpow(int x, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1) (res *= x) %= MOD;
		n >>= 1;
		(x *= x) %= MOD;
	}
	return res;
}
int invers(int x)
{
	return mpow(x, MOD - 2);
}
int sum(int A, int i, int n)
{
	return (A * (mpow(i, n) + MOD - 1) * invers(i - 1)) % MOD;
}
char day[7][50] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d", &n);
		int ans = (n / 7 + ex(1)) % MOD;
		for (int i = 2; i <= 6; ++ i)
		{
			(ans += sum(mpow(i, i), i, n / 7 + ex(i))) %= MOD;
		}
		puts(day[ans]);
	}
}

