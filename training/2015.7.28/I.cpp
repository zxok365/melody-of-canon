#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, p, z = 0;
	while (scanf("%d%d", &p, &n), !(n == 0 && p == 0))
	{
		int ans = 1;
		while (n)
		{
			ans *= (n % p + 1);
			n /= p;
		}
		printf("Case %d: %04d\n", ++ z, ans % 10000);
	}
}

