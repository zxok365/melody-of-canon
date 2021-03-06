#include <cstdio>
#include <iostream>

using namespace std;

int n, m, c, curx, cury;
int sum[50];
int ans[50][50];

void insert(int col) {
	ans[curx][cury]=col;
	if ((curx&1)==1 && cury==m) {
		curx++;
		return;
	}
	if ((curx&1)==0 && cury==1) {
		curx++;
		return;
	}
	if ((curx&1)==1) {
		cury++;
		return;
	}
	cury--;
}

int main() {
	while (scanf("%d%d%d", &n, &m, &c) == 3) {
		for (int i=1; i<=c; i++) scanf("%d", &sum[i]);
		curx=1;
		cury=1;
		for (int i=1; i<=c; i++) 
			for (int j=1; j<=sum[i]; j++) insert(i);
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) printf("%d", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
