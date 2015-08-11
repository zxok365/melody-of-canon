#include<iostream>
#include<cstdio>
using namespace std;
int Mo = 1e8 + 7;
int a[11111],c[11111],f[11111];
int n, m;
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n;i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) f[i] = 0;
		f[0] = 1;
		for (int i = 1; i <= n;i++)
			for (int j = a[i]; j <= m; j++)
				f[j] += f[j - a[i]], f[j] %= Mo;
		printf("Case %d: %d\n",time, f[m]);
	}
}
