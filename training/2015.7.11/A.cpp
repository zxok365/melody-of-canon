#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 100000;
typedef long long LL;
struct Point{
	int x,y;
}po[MAXN];
LL sum[MAXN];
int n,Q;
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
LL det(int n1,int n2){
	int x1=po[n1].x,x2=po[n2].x,y1=po[n1].y,y2=po[n2].y;
	LL ret=(LL)x1*y2-(LL)x2*y1;
	return ret;
}
int main(){
	bool now = false;
	while (scanf("%d%d",&n,&Q) == 2){
		if (n == 0 && Q == 0) return 0;
		if (now) printf("\n");
		now = true;
		for (int i=1;i<=n;i++)
			scanf("%d%d",&po[i].x,&po[i].y);
		sum[1]=0;
		for (int i=2;i<=n;i++)
			sum[i]=sum[i-1]+det(i-1,i);
		LL tot= fabs(sum[n] + det(n,1));
		for (int i=1;i<=Q;i++)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				p++;q++;
				if (p>q) swap(q,p);
				LL ans=fabs((sum[q]-sum[p]) + det(q , p));
				ans=min(ans,tot-ans);
				LL tans = ans / 2;	
				if (ans % 2 == 0) printf("%lld.0\n", tans); else printf("%lld.5\n", tans);
			}
	}
	return 0;
}
