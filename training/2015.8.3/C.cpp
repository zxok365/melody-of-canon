#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int st[100005], top;
char ins[100005][5];
int f[100005];
bool outer(long long a)
{
	if (a > (int)1e9 || a < (int)-1e9) return 1;
	return 0;
}
int main()
{
	while (true)
	{
		int n, m = 0;
		while (true)
		{
			m ++;
			scanf("%s", ins[m]);
			if (ins[m][0] == 'E' || ins[m][0] == 'Q') break;
			if (ins[m][0] == 'N') scanf("%d", &f[m]);
		}
		if (ins[m][0] == 'Q') break;
		m --;
		scanf("%d", &n);
		bool need = 1;
		for (int i = 1; i <= n; ++ i)
		{
			int init;
			scanf("%d", &init);
			st[top = 1] = init;
			bool flag = 0;
			if (need)
			for (int j = 1; j <= m; ++ j)
			{
				char *s = ins[j];
				if (s[0] == 'N')
				{
					st[++ top] = f[j];
				}
				else if (s[0] == 'P')
				{
					if (top == 0) {need = 0; flag = 1; break;}
					top --;
				}
				else if (s[0] == 'I')
				{
					if (top == 0) {need = 0; flag = 1; break;}
					st[top] = -st[top];
				}
				else if (s[0] == 'D' && s[1] == 'U')
				{
					if (top == 0) {need = 0; flag = 1; break;}
					top ++;
					st[top] = st[top - 1];
				}
				else if (s[0] == 'S' && s[1] == 'W')
				{
					if (top <= 1) {need = 0; flag = 1; break;}
					swap(st[top], st[top - 1]);
				}
				else if (s[0] == 'A')
				{
					if (top <= 1) {need = 0; flag = 1; break;}
					if (outer(st[top] + st[top - 1])) {flag = 1; break;}
					st[top - 1] = st[top] + st[top - 1];
					top --;
				}
				else if (s[0] == 'S' && s[1] == 'U')
				{
					if (top <= 1) {need = 0; flag = 1; break;}
					if (outer(st[top - 1] - st[top])) {flag = 1; break;}
					st[top - 1] = st[top - 1] - st[top];
					top --;
				}
				else if (s[0] == 'M' && s[1] == 'U')
				{
					if (top <= 1) {need = 0; flag = 1; break;}
					if (outer(1LL * st[top - 1] * st[top])) {flag = 1; break;}
					st[top - 1] = st[top - 1] * st[top];
					top --;
				}
				else if (s[0] =='D' && s[1] == 'I')
				{
					if (top <= 1) {need = 0; flag = 1; break;}
					if (st[top] == 0) {flag = 1; break;}
					st[top - 1] = st[top - 1] / st[top];
					top --;
				}
				else if (s[0] == 'M' && s[1] == 'O')
				{
					if (top <= 1) {need = 0; flag = 1; break;}
					if (st[top] == 0) {flag = 1; break;}
					st[top - 1] = st[top - 1] % st[top];
					top --;
				}
			}
			if (!flag && top != 1)
			{
				need = 0;
				flag = 1;
			}
			if (!need) flag = 1;
			if (flag) puts("ERROR"); else printf("%d\n", st[1]);
		}
		puts("");
	}
}

