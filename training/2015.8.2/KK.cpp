#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m, sa[N], ta[N], tb[N], *rank = ta, *tmp = tb;
int height[N], str[N], K;
char s[N];
bool cmp(int i, int j, int l)
{
	return tmp[i] == tmp[j] && tmp[i + l] == tmp[j + l];
}
void radixSort()
{
	static int w[N];
	fill(w, w + m, 0);
	for (int i = 0; i < n; ++ i)
	{
		w[rank[i]] ++;
	}
	for (int i = 1; i < m; ++ i)
	{
		w[i] += w[i - 1];
	}
	for (int i = n - 1; i >= 0; -- i)
	{
		sa[-- w[rank[tmp[i]]]] = tmp[i];
	}
}
void suffixArray()
{
	for (int i = 0; i < n; ++ i)
	{
		rank[i] = str[i];
		tmp[i] = i;
	}
	radixSort();
	for (int j = 1, i, p; j < n; j <<= 1, m = p)
	{
		for (i = n - j, p = 0; i < n; ++ i)
		{
			tmp[p ++] = i;
		}
		for (i = 0; i < n; ++ i)
		{
			if (sa[i] >= j)
			{
				tmp[p ++] = sa[i] - j;
			}
		}
		radixSort();
		for (swap(tmp, rank), rank[sa[0]] = 0, i = p = 1; i < n; ++ i)
		{
			rank[sa[i]] = cmp(sa[i - 1], sa[i], j) ? p - 1 : p ++;
		}
	}
	for (int i = 0, j, k = 0; i < n; ++ i, k = max(k - 1, 0))
	{
		if (rank[i])
		{
			j = sa[rank[i] - 1];
			for (; str[i + k] == str[j + k]; ++ k);
			height[rank[i]] = k;
		}
	}
}
long long ans[32], cur[32], tt[32];
void mod(int x, long long *cur)
{
	long long tmp[32];
	memset(tmp, 0, sizeof(tmp));
	for (int j = 0; j < K; ++ j) tmp[(j * 10 + x) % K] += cur[j];
	for (int j = 0; j < K; ++ j) cur[j] = tmp[j];
}
int P10[50005], sum[50005], his_cur[50005][32];
int range(int l, int r)
{
	return ((sum[l] - sum[r + 1] * P10[r - l + 1]) % K + K) % K;
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> s >> K)
	{
		n = strlen(s);
		m = 256;
		reverse(s, s + n);
		memset(tmp, 0, sizeof(tmp));
		int i, j;
		bool zero = 0;
		for (i = 0; i < n; ++ i) if (s[i] == '0') {zero = 1; break;}
		for (i = 0; i < n; ++ i) str[i] = s[i];
		str[n ++] = 0;
		P10[0] = 1;
		for (i = 1; i <= n; ++ i) P10[i] = (P10[i - 1] * 10) % K;
		sum[n - 1] = 0;
		for (i = n - 2; i >= 0; -- i) sum[i] = (sum[i + 1] * 10 + str[i] - '0') % K;
		suffixArray();
		/*cout << "SA : ";
		for (i = 0; i < n; ++ i) cout << sa[i] << " ";
		cout << endl;
		cout << "height : ";
		for (i = 0; i < n; ++ i) cout << height[i] << " ";
		cout << endl;*/
		memset(cur, 0, sizeof(cur));
		memset(ans, 0, sizeof(ans));
		int bound = n - 2;
		for (i = 1; i < n; ++ i)
		{
			int H = height[i] + sa[i] - 1;
			//printf("%d %d\n", sa[i], H);
			//cout << " bound H : " << bound << " " << H << endl;
			if (bound >= H)
			{
				for (j = 0; j < K; ++ j) tt[j] = cur[j];
			}
			else
			{
				for (j = 0; j < K; ++ j) tt[j] = his_cur[H + 1][j];
				long long tmp[32];
				int xxx = range(bound + 1, H);
				//cout << "l to r " << bound + 1 << " " << H << " : " << xxx << endl;
				memset(tmp, 0, sizeof(tmp));
				for (j = 0; j < K; ++ j) tmp[(j * P10[H - bound] + xxx) % K] += tt[j];
				for (j = 0; j < K; ++ j) tt[j] = tmp[j];
			}
			//for (j = 0; j < K; ++ j) cout << tt[j] << " ";
			//cout << endl;
			for (; bound >= sa[i]; bound --)
			{
				mod(str[bound] - '0', cur);
				mod(str[bound] - '0', tt);
				if (str[bound] != '0') cur[(str[bound] - '0') % K] ++;
				if (str[bound] != '0' && bound > H) tt[(str[bound] - '0') % K] ++;
				for (j = 0; j < K; ++ j) ans[j] += tt[j];
				for (j = 0; j < K; ++ j) his_cur[bound][j] = cur[j];
			}
			for (j = 0; j < K; ++ j) printf("%lld\n", ans[j]);
			printf("\n");
		}
		if (zero) ans[0] ++;
		for (i = 0; i < K; ++ i) cout << ans[i] << " \n"[i == K - 1];
	}
}


/*

SA : 9 8 7 6 5 4 3 2 1 0 
height : 0 0 0 0 0 0 0 0 0 0 
0 1 0 0 0 0 0 0 0 0
SA : 14 1 12 10 8 6 4 2 13 11 9 7 5 3 0 
height : 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0
SA : 17 16 0 15 1 14 2 13 3 12 4 11 5 10 6 9 7 8 
height : 0 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 
0 136
SA : 45 44 43 41 38 34 29 23 16 8 42 40 37 33 28 22 15 7 39 36 32 27 21 14 6 35 31 26 20 13 5 30 25 19 12 4 24 18 11 3 17 10 2 9 1 0 
height : 0 0 1 1 1 1 1 1 1 1 0 2 2 2 2 2 2 2 0 3 3 3 3 3 3 0 4 4 4 4 4 0 5 5 5 5 0 6 6 6 0 7 7 0 8 0 
11 33 19 14 17 12 28 16 24 30 27 31 21 23 13 0 25
SA : 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 
height : 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 
0 0 0 1 0 0 0 0 0 0 0


*/
