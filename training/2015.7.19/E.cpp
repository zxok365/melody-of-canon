#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;

queue<int> q;

int n;
int deg[maxn],to[maxn];
struct rec{
	int x,y;
	int last;
	rec(){}
	rec(int a,int b):x(a),y(b){}
}peo[maxn];

inline void topsort(){
	peo[1].x = INF;
	while(!q.empty()) q.pop();
	for (int i = 1;i <= n;i++)
		if (!deg[i]){
			peo[i].y = INF;
			peo[i].last = min(peo[i].x,peo[i].y);
			q.push(i);
		}
	while(!q.empty()){
		int u = q.front(); q.pop();
		int v = to[u];
		if (v == -1){
			peo[u].last = min(peo[u].x,peo[u].y);
			break;
		}
		if (peo[v].y == -1){
			peo[v].y = peo[u].last;
		}else peo[v].y += peo[u].last;
		deg[v]--;
		if (!deg[v]){
			if (peo[v].y == -1) peo[v].y = INF;
			peo[v].last = min(peo[v].x,peo[v].y);
	//		cerr<<v<<" "<<peo[v].last<<endl;
			q.push(v);
		}
	}
	/*
	for (int i = 1;i <= n;i++) 
		cerr<<i<<" "<<peo[i].last<<" "<<peo[i].x<<" "<<peo[i].y<<endl;
	*/
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) deg[i] = 0;
	for (int i = 1;i <= n;i++) to[i] = -1;
	for (int i = 1;i <  n;i++){
		int x,val; scanf("%d%d",&x,&val);
		deg[x]++;
		to[i + 1] = x;
		peo[i + 1] = rec(val,-1);
	}
	topsort();
	printf("%d.00\n",peo[1].last);
	return 0;
}
