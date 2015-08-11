#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int index(char c)
{
	if (c >= 'a') return c - 'a';
	return 26 + c - 'A';
}
char s[300005];
int main()
{
	int n, i, j, k, l;
	scanf("%d", &n);
	gets(s); gets(s);
	map<long long, int> M;
	M[0] = 1;
	long long cur = 0, ans = 0;
	for (i = 0; i < n; ++ i)
	{
		//int odd = 0, even = 0;
		cur ^= 1LL << index(s[i]);
		//long long flip = cur ^ ((1LL << 52) - 1);
		if (M.count(cur)) ans += M[cur];
		for (j = 0; j < 52; ++ j)
		{
			long long tmp = cur ^ (1LL << j);
			if (M.count(tmp)) ans += M[tmp]; //, odd += M[tmp];
		}
		//printf("*** %d  odd = %d even = %d\n", i, odd, even);
		M[cur] ++;
	}
	cout << ans << endl;
}

