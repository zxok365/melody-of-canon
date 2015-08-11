#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
int n, m;
int p[111111],q[111111],r[111111];
double pi = acos(-1.);
#define x first
#define y second
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &p[i], &q[i], &r[i]);
		}
		double ans = 0;
		for (int i = -89; i <= 270; i++)
		{
			int pp = 0;
			for (int j = 1; j <= n; j++)
			if (q[j] < i && r[j] >= i)
				pp = max(pp,p[j]);
			ans = ans + pi * pp * pp / 360;
		}
		printf("%.4f\n", ans);
	}
}
