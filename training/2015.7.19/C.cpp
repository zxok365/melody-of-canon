#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 150;

long long A[N][N][N];
int n;

void add(int x, int y, int z, int v) {
	for (int i = x; i <= n; i += (i & -i)) {
		for (int j = y; j <= n; j += (j & -j)) {
			for (int k = z; k <= n; k += (k & -k)) {
				A[i][j][k] += v;
			}
		}
	}
}

long long ask(int x, int y, int z) {
	long long ret = 0;
	for (int i = x; i; i -= (i & -i)) {
		for (int j = y; j; j -= (j & -j)) {
			for (int k = z; k; k -= (k & -k)) {
				ret += A[i][j][k];
			}
		}
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	while (1) {
		int type;
		scanf("%d", &type);
		if (type == 3) {
			break;
		}

		int x, y, z, xx, yy, zz, k;
		if (type == 1) {
			scanf("%d %d %d %d", &x, &y, &z, &k);
			x++, y++, z++;
			add(x, y, z, k);
		} else {
			scanf("%d %d %d %d %d %d", &x, &y, &z, &xx, &yy, &zz);
			x++, y++, z++, xx++, yy++, zz++;
			long long ans = 0;
			ans = ask(xx, yy, zz);
			ans -= (ask(x - 1, yy, zz) + ask(xx, y - 1, zz) + ask(xx, yy, z - 1));
			ans += (ask(x - 1, y - 1, zz) + ask(x - 1, yy, z - 1) + ask(xx, y - 1, z - 1));
			ans -= ask(x - 1, y - 1, z - 1);
			cout << ans << endl;
		}
	}

	return 0;
}

