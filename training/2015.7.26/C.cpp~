#include <cstdio>
#include <iostream>

using namespace std;

long long f[1005];
int ans, n, tot;
int a[50];

void prepare() {
	f[1] = 1;
	f[2] = 2;
	for (tot = 3; tot <= 1000; tot ++) {
		f[tot] = f[tot - 1] + f[tot - 2];
		if (f[tot] >= 2000000000) break;
	}
}

int check(int x) {
	int sum = 0;
	for (int i = tot; i >= 1; i --) while (f[i] <= x) {
		sum++;
		x -= f[i];
	}
	return sum;
}

int main() {
	prepare();
	int test;
	scanf("%d", &test);
	int tot = 0;
	while (test--) {
		tot++;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		long long ans = 1;
		for (int i = 1; i <= n; i ++) ans *= check(a[i]);
		printf("Case %d: ", tot);
		cout << ans << endl;
	}
	return 0;
}
