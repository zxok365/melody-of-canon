#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;
char s[505];
int sum[5], a[5];;

int abs(int x) {
	if (x < 0) x = -x;
	return x;
}

int main() {
	scanf("%d%d%d", &n, &a[0], &a[1]);
	scanf("%s", s);
	if (a[0] + a[1] > n) {
		printf("-1\n");
	} else {
		a[2] = n - a[0] - a[1];
		for (int i = 0; i < n; i ++) sum[s[i] - '0']++;
		a[0] -= sum[0];
		a[1] -= sum[1];
		a[2] -= sum[2];
		int mx = 0;
		int maxi = 0;;
		if (abs(a[0]) > abs(mx)) {
			mx = a[0];
			maxi = 0;
		}
		if (abs(a[1]) > abs(mx)) {
			mx = a[1];
			maxi = 1;
		}
		if (abs(a[2]) > abs(mx)) {
			mx = a[2];
			maxi = 2;
		}
		printf("%d\n", abs(mx));
		if (mx > 0) {
			for (int i = 0; i < n; i ++) {
				if (s[i] - '0' != maxi && a[maxi] != 0 && a[s[i] - '0'] != 0) {
					a[s[i] - '0']++;
					a[maxi] --;
					s[i] = '0' + maxi;
				}
			}
		} else {
			for (int i = 0; i < n; i ++) {
				if (s[i] - '0' == maxi && a[maxi] != 0) {
					int j;
					for (j = 0; j <= 2; j ++)
						if (j != maxi && a[j] != 0) break;
					a[maxi]++;
					a[j]--;
					s[i] = '0' + j;
				}
			}
		}
		printf("%s\n", s);
	}
	return 0;
}
