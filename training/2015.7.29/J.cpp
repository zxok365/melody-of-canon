#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[30][30], ans = - INF, ans_sz, TAR;
char sans[30][100], tans[30][100], co[5] = "+-*/";
void upd(int x, int Left)
{
	if (ans != -INF && abs(ans - TAR) <= abs(x - TAR)) return;
	//printf("upd in %d %d", x, Left);
	ans = x;
	ans_sz = 0;
	for (int i = 6; i > Left; -- i)
	{
		sprintf(sans[ans_sz ++], "%s", tans[i]);
	}
}
int calc(int k, int x, int y)
{
	long long res = 0;
	if (k == 0) res = 0LL + x + y;
	else if (k == 1) res = 0LL + x - y;
	else if (k == 2) res = 1LL *  x * y;
	else if (y != 0 && x % y == 0) res = x / y;
	else res = - INF;
	if (res >= 1e8) res = -INF;
	return (int)res;
}
void dfs(int Left, int last)
{
	upd(a[Left][1], Left);
	if (ans == TAR) return;
	if (Left == 1) return;
	sort(a[Left] + 1, a[Left] + 1 + Left, greater<int>());
	for (int i = 1; i <= Left; ++ i)
	{
		for (int j = i + 1; j <= Left; ++ j)
		{
			for (int k = 0; k < 4; ++ k)
			{
				if (last == 0 && k == 1) continue;
				if (last == 3 && k == 4) continue;
				a[Left - 1][1] = calc(k, a[Left][i], a[Left][j]);
				if (a[Left - 1][1] <= 0) continue;
				sprintf(tans[Left], "%d %c %d = %d", a[Left][i], co[k], a[Left][j], a[Left - 1][1]);
				int tmp = 1;
				for (int l = 1; l <= Left; ++ l) if (l != i && l != j) a[Left - 1][++ tmp] = a[Left][l];
				dfs(Left - 1, k);
				if (ans == TAR) return;
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int i;
		for (i = 1; i <= 6; ++ i) scanf("%d", &a[6][i]);
		ans = - INF;
		scanf("%d", &TAR);
		for (i = 1; i <= 6; ++ i) upd(a[6][i], 6);
		/*printf("***Target: %d\n", TAR);
		for (i = 0; i < ans_sz; ++ i)
		{
			printf("***%s\n", sans[i]);
		}
		printf("***Best approx: %d\n", ans);*/

		dfs(6, -1);
		printf("Target: %d\n", TAR);
		for (i = 0; i < ans_sz; ++ i)
		{
			printf("%s\n", sans[i]);
		}
		printf("Best approx: %d\n\n", ans);
	}
}

