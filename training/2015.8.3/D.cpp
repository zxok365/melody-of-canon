#include <cstdio>
#include <iostream>

using namespace std;

char s[1005][1005];
char txt[1005][1005];
char ans[1000005];
bool flag[6][1005][1005];
int n;

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) flag[1][i][j] = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%s", s[i]);
			for (int j = n; j >= 1; j --) {
				s[i][j] = s[i][j - 1];
				if (s[i][j] == 'O') flag[1][i][j] = true;
			}
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%s", txt[i]);
			for (int j = n; j >= 1; j --) txt[i][j] = txt[i][j - 1];
		}
		int len = 0;
		for (int t = 1; t <= 4; t ++) {
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= n; j ++)
					if (flag[t][i][j]) ans[len++] = txt[i][j];
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= n; j ++)
					flag[t + 1][j][n - i + 1] = flag[t][i][j];
		}
		ans[len] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
