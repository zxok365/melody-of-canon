#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include<cmath>
#define LL long long
using namespace std;
const int maxn=1e5+10;
const int INF=1999999999;

int p[maxn]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,INF};


int rear;

LL ans=0,A,B,k;

void dfs(int last,int num,LL pro)
{
	LL tmp=B/pro-A/pro;
	if(num%2)ans-=tmp;
	else ans+=tmp;
	for(int i=last+1;pro*p[i]<=B&&p[i]<=k;++i)
	dfs(i,num+1,pro*p[i]);
}

bool ok(int n)
{
	int nn=sqrt(n)+1;
	for(int i=2;i<=nn;++i)
	if(n%i==0)return 0;
	return 1;
}

int main() {
	int i;
	cin >> A >> B >> k;
	B=A+B;
	++k;
	for(i=A+1;i<=min(B,k);++i)
	if(ok(i))++ans;
	
	//for(rear=0;p[rear]<=k;++rear);
	//--rear;
	dfs(0,0,1);
	cout << ans << endl;
	
}
