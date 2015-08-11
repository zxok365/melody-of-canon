#include <cstdio>
#include <iostream>

using namespace std;

int n, m, a[10], b[10];

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d%d", &n, &m);
		int tot1 = 0 ;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			tot1 += a[i];
		}
		int tot2 = 0;
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &b[i]);
			tot2 += b[i];
		}
		if (tot1 > tot2) puts("Calem");
			else if (tot1 < tot2) puts("Serena");
				else puts("Draw");
	}
}
