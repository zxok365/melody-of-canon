#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

int up(int x) {
	if (x <= 0) return 0;
	return 1
}

int main() {
	int tot = 0;
	while (1) {
		tot ++;
		int W, L;
		scanf("%d%d", &W, &L);
		if (W == 0 && L == 0) break;
		if (L == 0) {
			printf("Case %d:\n", tot);
			if (W < 8) puts("Situation Impossible.");
				else printf("On Average Bob Reaches Round %.2f\n", 8.);
			continue;
		}
		int left = L + up(W - 7 * L);
		int right = L + W / 8;
		long double delta = log(1.0 * right / left) / 20000.0;
		long double ans = 0;
		for (int i = left; i <= right; i ++) {
			int new_r = min((int)(delta / (1.0 / i)) + i, right);
			ans += (2.0 / (i + new_r)) * (new_r - i + 1);
			i = new_r;
		}
		ans = ans * (W + L) / (1.0 + right - left);
		printf("Case %d:\n", tot);
		printf("On Average Bob Reaches Round %.2f\n", (double)ans);		
	}
	return 0;
}
