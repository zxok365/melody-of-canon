#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[50];
int b[10], tmp[5], c[1005][5], num2;
bool flag[50];
int num[500005];
pair<int, int> d[500005];

void dfs(int x) {
	if (x == 5) {
		num2++;
		for (int i = 1; i <= 4; i ++) c[num2][i] = tmp[i];
		return;
	}
	for (int i = 1; i <= 4; i ++) if (!flag[i]) {
		flag[i] = true;
		tmp[x] = i;
		dfs(x + 1);
		flag[i] = false;
	}
}

bool check(int x, int t) {
	int sum = 0;
	while (x != 0) {
		sum++;
		x -= (x & (-x));
	}
	return (sum == t);
}

int reverse(int x) {
	for (int i = 1; i <= 16; i ++) 
		x ^= (1<<(i - 1));
	return x;
}

int main() {
	dfs(1);
	int tot = 0;
	while (1) {
		tot ++;
		scanf("%d", &a[1]);
		if (a[1] == 0) break;
		for (int i = 2; i <= 16; i ++) scanf("%d", &a[i]);
		int all = 0;
		for (int mask = 1; mask < (1 << 16); mask ++) {
			num[mask] = 0;
			if (check(mask, 4)) {
				b[0] = 0;
				for (int i = 1; i <= 16; i ++) if ((mask & (1 << (i - 1))) != 0) {
					b[++b[0]] = a[i];
				}
				for (int i = 1; i <= num2; i ++) {
					int sum = 0;
					for (int j = 1; j <= 4; j ++) sum += c[i][j] * b[j];
					d[++all] = make_pair(sum, mask);
				}				
			}
		}
		sort(d + 1, d + all + 1);
		for (int i = 1; i <= all; i ++) {
			int j;
			for (j = i + 1; j <= all && d[j].first == d[j - 1].first; j ++);
//			cout << j - i << endl;
			for (int k = i; k < j; k ++)
				for (int l = k + 1; l < j; l ++) {
					if ((d[l].second & d[k].second) == 0) {
						num[d[l].second | d[k].second] += 1;
					}
				}
			i = j - 1;
		}
		long long ans = 0;
		for (int mask = 1; mask < (1<<16); mask ++) {
			if (check(mask, 8)) ans += (long long)num[mask] * (num[reverse(mask)]);
		}
		printf("Case %d: ", tot);
		ans >>= 1ll;
		cout << ans << endl;
	}
	return 0;
}
