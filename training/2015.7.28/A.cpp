#include <cstdio>
#include <iostream>

using namespace std;

int s, t, m, a, b, c;
int sum[105], flag[105];

int main() {
	int tot = 0;
	while (1) {
		scanf("%d%d%d", &s, &t, &m);
		tot++;
		if (s == 0 && t == 0 && m == 0) break;
		for (int i = 1; i <= s; i ++) sum[i] = flag[i] = 0;
		for (int i = 1; i <= s; i ++) {
			scanf("%d%d%d", &a, &b, &c);
			sum[a] += b + c;
		}
		for (int i = 1; i <= t; i ++) {
			scanf("%d%d", &a, &b);
			if (b >= m) flag[a] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= s; i ++) ans += sum[i] + flag[i];
		printf("Case %d: %d\n", tot, ans);
	}
	return 0;
}
