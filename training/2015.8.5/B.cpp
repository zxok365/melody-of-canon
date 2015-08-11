#include <cstdio>
#include <iostream>

using namespace std;


#define link  link1
#define other other1
int n, m, l;
int lst[505], pre[500005], other[500005], link[505];
bool flag[505];

void add(int u, int v) {
	l++;
	pre[l] = lst[u];
	lst[u] = l;
	other[l] = v;
}

bool find(int x) {
	flag[x] = true;
	for (int p = lst[x]; p != 0; p = pre[p]) {
		int q = other[p];
		if (link[q] == 0 || ((!flag[link[q]]) && find(link[q]))) {
			link[q] = x;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		int k, u;
		scanf("%d", &k);
		while (k --) {
			scanf("%d", &u);
			add(i, u);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) flag[j] = false;
		if (find(i)) ans++;
	}
	if (ans < m) puts("Alice");
		else puts("Bob");
	return 0;
}
