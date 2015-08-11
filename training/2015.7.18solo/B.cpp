#include<iostream>
#include<cstdio>
using namespace std;
int a[1111];
int f[222][222];
int du[222];
int ans[222];
int now;
int n, m;
bool bo;
void done(int u){
	a[u] = ++now;
	for (int v = 1; v <= n; v++)
	if (f[u][v] == 1){
		du[v]--;
	}
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d", &n , &m);
		for (int i = 1; i <= n; i++) a[i] = 0, du[i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = 0;
		for (int i = 1; i <= m; i++)
		{
			int p, q;
			scanf("%d%d", &p, &q);
			if (f[p][q] == 0) f[p][q] = 1,du[q]++;
		}
		now = 0;
		bool nnow;
		for (int t = 1; t <= n; t++)
		{
			nnow = false;
			for (int i = 1; i <= n; i++)
				if (a[i] == 0 && du[i] == 0)
				{
					done(i);
					nnow = true;
					break;
				}
			if (!nnow) break;
		}
		if (nnow == false)
			printf("-1\n");
		else
		{
			for (int k = 1; k <= n; k++)
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
						if (f[i][k] == 1 && f[k][j] == 1) f[i][j] = 1;
		/*	for (int i =1 ; i <= n; i++)
			{
				for (int j = 1; j <= n;j++)
					cout << f[i][j] <<' ';
				cout << endl;
			}*/
	/*		for (int i = 1; i <= n; i++)
			{
				bool bo = false;
				for (int j = 1; j < i; j++)
					if (f[i][ans[j]] == 1)
					{
						for (int k = i; k > j; k--) ans[k] = ans[k - 1];
						ans[j] = i;
						bo = true;
						break;
					}
				if (!bo) ans[i] = i;
			}*/
			for (int i = 1; i <= n; i++) ans[i] = 0;
			for (int i = 1; i <= n; i++)
			{
				int now_ans = 1;
				for (int j = i + 1; j <= n; j++)
					if (f[j][i] == 1) now_ans++;
				int now = 0, p = 0;
				for (int j = 1; j <= n; j++)
					if (ans[j] == 0)
					{
						now++;
						if (now == now_ans)
						{
							p = j;
							break;
						}
					}
				ans[p] = i;
			}
			for (int i = 1; i <= n; i++) a[ans[i]] = i;
			for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}
