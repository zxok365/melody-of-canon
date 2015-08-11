#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define PII pair<int, int>
#define st first
#define ed second
using namespace std;
PII a[100005];
int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; ++ i)
	{
		scanf("%d%d", &j, &k);
		a[i] = PII(j, k);
	}
	sort(a + 1, a + 1 + n);
	double l = 0, r = 1000000, ans = 0;
	for (int cnt = 0; cnt < 500; ++ cnt)
	{
		double mid = (l + r) / 2, last = 0;
		bool flag = 1;
		for (i = 1; i <= n; ++ i)
		{
			double cur = max(last, 1.0 * a[i].st);
			if (cur + mid > a[i].ed)
			{
				flag = 0;
				break;
			}
			last = cur + mid;
		}
		if (flag)
		{
			l = mid;
			ans = mid;
		}
		else
		{
			r = mid;
		}
	}
	long long A, B;
	for (B = 1; B <= 1000000; ++ B)
	{
		if (abs(B * ans - floor(B * ans)) < 1e-8)
		{
			A = floor(B * ans);
			break;
		}
		if (abs(B * ans - ceil(B * ans)) < 1e-8)
		{
			A = ceil(B * ans);
			break;
		}
	}
	cout << A << '/' << B << endl;
}

