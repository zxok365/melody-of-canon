#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long up(long long x) {
	if (x <= 0) return 0;
	long long sum = x / 8;
	if (x % 8 != 0) sum++;
	return sum;
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
			if (W % 8 != 0) puts("Situation Impossible.");
				else printf("On Average Bob Reaches Round %.2f\n", (double)8);
			continue;
		}
		long long left = 0LL + L + up(0LL + W - 7LL * L);
		long long right = 0LL + L + W / 8;
		long double delta = log(1.0 * right / left) / 10000.0;
		long double ans = 0;
		for (long long i = left; i <= right; i ++) {
			long long new_r = min((long long)(delta / (1.0 / i)) + i, right);
			ans += (2.0 / (i + new_r)) * (new_r - i + 1);
			i = new_r;
		}
		ans = ans * (0LL + W + L) / (1.0 + right - left);
		printf("Case %d:\n", tot);
		printf("On Average Bob Reaches Round %.2f\n", (double)ans);		
	}
	return 0;
}
