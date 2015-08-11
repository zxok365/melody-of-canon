#include <cstdio>
#include <iostream>

using namespace std;

int pre[200005], other[200005], last[200005], stack[200005], que[200005], dfn[200005], low[200005];
bool ins[200005], vis[200005], ok[200005];
int tot, n, m, l, sign;
long long ans;

void add(int u, int v) {
	l++;
	pre[l]=last[u];
	last[u]=l;
	other[l]=v;
}

void tarjan(int x, int fa) {
	sign++;
	dfn[x]=sign;
	low[x]=sign;
	stack[++tot]=x;
	ins[x]=true;
	int p=last[x];
	while (p!=0) {
		int q=other[p];
		if (q!=fa) {
			if (dfn[q]==0) {
				tarjan(q, x);
				low[x]=min(low[x], low[q]);
			} else low[x]=min(low[x], low[q]);
		}
		p=pre[p];
	}
	if (low[x]==dfn[x]) {
		if (stack[tot]==x) ok[x]=true;
		while (stack[tot]!=x) {
			ins[stack[tot]]=false;
			tot--;
		}
		ins[stack[tot]]=false;
		tot--;
	}
}

void BFS(int x) {
	int head=0;
	int tail=1;
	que[1]=x;
	vis[x]=true;
	while (head!=tail) {
		int cur=que[++head];
		int p=last[cur];
		while (p!=0) {
			int q=other[p];
			if ((ok[q])&&(!vis[q])) {
				que[++tail]=q;
				vis[q]=true;
			}
			p=pre[p];
		}
	}
	ans+=((long long)tail*(tail-1))/2;
}

int main() {
	int test;
	scanf("%d", &test);
	int te=0;
	while (test--) {
		scanf("%d%d", &n, &m);
		l=0;
		tot=0;
		sign=0;
		ans=0;
		for (int i=1; i<=n; i++) {
			ok[i]=false;
			last[i]=0;
			dfn[i]=0;
			low[i]=0;
			vis[i]=0;
		}
		int u, v;
		for (int i=1; i<=m; i++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		for (int i=1; i<=n; i++) if (dfn[i]==0) tarjan(i, 0);
		for (int i=1; i<=n; i++) if ((ok[i])&&(!vis[i])) {
			BFS(i);
		}
		te++;
		printf("Case #%d: ", te);
		cout << ans << endl;
	}
	return 0;
}
