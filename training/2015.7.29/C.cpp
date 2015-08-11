#include <cstdio>
#include <iostream>

using namespace std;

const int MO = 1e9 + 7;

int n;
int p[55], a[55];
int power[55], sum1[55], sum2[55];

void prepare(int x, int p, int a) {
	int sum = 0;
	int tmp = 1;
	for (int i = 0; i <= a; i ++) {
		sum = (sum + tmp) % MO;
		if (i == a - 1) sum1[x] = sum;
		if (i == a) {
			sum2[x] = sum;
			power[x] = tmp;
		}
		tmp = (long long)tmp * p % MO;
	}
}

int po(int p, int q) {
	if (q == 0) return 1;
	int tmp = po(p, q / 2);
	tmp = (long long)tmp * tmp % MO;
	if ((q & 1) == 1) tmp = (long long)tmp * p % MO;
	return tmp;
}

int get() {
	int tmp = 1;
	for (int i = 1; i <= n; i ++ ) tmp = (long long)tmp * power[i] % MO;
	return tmp;
}

int main() {
	int test;
	scanf("%d", &test);
	int tot = 0;
	while (test--) {
		tot ++;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i ++) scanf("%d%d", &p[i], &a[i]);
		for (int i = 1; i <= n; i ++) prepare(i, p[i], a[i]);
		for (int mask = 0; mask < (1<<n); mask ++) {
			int k1 = 1;
			int k2 = 1;
			int p = 1;
			int q = 1;
			for (int i = 1; i <= n; i ++) {
				if ((mask & (1<<(i - 1))) != 0) {
					k1 = (long long)k1 * power[i] % MO;
					k2 = (long long)k2 * sum2[i] % MO;
					q = (long long)q * (a[i] + 1) % MO;
				} else {
					k1 = (long long)k1 * sum1[i] % MO;
					k2 = (long long)k2 * power[i] % MO;
					p = (long long)p * a[i] % MO;
				}
			}
			ans = ((long long)ans + (((long long)k1 * q) % MO + ((long long)k2 * p) % MO) % MO) % MO;
		//	cout << ans << endl;
		}
		ans = (((long long)ans * po(2, MO - 2) % MO) + get()) % MO;
		printf("Case %d: %d\n", tot, ans);
	}
	return 0;
}
