#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct nod
{
	long long type, cnt;
	int ind;
	nod() {type = cnt = ind = 0;}
	nod(long long type, long long cnt, int ind) : type(type) , cnt(cnt) , ind(ind) {}
};
bool operator < (const nod &a, const nod &b)
{
	return a.type * a.cnt > b.type * b.cnt;
}
vector<nod> G[20];
vector<int> ans;
unsigned long long P[20];
int main()
{
	long long x;
	int n, i, j, k, l;
	P[0] = 1;
	for (i = 1; i <= 19; ++ i) P[i] = P[i - 1] * 10;
	//cout << P[19] << endl;
	//printf("%ulld\n", P[19]);
	scanf("%lld%d", &x, &n);
	for (i = 1; i <= n; ++ i)
	{
		long long t, c;
		scanf("%lld%lld", &t, &c);
		G[t].push_back(nod(P[t], c, i));
	}
	unsigned long long remain = 0;
	bool flag = 1;
	for (i = 0; i <= 18; ++ i)
	{
		sort(G[i].begin(), G[i].end());
		j = 0;
		while (j < G[i].size() && remain < x % P[i + 1])
		{
			ans.push_back(G[i][j].ind);
			remain += G[i][j].type * G[i][j].cnt;
			j ++;
		}
		if (remain < x % P[i + 1])
		{
			flag = 0;
			break;
		}
		remain -= x % P[i + 1];
		x -= x % P[i + 1];
		for (; j < G[i].size(); ++ j)
		{
			G[i + 1].push_back(G[i][j]);
		}
	}
	if (!flag)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", ans.size());
		for (i = 0; i < ans.size(); ++ i) printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	}
}

