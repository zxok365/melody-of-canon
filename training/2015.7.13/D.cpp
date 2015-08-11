#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
//#include<climits>

using namespace std;
const int maxn=2e5+10;
const int INF=199999999;

struct pii{
	int dis;
	double p;
	pii(){
		dis=INF;
		p=0;
	}
};

const double eps=1e-6;

bool operator <(const pii &a,const pii &b)
{
	if(a.dis!=b.dis)return a.dis<b.dis;
	return a.p>b.p+eps;
}


pii d[maxn];
int first[maxn],next[maxn],n,m,s,t,q[maxn],flag[maxn],rear=-1,v[maxn],fa[maxn],route[maxn];
double p[maxn];

void addedge(int from,int to, double pro)
{
	next[++rear]=first[from];
	first[from]=rear;
	v[rear]=to;
	p[rear]=pro;
}

void SPFA()
{
	memset(flag,0,sizeof(flag));
	d[s].dis=0;
	d[s].p=1;
//cout<<"###"<<endl;
	int front=0,rear=-1,i,e,x,to;
	pii tmp;
	q[++rear]=s;
	flag[s]=1;
	fa[s]=-1;
	while(front<=rear)
	{
		x=q[front++];
//cout<<d[x].p<<endl;
		flag[x]=0;
		for(e=first[x];e!=-1;e=next[e])
		{
			to=v[e];
			tmp.dis=d[x].dis+1;
			tmp.p=d[x].p*p[e];
//cout<<p[e]<<"EEEE"<<endl;
//cout<<tmp.p<<endl;
			if(tmp<d[to])
			{
				fa[to]=x;
				d[to]=tmp;
				if(!flag[to]&&to!=t){
					q[++rear]=to;
					flag[to]=1;
				}
			}			
		}		
	}
//cout<<"###"<<endl;
}


int main() {
	cin>>n>>m>>s>>t;
	int x,y,z;
	int i;
	memset(first,-1,sizeof(first));
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,1.0*(100-z)/100);
		addedge(y,x,1.0*(100-z)/100);
	}
	SPFA();
//cout<<"###"<<endl;
	rear=-1;
	int cur=t;
	while(cur!=-1)
	route[++rear]=cur,cur=fa[cur];
	
	printf("%d %.9f\n",d[t].dis+1,1-d[t].p);
	for(i=rear;i>0;--i)
	printf("%d ",route[i]);
	printf("%d\n",route[i]);
	

}
