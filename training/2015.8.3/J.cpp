#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
char s1[N], s2[N], ans[N];
int main()
{
	while (scanf("%s%s", s1, s2) == 2)
	{
		int i, n = strlen(s1), m = strlen(s2);
		for (i = 0; i < m; ++ i)
		{
			char a = s1[i % n], b = s2[i];
			ans[i] = (a - 'A' + 1 + b - 'A' + 1 - 1) % 26 + 'A';
		}
		ans[m] = 0;
		puts(ans);
	}
}

