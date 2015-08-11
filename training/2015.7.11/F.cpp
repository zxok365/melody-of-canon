#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,a1,d;
int main(){
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&a1,&d);
		int ans=a1*n+(n-1)*n/2*d;
		printf("%d\n",ans);
	}
}
