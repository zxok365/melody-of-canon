#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;
const int maxn=1e5+10;

int a[maxn],n,cnt,t,cur,maxx=0;
int main() {
	cin>>n;
	int i;
	for(i=1;i<=n;++i)
	scanf("%d",&a[i]);
	t=1;
	cnt=0;
	cur=1;
	for(i=2;i<=n;++i)
	{
		++cnt;
		if(a[i]<a[cur]){
			cur=i;
			cnt=1;
		}
		if(cnt>maxx){
			maxx=cnt;
			t=cur;
		}
	}
	if(cnt>maxx)t=cur;
	cout<<t<<'\n';
}
