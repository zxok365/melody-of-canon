#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define PII pair<int, int>
using namespace std;
struct course
{
	int s, t, id;
	course() {s = t = id = 0;}
	course(int s, int t, int id) : s(s), t(t), id(id) {}
};
bool cmp1(const course &a, const course &b)
{
	return a.s < b.s;
}
bool cmp2(const course &a, const course &b)
{
	return a.t < b.t;
}
int NN;
PII tree[200005], dp[100005];
vector<int> tot;
course a[100005];
inline int lowbit(int x) {return x & -x;}
PII imax(PII a, PII b)
{
	if (a.first < b.first) return b;
	if (a.first > b.first) return a;
	if (a.second < b.second) return a;
	return b;
}
PII query(int x)
{
	PII res = PII(0, 0);
	while (x)
	{
		res = imax(res, tree[x]);
		x -= lowbit(x);
	}
	return res;
}
void add(int x, PII c)
{
	while (x <= NN)
	{
		tree[x] = imax(tree[x], c);
		x += lowbit(x);
	}
}
vector<int> A[100005];
bool in_chain[100005];
int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		tot.clear();
		for (i = 1; i <= n; ++ i)
		{
			scanf("%d%d", &j, &k);
			a[i] = course(j, k, i);
			tot.push_back(j);
			tot.push_back(k);
		}
		sort(tot.begin(), tot.end());
		tot.erase(unique(tot.begin(), tot.end()), tot.end());
		for (i = 1; i <= n; ++ i)
		{
			a[i].s = lower_bound(tot.begin(), tot.end(), a[i].s) - tot.begin() + 1;
			a[i].t = lower_bound(tot.begin(), tot.end(), a[i].t) - tot.begin() + 1;
			//printf(" newxy : %d %d\n", a[i].s, a[i].t);
		}
		NN = (int) tot.size() + 1;
		memset(tree, 0, sizeof(tree));
		sort(a + 1, a + 1 + n, cmp2);
		for (i = 1; i <= n; ++ i)
		{
			PII tmp = query(a[i].s);
			dp[i] = PII(tmp.first + 1, tmp.second);
			add(a[i].t, PII(dp[i].first, i));
		}
	    //printf("###\n");
		int ans = 0, ans_ind;
		for (i = 1; i <= n; ++ i)
		{
			if (ans < dp[i].first)
			{
				ans = dp[i].first;
				ans_ind = i;
			}
		}
		for (i = 1; i <= n; ++ i) in_chain[i] = 0;
		vector<course> chain;
		for (i = ans_ind; i; i = dp[i].second)
		{
			in_chain[a[i].id] = 1;
			chain.push_back(a[i]);
		}
		reverse(chain.begin(), chain.end());
		sort(a + 1, a + 1 + n, cmp2);
		//printf("***\n");
		for (i = 0; i < ans; ++ i) A[i].clear(), A[i].push_back(chain[i].id);
		int cur = 0;
		for (i = 1; i <= n; ++ i)
		{
			if (in_chain[a[i].id]) continue;
			while (cur < ans - 1 && chain[cur].t <= a[i].s) cur ++;
			A[cur].push_back(a[i].id);
		}
		//printf("***\n");
		printf("%d\n", ans);
		for (i = 0; i < ans; ++ i)
		{
			sort(A[i].begin(), A[i].end());
			for (j = 0; j < (int ) A[i].size(); ++ j) printf("%d%c", A[i][j], " \n"[j == (int) A[i].size() - 1]);
		}
		printf("\n");
	}
}

