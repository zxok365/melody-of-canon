#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define x first
#define y second
const int maxn = 222222;
int w[maxn],s[maxn << 1],y[maxn << 1], z[maxn << 1];
int dl[maxn << 1], fa[maxn], point_to[maxn];
bool bo[maxn];
int tail, head;
int tot;
int now_ans;
int sign[maxn],now_sign[maxn];
int ans[maxn];
int m, n;
bool boo[maxn];
int du[maxn];
void add_edge(int p, int q, int r){
	s[++tail] = w[p];
	y[tail] = q; 
	z[tail] = r;
	w[p] = tail;
}        

void add_ans(int p){
	ans[++now_ans] = p;
}

void outp(){
	sort(ans + 1, ans + now_ans + 1);
	printf("%d\n", now_ans);
	for (int i = 1; i < now_ans; i++) printf("%d ", ans[i]);
	if (now_ans >= 1) printf("%d\n", ans[now_ans]);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1;i++)
	{
		int p, q;
		scanf("%d %d", &p ,&q);
		char ch;
		scanf(" %c", &ch);
		du[p]++;
		du[q]++;
		if (ch == 'p')
		{
			add_edge(p, q, 1);
			add_edge(q, p, 1);
			for (int j = 1; j <= 8; j++) ch = getchar();
		} else
		{
			add_edge(p, q, -1);
			add_edge(q, p, -1);
			for (int j = 1; j <= 15; j++) ch = getchar();
		}
	}
	tail = 0;
	for (int i = 2; i <= n; i++) if (du[i] == 1) dl[++tail] = i;
	for (int i = 1; i <= n; i++) bo[i] = false,sign[i] = 0;
	head = 1;
	while (head <= tail){
		int u = dl[head];
		bo[u] = true;
		for (int i = w[u]; i != 0; i = s[i]){
			int v = y[i];
			if (bo[v]) continue;
			fa[u] = v;
			du[v]--;
			point_to[u] = (i + 1) / 2;
			sign[u] = sign[u] + z[i];
			sign[v] = min(sign[v], sign[u]);
			if (du[v] == 1 && v != 1) dl[++tail] = v;
		}
	//	cout << u << ' ' << fa[u] << ' ' << sign[u] << endl;
		head++;
	}
//	cout << "***************" << endl;
	m = tail;
	now_ans = 0;
	for (int i = m;i >= 1; i--){
		int u = dl[i];
		int edge = point_to[u];
		boo[u] = boo[fa[u]];
		now_sign[u] = now_sign[fa[u]];
	//	cout << u << ' ' << edge << ' ' << now_sign[u] << ' ' << sign[u] <<  endl;
	//	if (boo[u]) continue;
	//	cout << z[edge] << endl; 
		if (z[2 * edge] == 1)
		{
			now_sign[u]++;
			continue;
		}
		else
		if (now_sign[u] + sign[u] < 0)
		{
	//		cout << edge << endl;
			add_ans(edge);
			now_sign[u]++;
			sign[u]++;
		}
	}
	outp();
}

