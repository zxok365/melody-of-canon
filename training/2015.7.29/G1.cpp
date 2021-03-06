#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
double A[10005];
char buf[100005];
int cur;
bool getint(int &x)
{
	x = 0;
	while (buf[cur] == ' ') cur ++;
	if (buf[cur] == '\0') return false;
	while (buf[cur] >= '0' && buf[cur] <= '9')
	{
		x = x * 10 + buf[cur] - '0';
		cur ++;
	}
	return true;
}
int main()
{
	int z = 0;
	while (gets(buf) && strlen(buf) != 0)
	{
		++ z;
		//assert(z <= 5000);
		//printf("%s\n", buf);
		int p, d, i, j, k, l, n = 0;
		cur = 0;
		getint(d);
		if (d == 0) continue;
		getint(p);
		//printf("get d, p : %d %d\n", d, p);
		while (getint(j))
		{
			A[n ++] = j;
		}
		double a, b;
		int x1 = A[n - 4], x2 = A[n - 3], x3 = A[n - 2], x4 = A[n - 1];
		if (1LL * x1 * x3 - 1LL * x2 * x2 == 0)
		{
			b = 0;
			if (x2 == 0) a = 0; else a = 1.0 * x3 / x2;
		}
		else
		{
			b = (1.0 * x3 * x3 - 1.0 * x2 * x4) / (1.0 * x1 * x3 - 1.0 * x2 * x2);
			a = (1.0 * x2 * x3 - 1.0 * x1 * x4) / (1.0 * x2 * x2 - 1.0 * x1 * x3);
		}
		double MIN = A[0];
		double MAX = A[n - 1];
		for (i = n; i <= d; ++ i)
		{
			A[i] = a * A[i - 1] + b * A[i - 2];
			MAX = A[i];
			if (MAX > p) break;
		}
		for (i = 1; i <= d; ++ i)
		{
			if (A[i] > p) break;
		}
		if (p < MIN)
		{
			puts("The spider is going to fall!");
		}
		else if (p > MAX)
		{
			puts("The spider may fall!");
		}
		else
		{
			printf("%d\n", d - i + 1);
		}
	}
	return 0;
}
