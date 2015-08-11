#include <cstdio>
#include <iostream>

#define left asdjkasdk
#define right adfa

using namespace std;

const int MAXN = 10000000;

int n, m, tot;
int a[100005];
int left[300005], right[300005], sum[300005], mx[300005], prime[5000005];
bool flag[10000005];

void prepare() {
	for (int i = 2; i <= MAXN; i ++) {
		if (!flag[i]) {
			prime[++tot] = i;
			for (int j = 1; j <= tot; j ++) {
				if (i * prime[j] > MAXN) break;
				flag[i * prime[j]] = true;
				if (i % prime[j] == 0) break;
			}
		} else {
			for (int j = 1; j <= tot; j ++) {
				if (i * prime[j] > MAXN) break;
				flag[i * prime[j]] = true;
				if (i % prime[j] == 0) break;
			}
		}
		if ((i & (-i)) == i) flag[i] = false;
	}
	flag[0] = false;
	flag[6] = false;
}

void update(int x) {
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
	sum[x] = sum[x * 2] + sum[x * 2 + 1];
}

void build(int x, int l, int r) {
	left[x] = l;
	right[x] = r;
	if (l == r) {
		sum[x] = 1 - flag[a[l]];
		mx[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	update(x);
}

int asksum(int x, int l, int r) {
	if (l == left[x] && r == right[x]) return sum[x];
	int mid = left[x] + right[x] >> 1;
	if (r <= mid) return asksum(x * 2, l, r);
		else if (l > mid) return asksum(x * 2 + 1, l, r);
			else return asksum(x * 2, l, mid) + asksum(x * 2 + 1, mid + 1, r);
}

void change1(int x, int l, int r, int v) {
	if (l == left[x] && r == right[x]) {
		if (mx[x] >= v) {
			if (l == r) {
				a[l] %= v;
				mx[x] = a[l];
				sum[x] = 1 - flag[a[l]];
			} else {
				int mid = left[x] + right[x] >> 1;
				if (mx[x * 2] >= v) change1(x * 2, l, mid, v);
				if (mx[x * 2 + 1] >= v) change1(x * 2 + 1, mid + 1, r, v);
				update(x);
			}
		}
		return;
	}
	int mid = left[x] + right[x] >> 1;
	if (r <= mid) change1(x * 2, l, r, v);
		else if (l > mid) change1(x * 2 + 1, l, r, v);
			else {
				change1(x * 2, l, mid, v);
				change1(x * 2 + 1, mid + 1, r, v);
			}
	update(x);
}

void change2(int x, int l, int v) {
	if (left[x] == right[x]) {
		a[l] = v;
		mx[x] = v;
		sum[x] = 1 - flag[v];
		return;
	}
	int mid = left[x] + right[x] >> 1;
	if (l <= mid) change2(x * 2, l, v);
		else change2(x * 2 + 1, l, v);
	update(x);
}

int main() {
	prepare();
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		build(1, 1, n);
		scanf("%d", &m);
		int v, type, l, r, p, x;
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &type);
			if (type == 1) {
				scanf("%d%d", &l, &r);
				printf("%d\n", asksum(1, l, r));
			} else if (type == 2) {
				scanf("%d%d%d", &l, &r, &v);
				change1(1, l, r, v);
			} else if (type == 3) {
				scanf("%d%d", &p, &x);
				change2(1, p, x);
			}
		}
	}
	return 0;
}
