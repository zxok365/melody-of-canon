#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 1000;
typedef long long LL;
struct Frac{
	LL up,down;
};
int T,n,a[MAXN],p[MAXN],A,B,C;
LL gcd(LL x,LL y){
	if (y==0) return x;
	else return gcd(y,x%y);
}
LL sqr(LL x){
	return x*x;
}
Frac simplify(Frac pp){	
	Frac ret;
	if (pp.up==0)
	{
		ret.up=0;
		ret.down=1;
		return ret;
	}
	LL tmp=gcd(pp.up,pp.down);
	ret.up=pp.up/tmp;
	ret.down=pp.down/tmp;
	return ret;
}
Frac operator + (Frac p1,Frac p2){
	LL tmp=gcd(p1.down,p2.down);
	LL nd=p1.down/tmp*p2.down;
	Frac ret;
	ret.down=nd;
	ret.up=p1.up*nd/p1.down+p2.up*nd/p2.down;
	ret=simplify(ret);
	return ret;
}
Frac calc(int n1,int n2){
	Frac p1,p2;
	p1.up=a[n1],p1.down=100;
	p2.up=a[n2],p2.down=100;
	Frac tmp;
	tmp.up=p1.up*p2.up;
	tmp.down=p1.down*p2.down;
	tmp=simplify(tmp);
	tmp.up=tmp.up*(sqr(n1-n2)*A+B*abs(n1-n2)+C);
	tmp=simplify(tmp);
	//cout<<"ok12"<<endl;
	return tmp;
}
void writeln(Frac pp){
	printf("%lld/%lld\n",pp.up,pp.down);
}
int main(){
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&A,&B,&C);
		for (int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		sort(p+1,p+n+1);
		if (n%2)
		{
			a[(n+1)/2]=p[n];
			int l=(n+1)/2-1;
			int r=(n+1)/2+1;
			for (int i=n-1;i>=1;i-=2)
			{
				a[l]=p[i];
				a[r]=p[i-1];
				l--;r++;
			}
		}
		else
		{
			int l=n/2,r=n/2+1;
			for (int i=n;i>=1;i-=2)
			{
				a[l]=p[i];
				a[r]=p[i-1];
				l--;r++;
			}
		}
		Frac ans;
//		cout<<"ok"<<endl;
		ans.up=0;ans.down=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				ans=ans+calc(i,j);
				//cout<<i<<" "<<j<<endl;
			}
		writeln(ans);
	}	
	return 0;
}
