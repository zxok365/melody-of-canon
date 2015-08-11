#include <cstdio>
#include <iostream>
#include <cstring>
#include<string>
#include <algorithm>
using namespace std;

struct mat {
	int c[55][55];
	mat(){}
} unit, init, ans;

const int mo = 1e9 + 7;

string ss[55];
int n, m;
char s[55][55];
int len[55];
bool flag[55];

bool check(int x, int y, int p, int len) {
	for (int i = 1; i <= len; i ++) 
		if (s[x][p + i] != s[y][i]) return false;
	return true;
}

int count(int x, int y) {
	int sum = 0;
	int le = min(len[x], len[y]);
	for (int i = 2; i <= le; i ++) 
		if (check(x, y, len[x] - i, i)) sum++;
	return sum;
}

mat cheng(const mat &a, const mat &b) {
	mat tmp;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) tmp.c[i][j] = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= n; k ++) {
				tmp.c[i][j] = (tmp.c[i][j] + (1ll * a.c[i][k] * b.c[k][j]) % mo) % mo;
			}
	return tmp;
}

mat power(int p) {
	if (p == 0) return unit;
	mat t = power(p >> 1);
	t = cheng(t, t);
	if ((p & 1) == 1) t = cheng(t, init);
	return t;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) unit.c[i][i] = 1;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%s", s[i] + 1);
			ss[i] = (s[i] + 1);
		}
		sort(ss + 1, ss + n + 1);
		int t = unique(ss + 1,ss + n + 1) - ss - 1;
		n = t;
		for (int i = 1; i <= n; i ++)
		{
			len[i] = ss[i].size();
			for (int j = 1; j <= len[i]; j++)
				s[i][j] = ss[i][j - 1];
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++)
				init.c[i][j] = min(count(i, j), 1);
		}
		if (n <= 0 || m <= 0) {
			printf("1\n");
		} else {
			ans = power(m - 1);
			int sum = 0;
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= n; j ++) sum = (sum + ans.c[i][j]) % mo;
			printf("%d\n", sum);
		}
	}
	return 0;
}

/*
   1 1 1 0 1 1 0 1 0 0 
   0 1 0 1 0 0 0 0 0 1 
   1 1 2 0 1 1 0 1 0 0 
   0 0 0 1 0 0 0 0 0 0 
   0 0 0 1 1 0 0 0 0 1 
   1 1 1 0 2 2 0 1 0 0 
   0 0 0 0 1 1 1 1 0 0 
   0 0 0 0 1 1 0 1 0 0 
   0 0 0 0 0 0 0 0 0 0 
   0 0 0 1 0 0 0 0 0 1 

 */
