#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
struct mat
{
	double a[2][2];
	mat() {a[0][0] = a[1][1] = 1; a[0][1] = a[1][0] = 0;}
	mat(double q, double w, double e, double r)
	{
		a[0][0] = q;
		a[0][1] = w;
		a[1][0] = e;
		a[1][1] = r;
	}
};
mat operator * (mat a, mat &b)
{
	mat c = mat();
	for (int i = 0; i < 2; ++ i)
	{
		for (int j = 0; j < 2; ++ j)
		{
			for (int k = 0; k < 2; ++ k)
			{
				c.a[i][j] += a.a[i][k] * b.a[k][j];
			}
		}
	}
	return c;
}
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
double get_ind(double q, double w, double a, double b, int n)
{
	mat p = mat(0, b, 1, a);
	mat ans = mat(q, w, 0, 0);
	while (n)
	{
		if (n % 2 == 1) ans = ans * p;
		p = p * p;
		n >>= 1;
	}
	return ans.a[0][2];
}
int n;
double a, b;
double get(int x)
{
	if (x < n) return A[x];
	return get_ind(A[n - 2], A[n - 1], a, b, x - n + 1);
}
int main()
{
	int z = 0;
	while (gets(buf), strlen(buf) != 0)
	{
		++ z;
		assert(z <= 5000);
		//printf("%s\n", buf);
		int p, d, i, j, k;
		n = 0;
		cur = 0;
		getint(d);
		if (d == 0) continue;
		getint(p);
		//printf("get d, p : %d %d\n", d, p);
		while (getint(j))
		{
			A[n ++] = j;
		}
		if (p < A[0])
		{
			puts("The spider is going to fall!");
			continue;
		}
		int x1 = A[n - 4], x2 = A[n - 3], x3 = A[n - 2], x4 = A[n - 1];
		if (1LL * x1 * x3 - 1LL * x2 * x2 == 0)
		{
			b = 0;
			a = 1.0 * x3 / x2;
		}
		else
		{
			b = (1.0 * x3 * x3 - 1.0 * x2 * x4) / (1.0 * x1 * x3 - 1.0 * x2 * x2);
			a = (1.0 * x2 * x3 - 1.0 * x1 * x4) / (1.0 * x2 * x2 - 1.0 * x1 * x3);
		}
		if (p > get(d))
		{
			puts("The spider may fall!");
			continue;
		}
		int l = 0, r = d, ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			double cur = get(mid);
			if (cur <= p)
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		printf("%d\n", d - ans);
	}
	return 0;
}

