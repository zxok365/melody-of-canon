#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ULL unsigned long long
#define MAG 31
using namespace std;
char s[1005][505];
ULL H[1005], R[1005], P[1005];
int len[1005];
int main()
{
	int n, z = 0, T;
	scanf("%d", &T);
	P[0] = 1;
	for (n = 1; n <= 1000; ++ n) P[n] = P[n - 1] * MAG;
	while (scanf("%d", &n) == 1)
	{
		int i, j, k, l;
		for (i = 1; i <= n; ++ i) scanf("%s", s[i]);
		for (i = 1; i <= n; ++ i)
		{
			len[i] = strlen(s[i]);
			H[i] = 0;
			for (j = 0; j < len[i]; ++ j) H[i] = H[i] * MAG + s[i][j] - 'a';
			R[i] = 0;
			for (j = len[i] - 1; j >= 0; -- j) R[i] = R[i] * MAG + s[i][j] - 'a';
		}
		int ans = 0;
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j) if (i != j)
			{
				ULL S1 = H[i] * P[len[j]] + H[j];
				ULL S2 = R[j] * P[len[i]] + R[i];
				if (S1 == S2) ans ++;
			}
		}
		printf("Case #%d: %d\n", ++ z, ans);
	}
}

