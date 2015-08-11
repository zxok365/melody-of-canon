#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <bitset>
#include <sstream>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define X first
#define Y second
#define INF 1000000000


const int MN = 45;
const LL BASE = 1e7;

int m, n, sum;
struct BIG
{
	LL a[105];
	BIG(int x = 0)
	{
		for(int i = 0; i <= 104; ++i) a[i] = 0;
		a[0] = 1;
		a[1] = x;
	}
	void prin()
	{
		bool flag = 0;
		for(int i = 104; i >= 1; --i)
		{
			if(flag) printf("%07lld", a[i]);
			if(!flag && a[i] != 0)
			{
				flag = 1;
				printf("%lld", a[i]);
			}
		}
		
		if(!flag) printf("0");
	
		printf("\n");
	}
};
/*
LL c[MN][MN], ycl[MN][MN], f[MN][MN], ans;
*/

BIG c[MN][MN];
BIG ycl[MN][MN];
BIG f[MN][MN];
BIG ans;

BIG operator + (const BIG &x, const BIG &y)
{
	int len = max(x.a[0], y.a[0]);
	BIG tmp;

	for(int i = 1; i <= len + 1; ++i)
	{
		tmp.a[i] += x.a[i] + y.a[i];
		tmp.a[i + 1] += tmp.a[i] / BASE;
		tmp.a[i] %= BASE;
	}
	tmp.a[0] = len + 1;
	while (tmp.a[0] > 1 && tmp.a[tmp.a[0]] == 0) --tmp.a[0];
	return tmp;
}

BIG operator * (const BIG &x, const BIG &y)
{
	BIG res;
	LL p = min(x.a[0] + y.a[0] +2, 100ll);
	for(int i = 1; i <= x.a[0]; ++i)
	{
		for(int j = 1; j <= y.a[0]; ++j)
			res.a[j + i - 1] += y.a[j] * x.a[i];
	}			
		
		for(int j = 1; j <= p; ++j)
		{
			res.a[j + 1] += res.a[j] / BASE;
			res.a[j] %= BASE;
		}
	while (p > 1 && res.a[p] == 0) --p;
	res.a[0] = p;
	/*
	cout << "========" << endl;
	x.prin(); y.prin(); res.prin();
	cout << "========" << endl;
	*/
	return res;
}


int main()
{
	
	
	
	scanf("%d %d %d", &m, &n, &sum);
	
	c[0][0] = BIG(1);
	
	for(int i = 1; i <= m; ++i)
	{
		c[i][0] = BIG(1);
		c[i][i] = BIG(1);
		
		
		for(int j = 1; j < i; ++j)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}	
		
	}
	
	/*
	for(int i = 1; i <= m; ++i)
	for(int j = 0; j <= i; ++j)
		cout << i << " " << j << " : " , c[i][j].prin();
	*/
	
	for(int j = 0; j <= m; ++j)
		for(int k = 0; k <= m; ++k)
		{
			int p = min(sum, k); p = min(p, m -j);
			for(int l = max(0, k - j); l <= p; ++l)
			{
				//cout << "=======" << endl;
				//c[k][l].prin(); c[m - k][j - l].prin(); ycl[j][k].prin();
				ycl[j][k] = ycl[j][k] + (c[k][l] * c[m - k][m - j - l]);
				//ycl[j][k].prin(); cout << "======" << endl;
			}
		}
		
	//cout << ycl[1][0] << endl;
		
	f[0][0] = BIG(1); 
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
		{
			for(int k = 0; k <= m; ++k)
			{
				//cout << "=======" << endl;
				//f[i][j].prin(); f[i - 1][k].prin(); ycl[j][k].prin();
				f[i][j] = (f[i - 1][k] * ycl[j][k]) + f[i][j];
				//f[i][j].prin();
				//cout << "=======" << endl;
			}
			if(i == n) ans = ans + f[i][j];
		}
	
	//cout << f[1][0] << " " << f[1][1] << " " << f[1][2] << endl;
	
	//cout << ans << endl;
	ans.prin();
	
	/*
	BIG aaa = BIG(10080), bbb = BIG(10), ccc = 61290;
	BIG now = aaa * bbb + ccc;
	now.prin();
	*/
	return 0;
}
