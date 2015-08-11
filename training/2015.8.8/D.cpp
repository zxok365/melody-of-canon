#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool hang[4][20], lie[4][20];
long long A[20];
void dfs(int x, int y, int M)
{
	if (y == 4) {x ++; y = 0;}
	if (x == 4)
	{
		A[M] ++;
		return;
	}
	for (int i = 0; i < M; ++ i)
	{
		if (!hang[x][i] && !lie[y][i])
		{
			hang[x][i] = 1;
			lie[y][i] = 1;
			dfs(x, y + 1, M);
			hang[x][i] = 0;
			lie[y][i] = 0;
		}
	}
	hang[x][M] = 1;
	lie[y][M] = 1;
	dfs(x, y + 1, M + 1);
	hang[x][M] = 0;
	lie[y][M] = 0;
}
const int MM = 1e8;
struct big
{
	int a[5000], len;
	big() {memset(a, 0, sizeof(a)); len = 0;}
	big(long long x)
	{
		memset(a, 0, sizeof(a));
		len = 0;
		while (x)
		{
			a[len ++] = x % MM;
			x /= MM;
		}
	}
	void println()
	{
		if (len == 0)
		{
			puts("0");
			return;
		}
		printf("%d", a[len - 1]);
		for (int i = len - 2; i >= 0; -- i) printf("%08d", a[i]);
		puts("");
	}
};
big operator + (const big &a, const big &b)
{
	big c = big();
	c.len = max(a.len, b.len);
	long long tmp = 0;
	for (int i = 0; i < c.len; ++ i)
	{
		tmp /= MM;
		tmp += a.a[i] + b.a[i];
		c.a[i] = tmp % MM;
	}
	tmp /= MM;
	if (tmp) c.a[c.len ++] = tmp;
	return c;
}
big operator * (const big &a, const big &b)
{
	big c = big();
	c.len = a.len + b.len - 1;
	for (int i = 0; i < a.len; ++ i)
	{
		for (int j = 0; j < b.len; ++ j)
		{
			long long tmp = 1LL * a.a[i] * b.a[j] + c.a[i + j];
			c.a[i + j] = tmp % MM;
			c.a[i + j + 1] += tmp / MM;
		}
	}
	if (c.a[c.len]) c.len ++;
	return c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	dfs(0, 0, 0);
	//for (int i = 1; i <= 16; ++ i) printf("A[%d] = %lld\n", i, A[i]);
	/*big(1234567890123LL).println();
	(big(111111111) * big(111111111)).println();
	(big(123456789LL) + big(987654321LL)).println();*/
	int T;
	cin >> T;
	while (T --)
	{
		long long n;
		cin >> n;
		big ans = big();
		for (int i = 4; i <= min(n, 16LL); ++ i)
		{
			big tmp = big(A[i]);
			for (int j = 1; j <= i; ++ j)
			{
				tmp = tmp * big(n - j + 1);
				//printf("*** ");
				//tmp.println();
			}
			//printf("--- %d : ", i);
			//tmp.println();
			ans = ans + tmp;
		}
		ans = ans * ans;
		ans = ans * ans;
		ans.println();
	}
}

