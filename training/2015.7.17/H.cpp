#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char s[100005];
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	gets(s);
	while (T --)
	{
		gets(s);
		int i, j, k, st, ed, n = strlen(s);
		for (i = 1; i < n; ++ i) if (s[i] == '/' && s[i - 1] == '/')
		{
			st = i + 1;
			break;
		}
		printf("Case #%d: ", ++ z);
		for (i = st; i < n; ++ i)
		{
			if (s[i] == '/' || s[i] == ':') break;
			putchar(s[i]);
		}
		puts("");
	}
}

