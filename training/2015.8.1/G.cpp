#include <cstdio>
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

char c;
bool flag[200005];
int b[200005], g[200005];
int n, m;
int ans[200005];
priority_queue<pair<int, int> > heap;

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++) {
		scanf(" %c", &c);
		scanf("%d", &m);
		if (c == 'p') {
			flag[i] = true;
			b[i] = m;
			b[i] --;
		} else g[i] = m;
	}
	for (int i = 2; i <= n; i ++) {
		int j;
		for (j = i; j <= n; j ++) if (flag[j]) break;
		if (j != n) {
			while (heap.size() > b[j]) {
				heap.pop();
			}
			for (int k = i; k < j; k ++) {
				if (heap.size() < b[j]) {
					heap.push(make_pair(-g[k], k));
				} else if ((!heap.empty()) && (g[k] > -(heap.top().first))) {
					heap.pop();
					heap.push(make_pair(-g[k], k));
				}
			}
			i = j;
			continue;
		} else {
			for (int k = i; k < n; k ++) heap.push(make_pair(-g[k], k));
			if (heap.size() <= b[n]) {
				printf("-1\n");
			} else {
				int sum = 0;
				int tot = 0;
				while (!heap.empty()) {
					sum += -heap.top().first;
					ans[++tot] = heap.top().second;
					heap.pop();
				}
				printf("%d\n", sum);
				sort(ans + 1, ans + tot + 1);
				printf("%d\n", tot);
				for (int t = 1; t <= tot; t++) printf("%d%c", ans[t], t == tot ? '\n' : ' ');
			}
			i = n;
		}
	}
	return 0;
}
