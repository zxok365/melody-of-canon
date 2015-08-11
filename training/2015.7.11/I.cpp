#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=100;
const int MO = 3737373;
map<int,int> hash;
map<int,bool> h;
int T,n,p,f[MAXN];
int dfs(int fm,int res,int now){
	if (res==0) return 0;
	int ret=0;
	for (int i=fm;i<=res;i++)
	{
		int nnow=(int)((LL)now*i%p);
		if (!h[nnow])
		{
			ret++;
			//cout<<nnow<<endl; 
			h[nnow]=1;
			hash[nnow]=res-i;
			ret+=dfs(i,res-i,nnow);
		}
		else if ((res-i)>hash[nnow]) ret+=dfs(i,res-i,nnow);
	}
	return ret;	
}
int main(){
	scanf("%d",&T);
	while (T--)
	{
		hash.clear();
		h.clear();
		scanf("%d%d",&n,&p);
		h[1] = 1;
		hash[1] = n - 1;
		printf("%d\n",dfs(2,n,1) + 1);
	}
	return 0;
}

/*

shijianchuo

SJC[]

now  * i ---->new_now ---- >hash --->h[hash(new_now)] = (res - i)*/

