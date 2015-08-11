#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n;
map<int, int> pp;
int fa[111111][20];
int id[111111],fa_id[111111];
int depth[111111];
int w[111111],s[111111],y[111111];
int tail;

void add_edge(int p, int q){
	y[++tail] = q;
	s[tail] = w[p];
	w[p] = tail;
}


void dfs(int p, int deep){
	depth[p] = deep;
	int now_deep = 2, now_num = 1, t = fa[p][0];
	while (now_deep <= deep){
		t = (fa[p][now_num] = fa[t][now_num - 1]); 
		now_num++;
		now_deep <<= 1;
	}
	for (int  j = w[p]; j != 0; j = s[j])
		dfs(y[j], deep + 1);
}

int lowbit(int x) {return x & (-x);}
int lca(int p, int q){
	int nnow = 2;
	if (depth[p] < depth[q])
	{
		swap(p,q);
		nnow = 1;
	}
	int delta = depth[p] - depth[q];
	int now = 0, now_deep = 1;
	while (delta > 0){
		if (now_deep == lowbit(delta)){
			p = fa[p][now];
			delta -= now_deep;
		}
		now = now + 1;
		now_deep <<= 1;
	}
	if (p == q) return nnow; else return 0;
}
int main(){
	scanf("%d", &n);
	pp.clear();
	pp[-1] = 1;
	tail = 0;
	for (int i = 1;i <= n; i++)
	{
		scanf("%d%d", &id[i], &fa_id[i]);
		pp[id[i]] = i + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		fa[i + 1][0] = pp[fa_id[i]];
		add_edge(fa[i + 1][0], i + 1);
	}
	dfs(1, 1);
	int q;
	scanf("%d", &q);
/*	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 0; j <= 2;j ++)
			cout << fa[i][j] << ' ' ;
		cout << endl;
	}*/
	for (int times = 1; times <= q; times++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int t = lca(pp[x], pp[y]);
		printf("%d\n", t);
	}
}
