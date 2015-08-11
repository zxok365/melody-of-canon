#include<iostream>
#include<cstdio>
using namespace std;
int f[111][111];
int up[111][111],down[111][111],rt[111][111],lt[111][111],nnow[111][111];
int n, m, c, q;
int ans[1111];
bool bo;
int d;
int min(int a, int b, int c, int d){
	return min(min(a, b), min(c,d));
}
void make(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (f[i][j] != f[i - 1][j])
				up[i][j] = 1;
			else
				up[i][j] = up[i - 1][j] + 1;
			if (f[i][j] != f[i][j - 1])
				lt[i][j] = 1;
			else
				lt[i][j] = lt[i][j - 1] + 1;
		}
	for (int i = n; i >= 1;i --)
		for (int j = m; j >= 1;j--)
		{
			
			if (f[i][j] != f[i + 1][j])
				down[i][j] = 1;
			else
				down[i][j] = down[i + 1][j] + 1;
			if (f[i][j] != f[i][j + 1])
				rt[i][j] = 1;
			else
				rt[i][j] = rt[i][j + 1] + 1;
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			nnow[i][j] = min(up[i][j], down[i][j], lt[i][j], rt[i][j]) - 1;
			ans[f[i][j]] = ans[f[i][j]] + nnow[i][j];
		}
}
void make2(int p, int q, int c, int d)
{
	for(int i = 1; i <= n; i++)
		up[i][q] = (f[i - 1][q] == f[i][q] ? up[i - 1][q] + 1 : 1);
	for (int i = n; i >= 1; i--)
		down[i][q] = (f[i + 1][q] == f[i][q] ? down[i + 1][q] + 1 : 1);
	for (int j = 1; j <= m; j++)
		lt[p][j] = (f[p][j - 1] == f[p][j] ? lt[p][j - 1] + 1 : 1);
	for (int j = m; j >= 1; j--)
		rt[p][j] = (f[p][j + 1] == f[p][j] ? rt[p][j + 1] + 1 : 1);
	for (int i = 1; i <= n; i++)
	if (i == p) continue; else
	{
		int t = nnow[i][q];
		nnow[i][q] = min(up[i][q], down[i][q], lt[i][q], rt[i][q]) - 1;
		ans[f[i][q]] += nnow[i][q] - t;
	}
	for (int j = 1; j <= m;j ++)
	if (j == q) continue; else
	{
		int t = nnow[p][j];
		nnow[p][j] = min(up[p][j], down[p][j], lt[p][j], rt[p][j]) - 1;
		ans[f[p][j]] += nnow[p][j] - t;
	}
	int t = nnow[p][q];
	nnow[p][q] = min(up[p][q], down[p][q], lt[p][q], rt[p][q]) - 1;
	ans[d] -= t;
	ans[c] += nnow[p][q];
}
int main(){
	scanf("%d%d%d%d", &n, &m, &c, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &f[i][j]);
	make();
	for (int i = 1; i <= q; i++){
		char ch;
		scanf(" %c", &ch);
		if (ch =='Q'){
			int t;
			scanf("%d", &t);
			printf("%d\n",ans[t]);
		}
		else
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b ,&c);
			d = f[a][b];
			f[a][b] = c;
			make2(a, b, c, d);
		}
	}
}
