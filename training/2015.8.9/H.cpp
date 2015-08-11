#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct monster
{
	long long da, bao;
	int cnt;
	monster(long long da = 0, long long bao = 0, int cnt = 0) : da(da), bao(bao), cnt(cnt) {}
};
struct nod
{
	long long cost;
	int id;
	nod(long long cost = 0, int id = 0) : cost(cost), id(id) {}
};
bool operator < (const nod &i, const nod &j)
{
	return i.cost > j.cost;
}
monster M[200005];
vector<int> upd[200005];
bool dabao[200005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		int da, bao, cnt;
		scanf("%d%d%d", &da, &bao, &cnt);
		M[i] = monster(da, bao, cnt);
		for (int j = 0; j < cnt; ++ j)
		{
			int v;
			scanf("%d", &v);
			upd[v].push_back(i);
		}
	}
	priority_queue<nod> q;
	for (int i = 1; i <= n; ++ i) q.push(nod(M[i].bao, i));
	long long ans;
	while (!q.empty())
	{
		while (dabao[q.top().id]) q.pop();
		nod p = q.top(); q.pop();
		dabao[p.id] = true;
		if (p.id == 1)
		{
			ans = p.cost;
			break;
		}
		for (int j = 0; j < upd[p.id].size(); ++ j)
		{
			int v = upd[p.id][j];
			if (dabao[v]) continue;
			M[v].cnt --;
			M[v].da += p.cost;
			if (M[v].cnt == 0)
			{
				q.push(nod(M[v].da, v));
			}
		}
	}
	cout << ans << endl;
}

