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
		memset(cur, 0, sizeof(cur));
		memset(ans, 0, sizeof(ans));
		int bound = n - 2;
		for (int l = n - 1; l >= 0; -- l)
		{
			i = rank[l];
			int H = height[i] + sa[i] - 1;
			if (bound >= H)
			{
				for (j = 0; j < K; ++ j) tt[j] = cur[j];
			}
			else
			{
				for (j = 0; j < K; ++ j) tt[j] = his_cur[H + 1][j];
				long long tmp[32];
				int xxx = range(bound + 1, H);
				memset(tmp, 0, sizeof(tmp));
				for (j = 0; j < K; ++ j) tmp[(j * P10[H - bound] + xxx) % K] += tt[j];
				for (j = 0; j < K; ++ j) tt[j] = tmp[j];
			}
			for (; bound >= sa[i]; bound --)
			{
				mod(str[bound] - '0', cur);
				mod(str[bound] - '0', tt);
				if (str[bound] != '0') cur[(str[bound] - '0') % K] ++;
				if (str[bound] != '0' && bound > H) tt[(str[bound] - '0') % K] ++;
				for (j = 0; j < K; ++ j) ans[j] += tt[j];
				for (j = 0; j < K; ++ j) his_cur[bound][j] = cur[j];
			}
		}
		if (zero) ans[0] ++;
		for (i = 0; i < K; ++ i) cout << ans[i] << " \n"[i == K - 1];
	}
}
