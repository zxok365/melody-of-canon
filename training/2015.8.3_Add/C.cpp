#include<iostream>
#include<cstdio>
using namespace std;
int Mo = 1e8 + 7;
int a[111111],c[111111];
bool f[111111];
int n, m;
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n;i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n;i++)
			scanf("%d",&c[i]);
		for (int i = 1; i <= m; i++) f[i] = false;
		f[0] = true;
		for (int i = 1; i <= n;i++)
		{
			int t = 0;
			for (int k = 1; k <= c[i]; k <<= 1)
			{
				if (t + k > c[i]) break;
				t += k;
				for (int j = m; j >=  a[i] * k;j--)
					if (j - a[i] * k >= 0) f[j] |= f[j - a[i] * k];
			}
			int k = c[i] - t;
			if (k > 0)
			for (int j = m; j >= a[i] * k;j--)
				if (j - a[i] * k >= 0) f[j] |= f[j - a[i] * k];
		}
		int ans = 0;
		for (int i = 1; i <= m; i++)
			 if (f[i]) ans++;	
		printf("Case %d: %d\n",time, ans);
	}
}

