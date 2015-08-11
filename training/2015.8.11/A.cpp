#include <cstdio>
#include <iostream>

using namespace std;

struct seg { 
	int l, r;
	long long key[2][2];
} tree[400005];

int n, m;
int a[100005];

void update(int x) {
	for (int i = 0; i <= 1; i ++)
		for (int j = 0; j <= 1; j ++) 
			tree[x].key[i][j] = -(1e15);
	for (int i = 0; i <= 1; i ++)
		for (int j = 0; j <= 1; j ++) {
			tree[x].key[i][j] = max(tree[x].key[i][j], tree[x * 2].key[i][j]);
			tree[x].key[i][j] = max(tree[x].key[i][j], tree[x * 2 + 1].key[i][j]);
			tree[x].key[i][j] = max(tree[x].key[i][j], tree[x * 2].key[i][0] + tree[x * 2 + 1].key[1][j]);
			tree[x].key[i][j] = max(tree[x].key[i][j], tree[x * 2].key[i][1] + tree[x * 2 + 1].key[0][j]);
		}
}

void build(int x, int l, int r) {
	tree[x].l = l;
	tree[x].r = r;
	for (int i = 0; i <= 1; i ++)
		for (int j = 0; j <= 1; j ++) tree[x].key[i][j] = -(1e15);
	if (l == r) {
		int pos = l & 1;
		tree[x].key[pos][pos] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	update(x);
}

void change(int x, int p, int k) {
	if (tree[x].l == tree[x].r) {
		int pos = tree[x].l & 1;
		tree[x].key[pos][pos] = k;
		tree[x].key[pos ^ 1][pos ^ 1] = -(1e15);
		return;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (p <= mid) change(x * 2, p, k);
		else change(x * 2 + 1, p, k);
	update(x);
}

seg ask(int x, int l, int r) {
	if (tree[x].l == l && tree[x].r == r) return tree[x];
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (r <= mid) return ask(x * 2, l, r);
		else if (l > mid) return ask(x * 2 + 1, l, r);
			else {
				seg tmp, tmp1, tmp2;
				tmp1 = ask(x * 2, l, mid);
				tmp2 = ask(x * 2 + 1, mid + 1, r);
				for (int i = 0; i <= 1; i ++)
					for (int j = 0; j <= 1; j ++) tmp.key[i][j] = -(1e15);
				for (int i = 0; i <= 1; i ++)
					for (int j = 0; j <= 1; j ++) {
						tmp.key[i][j] = max(tmp.key[i][j], tmp1.key[i][j]);
						tmp.key[i][j] = max(tmp.key[i][j], tmp2.key[i][j]);
						tmp.key[i][j] = max(tmp.key[i][j], tmp1.key[i][0] + tmp2.key[1][j]);
						tmp.key[i][j] = max(tmp.key[i][j], tmp1.key[i][1] + tmp2.key[0][j]);
					}
				return tmp;
			}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		build(1, 1, n);
		int typ, u, v;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d", &typ, &u, &v);
			if (typ == 0) {
				seg tmp = ask(1, u, v);
				long long ans = -(1e15);
				for (int p = 0; p <= 1; p ++)
					for (int q = 0; q <= 1; q ++)
						ans = max(ans, tmp.key[p][q]);
				printf("%I64d\n", ans);
//				printf("%lld\n", ans);
			} else {
				change(1, u, v);
			}
		}
	}
	return 0;
}
