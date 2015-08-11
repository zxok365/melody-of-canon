#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[10005], ss[5] = "ACGT";
int main()
{
	int n, cnt[4];
	scanf("%d", &n);
	scanf("%s", s);
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 0; i < n; ++ i)
	{
		if (s[i] == 'A') cnt[0] ++;
		else if (s[i] == 'C') cnt[1] ++;
		else if (s[i] == 'G') cnt[2] ++;
		else if (s[i] == 'T') cnt[3] ++;
	}
	int ans = 0;
	if (cnt[1] < cnt[ans]) ans = 1;
	if (cnt[2] < cnt[ans]) ans = 2;
	if (cnt[3] < cnt[ans]) ans = 3;
	printf("%d\n", cnt[ans]);
	for (int i = 0; i < n; ++ i) putchar(ss[ans]);
	puts("");
}

