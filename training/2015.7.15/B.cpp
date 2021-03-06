#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct Edge{
	int a,b;
	long long v00,v01,v10,v11;
}e[1200];
const int N  = 150;
const long long MOD = 1e9 + 7;
int next[N * 2], last[N], to[N * 2], G;
int col[N],num1[N],num0[N];
long long num[N][2],ans;
int bit[N],cnt[2],n,m;
void addedge(int x,int y)
{
	next[++G] = last[x]; last[x] = G; to[G] = y;
}
void DFS(int x)
{
	for(int i = last[x]; i; i = next[i])
	{
		if(col[to[i]] != -1) continue;
		col[to[i]] = col[x] == 1 ? 0 : 1;
		DFS(to[i]);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%lld%lld%lld%lld",&e[i].a, &e[i].b, &e[i].v00, &e[i].v01, &e[i].v10, &e[i].v11);
		addedge(e[i].a, e[i].b);
		addedge(e[i].b, e[i].a);
	}
	for(int i = 1; i <= n; i++) col[i] = -1;
	for(int i = 1; i <= n; i++)
		if(col[i] == -1)
			col[i] = 0,DFS(i);
		
	
	for(int i = 1; i <= n; i++)
		if(col[i] == 0)
			num0[++cnt[0]] = i;
		else
			num1[++cnt[1]] = i;
			
	if(cnt[0] > cnt[1])
	{
		for(int i = 1; i <= cnt[0]; i++)
			swap(num0[i],num1[i]);
		swap(cnt[0],cnt[1]);
	}
	for(int i = 1; i <= cnt[0]; i++) col[num0[i]] = 0;
	for(int i = 1; i <= cnt[1]; i++) col[num1[i]] = 1;
	
	//for(int i = 1; i <= n; i++)
	//	printf("%d ",col[i]);
	//puts("");
	int Bit = 1;
	for(int i = 1; i <= cnt[0]; i++)
		bit[num0[i]] = Bit, Bit *= 2;
		
	for(int i = 0; i < Bit; i++)
	{
		for(int j = 1; j <= n; j++) num[j][0] = num[j][1] = 1;
		
		for(int j = 1; j <= m; j++)
		{
			if(col[e[j].a] == 0)
			{
				if(bit[e[j].a] & i)
					num[e[j].b][0] = (num[e[j].b][0] * e[j].v10) % MOD,
					num[e[j].b][1] = (num[e[j].b][1] * e[j].v11) % MOD;
				else
					num[e[j].b][0] = (num[e[j].b][0] * e[j].v00) % MOD,
					num[e[j].b][1] = (num[e[j].b][1] * e[j].v01) % MOD;
			}
			else
			{		
				if(bit[e[j].b] & i)
					num[e[j].a][0] = (num[e[j].a][0] * e[j].v01) % MOD,
					num[e[j].a][1] = (num[e[j].a][1] * e[j].v11) % MOD;
				else
					num[e[j].a][0] = (num[e[j].a][0] * e[j].v00) % MOD,
					num[e[j].a][1] = (num[e[j].a][1] * e[j].v10) % MOD;		
			}
		}
		
		long long tem = 1;
		for(int j = 1; j <= cnt[1]; j++)
		{
			tem = (tem * (num[num1[j]][1] + num[num1[j]][0])) % MOD;
		//	cout << 
		}
		ans = (ans + tem) % MOD; 
	}
	
	cout << ans << endl;

}
