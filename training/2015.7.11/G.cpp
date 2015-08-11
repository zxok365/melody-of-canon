#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int MAXN=30000;
int T,n,k,a[MAXN];
int main(){
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);	
		if (k==1)
		{
			puts("0");
			continue;
		}
		sort(a+1,a+n+1);
		int ans=2000000000;
		for (int i=1;i+k-1<=n;i++)
			ans=min(ans,a[i+k-1]-a[i]);
		printf("%d\n",ans);
	}
	return 0;
}
