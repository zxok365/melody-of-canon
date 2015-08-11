#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define left asda
#define right asasdas

int n, q, tot1, tot2;
int x[50005], y[50005];
int w, h;
int left[500005], right[500005];
set<pair<int, int> > sum[500005];
vector<int> tmp;
int visit[50005];
int round = 0;

void Init(int x, int l, int r) {
	left[x]=l;
	right[x]=r;
	sum[x].clear();
	if (l==r) return;
	int mid=l+(r-l)/2;
	Init(x*2, l, mid);
	Init(x*2+1, mid+1, r);
}

void del(int x, int l, int r, int key1, int key2, int info) {
	sum[x].erase(make_pair(key2, info));
	if (l==r) return;
	int mid=l+(r-l)/2;
	if (key1<=mid) del(x*2, l, mid, key1, key2, info);
		else del(x*2+1, mid+1, r, key1, key2, info);
}

void insert(int x, int l, int r, int key1, int key2, int info) {
	sum[x].insert(make_pair(key2, info));
	if (l==r) return;
	int mid=l+(r-l)/2;
	if (key1<=mid) insert(x*2, l, mid, key1, key2, info);
		else insert(x*2+1, mid+1, r, key1, key2, info);
}

void move(int xx, int l1, int r1, int l2, int r2) {	
	if (l1==left[xx]&&r1==right[xx]) {
		set<pair<int, int> > :: iterator it1, it2;
		it1=sum[xx].lower_bound(make_pair(l2, 0));
		it2=sum[xx].upper_bound(make_pair(r2, n+10));
		if (it1==it2) return;
		int last=tmp.size();
		for (; it1!=it2; it1++) {
			int cur = (*it1).second;
			if (visit[cur] != round) tmp.push_back(cur), visit[cur] = round;
		}
		return;
	}
	int mid=left[xx]+(right[xx]-left[xx])/2;
	if (r1<=mid) move(xx*2, l1, r1, l2, r2);
		else if (l1>mid) move(xx*2+1, l1, r1, l2, r2);
			else {
				move(xx*2, l1, mid, l2, r2);
				move(xx*2+1, mid+1, r1, l2, r2);
			}
}
int main() {
	int test;
	scanf("%d", &test);
	int tot=0;
	while (test--) {
		tot++;
		scanf("%d%d%d%d", &n, &q, &w, &h);
		Init(1, -h, w);
		for (int i=1; i<=n; i++) {
			scanf("%d%d", &x[i], &y[i]);
			insert(1, -h, w, x[i]-y[i], x[i]+y[i], i);
		}
		for (int i=1; i<=q; i++) {
			int xk, yk, ek, a, b, c, d, e, f;
			scanf("%d%d%d%d%d%d%d%d%d", &xk, &yk, &ek, &a, &b, &c, &d, &e, &f);
			int x1=xk;
			int y1=yk-ek;
			int x2=xk;
			int y2=yk+ek;
			tmp.clear();
			round ++;
			move(1, max(-h, x2-y2), min(x1-y1, w), x1+y1, x2+y2);
			for (int i=0; i<tmp.size(); i++) {
				int cur=tmp[i];
				del(1, -h, w, x[cur]-y[cur], x[cur]+y[cur], cur);
				visit[cur] = round;
				int newx=(((long long)x[cur]*a)+((long long)y[cur]*b)+((long long)cur*c)) % w;
				int newy=(((long long)x[cur]*d)+((long long)y[cur]*e)+((long long)cur*f)) % h;
				x[cur]=newx;
				y[cur]=newy;
				insert(1, -h, w, newx-newy, newx+newy, cur);
			}
		}
		printf("Case #%d:\n", tot);
		for (int i=1; i<=n; i++) printf("%d %d\n", x[i], y[i]);
	}
	return 0;
}
