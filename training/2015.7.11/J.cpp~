#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MO = 1000000007;
const int MAXN = 1000;
struct Node{
	int to,nxt;
}nod[MAXN*2];
int tot,T,dfn[MAXN],used[MAXN],head[MAXN],tim,flg,go[MAXN],n,k,dep[MAXN],cir;
LL f[MAXN];
void clear(){
	tot=-1;
	for (int i=1;i<=n;i++) head[i]=-1,dfn[i]=0,dep[i]=0;
	f[1]=k;f[2]=k*(k-1)%MO;f[3]=f[2]*(k-2)%MO;
	for (int i=4;i<=n;i++)
	{
		f[i]=(k-2)*f[i-1]%MO+(k-1)*f[i-2]%MO;
		f[i]%=MO;
	}
}
void add(int x,int y){
	nod[++tot].nxt=head[x];
	head[x]=tot;
	nod[tot].to=y;
}
LL calc(int x,int y){
	LL ret=1;
	for (int i=1;i<=y;i++)
	{
		ret=ret*x;
		if (ret>=MO) ret%=MO;
	}
	return ret;
}
void dfs(int x){
	dfn[x]=++tim;
	for (int p=head[x];p>-1;p=nod[p].nxt)
	{
		if (!used[p])
		{
			used[p]=used[p^1]=1;
			if (!dfn[nod[p].to]) 
			{
				dep[nod[p].to]=dep[x]+1;
				dfs(nod[p].to);
			}
			else
			{
				if (dep[nod[p].to]<dep[x])
				cir=(dep[x]-dep[nod[p].to]+1);
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		clear();
		for (int i=1;i<=n;i++)
		{
			int t;
			scanf("%d",&t);
			t++;
			go[i]=t;
			add(i,t);add(t,i);
		}
		LL ans=1;
		for (int i=0;i<=tot;i++) used[i]=0;
		for (int i=1;i<=n;i++)
			if (!dfn[i])
			{
				cir=0;
				tim=0;
				dep[i]=1;
				dfs(i);
				LL ret=f[cir]*calc(k-1,tim-cir)%MO;
				ans=ans*ret%MO;	
			}
		printf("%lld\n",ans);
		
	}
	return 0;
}
