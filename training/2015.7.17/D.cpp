#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define mp make_pair
#define PII pair<int, int>
PII gg[400005];
int sz[100005], ggg[400005], *G[100005];
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		map<pair<int, int>, int> M;
		int i, j, k, l, n, q, m;
		scanf("%d %d", &n, &m);
		l = 0;
		for (i = 1; i <= m; ++ i)
		{
			scanf("%d %d", &j, &k);
			gg[l ++] = PII(j, k);
			gg[l ++] = PII(k, j);
		}
		sort(gg, gg + l);
		j = -1;
		for (i = 1; i <= n; ++ i) sz[i] = 0;
		for (i = 0; i < 2 * m; ++ i)
		{
			ggg[i] = gg[i].second;
			if (gg[i].first != j)
			{
				G[gg[i].first] = &ggg[i];
			}
			sz[gg[i].first] ++;
			j = gg[i].first;
		}
/*		for (int i = 1; i <= n; i++)
		{
			cout << i << ':' << endl;
			for (int j = 0; j < G[i].size();j++)
				cout << G[i][j] << ' ' ;
			cout << endl;
		}*/
		scanf("%d", &q);
		printf("Case #%d:\n", ++ z);
		for (i = 1; i <= q; ++ i)
		{
			int s, t;
			scanf("%d %d", &s, &t);
			if (sz[t] > sz[s] || (sz[t] == sz[s] && t > s)) swap(s, t);
		//`	cout << s << ' ' << t << endl;
			int *it = lower_bound(G[s], G[s] + sz[s], t);
			if (s == t)
			{
				printf("0 1\n");
			}
			else if (it != G[s] + sz[s] && *it == t)
			{
				//cout << *lower_bound(G[s].begin(),G[s].end(),t) << endl;
				int ans = upper_bound(G[s], G[s] + sz[s], t) - lower_bound(G[s], G[s] + sz[s], t);
				printf("%d %d\n", 1, ans);
			}
			else
			{
				int ans = 0;
				if (M.count(mp(s, t)))
				{
					ans = M[mp(s, t)];
				}
				else
				{
					for (k = 0; k < sz[t]; ++ k)
					{
						int tmp = upper_bound(G[s], G[s] + sz[s], G[t][k]) - lower_bound(G[s], G[s] + sz[s], G[t][k]);
						ans += tmp;
					}
					M[pair<int, int>(s, t)] = ans;
				}
				if (ans == 0) printf("The pair of cities are not connected or too far away.\n");
				else printf("2 %d\n", ans);
			}
		}
	}
	return 0;
}

