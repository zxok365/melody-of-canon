#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long f[2][1111];
int s[55][1111],val[55][1111];
int x;
int n, m;
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d%d", &m, &n, &x);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &s[i][j]);
		s[0][1] = x;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &val[i][j]);
		for (int i = 2; i <= n; i++) f[0][i] = -1;
		f[0][1] = 0;
		for (int i = 1; i <= m; i++)
		{
			int v = i & 1;
			int u = v ^ 1;
			for (int j = 1; j <= n; j++)
				f[v][j] = -1;
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					long long p = s[i][j] - s[i - 1][k];
					if (f[u][k] < 0) continue;
					if (p < 0) p = -p;
					if (f[v][j] < 0)
						f[v][j] = f[u][k] + p;
					else
						f[v][j] = min(f[v][j], f[u][k] + p);
				}
				f[v][j] += val[i][j];
			}
		}
		long long ans = -1;
		for (int i = 1; i <= n; i++)
		{
			if (f[m & 1][i] < 0) continue;
			if (ans < 0)
				ans = f[m & 1][i];
			else
				ans = min(ans,f[m & 1][i]);
		}
		cout << ans << endl;
	}
}
