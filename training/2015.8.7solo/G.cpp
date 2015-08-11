#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define x first
#define y second
pair<int, int> p[111111];
int nxt[111111];
pair<int, int> ans[111111];
bool bo[111111];
int max_y, min_x;
int tot, n;
bool cmp(const pair<int ,int> &p, const pair<int, int> &q){
	if (p.x != q.x) return p.x < q.x;
	return p.y > q.y;
}
int main(){
	scanf("%d", &n);
	max_y = 1;
	min_x = n;
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		if (p[i].x < p[i].y) swap(p[i].x, p[i].y);
		max_y = max(max_y, p[i].x);
		min_x = min(min_x, p[i].y);
	}
	for (int i = 1;i < n; i++)
		nxt[i] = i + 1;
	nxt[n] = 1;
	tot = 0;
	sort(p + 1, p + t + 1, cmp);
	for (int i = 1; i <= t; i++)
	{
		int st = p[i].y;
		int ed = p[i].x;
		int now = nxt[st];
		while (nxt[now] != ed){
			bo[now] = true;
			ans[++tot].x = st;
			ans[tot].y = nxt[now];
			now = nxt[now];
		}
		bo[now] = true;
		nxt[st] = ed;
	}
	for (int i = 1; i <= n;i++)
	if (!bo[i]){
		int st = i;
		int now = nxt[st];
		if (nxt[now] == st)continue;
		while (nxt[nxt[now]] != st){
			bo[now] = true;
			ans[++tot].x = st;
			ans[tot].y = nxt[now];
			now = nxt[now];
		}
		break;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d %d\n", ans[i].x, ans[i].y);
}

