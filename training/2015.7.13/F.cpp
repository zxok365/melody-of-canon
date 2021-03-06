#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include<cmath>
#define LL long long
using namespace std;
const int maxn=110;
const int INF=1999999999;


long double f[maxn];
long double c[maxn][maxn],e3[maxn],e2[maxn];

void init()
{
	memset(c,0,sizeof(c));
	int i,j;
	c[1][0]=1;
	c[1][1]=1;
	for(i=1;i<maxn;++i)
	c[i][0]=1;
	
	for(i=2;i<maxn;++i)
	for(j=1;j<maxn;++j)
	c[i][j]=c[i-1][j-1]+c[i-1][j];
	
	e3[0]=1.0;
	e2[0]=1.0;
	for(i=1;i<maxn;++i)
	e3[i]=e3[i-1]*3,e2[i]=e2[i-1]*2;
	//cout<<e3[3]<<endl;
}


int main() {
	init();
	f[1]=0;
	int i,n,j;
	cin>>n;
	for(i=2;i<=n;++i)
	{
		long double up=e3[i-1];
		for(j=1;j<=i-1;++j)
		up+=c[i][j]*f[j];
		f[i]=up/(e2[i]-2);	
		//cout<<f[i]<<endl;
	}
	printf("%.10f\n",(double)f[n]);
}
