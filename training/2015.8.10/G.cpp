#pragma comment(linker,"/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

struct hum{
	int fa, loy, abi, l, r;
	hum(){}
} a[81111];
bool operator <(const hum &p, const hum &q){
	if (p.abi != q.abi) return p.abi > q.abi;
	if (p.l < q.l) return true;
	return false;
}

int w[81111],s[81111],y[81111];
int tree[511111];
int ans[511111];
int sign[81111];
int Map[1111111];
int n, m, tail, now;



void add_edge(int p, int q){
	w[++tail] = s[p];
	s[p] = tail;
	y[tail] = q;
}
void dfs(int u){
	a[u].l = ++ now;
	for (int j = s[u]; j != 0; j = w[j]){
		dfs(y[j]);
	}
	a[u].r = now;
}

bool cmp(const int &p, const int &q){
	return a[p] < a[q];
}

int find(int x,int l, int r, int p, int q){
	if (l == p && q == r) return tree[x];
	int mid = (l + r) >> 1;
	if (mid >= q)
		return find(x * 2, l, mid, p, q);
	else
		if (mid < p)
			return find(x * 2 + 1, mid + 1, r, p, q);
		else
			return max(find(x * 2, l, mid, p, mid), find(x * 2 + 1, mid + 1, r, mid + 1, q));
}

void insert(int x, int l, int r, int pos, int ans){
	tree[x] = max(tree[x], ans);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (mid >= pos)
		insert(x * 2, l, mid, pos, ans);
	else
		insert(x * 2 + 1, mid + 1, r, pos, ans);
}


int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d", &n, &m);
		tail = now = 0;
		for (int i = 0; i <= n; i++) s[i] = 0;
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d%d", &a[i].fa, &a[i].loy, &a[i].abi);
			Map[a[i].loy] = i;
			a[i].l = a[i].r = 0;
			add_edge(a[i].fa, i);
		}
		dfs(0);
		for (int i = 1; i <= n * 8; i++) tree[i] = -1;
		for (int i = 1; i < n; i++) sign[i] = i;
		sort(sign + 1,sign + n, cmp);
		for (int i = 1; i < n; i++)
		{
			int p =	find(1, 1, now, a[sign[i]].l, a[sign[i]].r);
			if (p == -1)
				ans[Map[a[sign[i]].loy]] = -1;
			else
				ans[Map[a[sign[i]].loy]] = Map[p];
			insert(1, 1, now, a[sign[i]].l, a[sign[i]].loy);
		}
		for (int i = 1; i <= m;i++){
			int p;
			scanf("%d", &p);
			printf("%d\n", ans[p]);
		}
	}
}
