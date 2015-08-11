#include<iostream>
#include<cstdio>
using namespace std;
long double c[1111][1111];
long double f[1111];
long double pone[1111];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	c[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = c[i - 1][0] / 2;
		for( int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) / 2;
	}
/*	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}*/
	for (int i = 0; i <= m; i++) f[i] = 1;
	pone[0] = 1;
	for (int i = m + 1; i <= n;i++)
	{
		for (int j = 0;j < m; j++)
		{
			long double t = f[i - j - 1] / i;
	//		cout << '!' << t << endl;
			f[i] += t;
		}
	}
	printf("%.8f\n", (double)f[n]);

}
