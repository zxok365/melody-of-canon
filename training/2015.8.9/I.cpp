#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int pos[1000005]; //, ind[1000005];
vector<int> ans[1000005];
/*bool cmp(int i, int j)
{
	return ans[i][0] < ans[j][0];
}*/
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		int j;
		scanf("%d", &j);
		pos[j] = i;
	}
	int tot = 0, cur_first = n + 1, cur_sz= 0;
	for (int i = n; i >= 1; -- i)
	{
		if (cur_sz == 0)
		{
			cur_sz = cur_first - pos[i] - 1;
			cur_first = pos[i];
			ans[tot].push_back(i);
			tot ++;
		}
		else
		{
			ans[tot - 1].push_back(i);
			if (pos[i] > cur_first)
			{
				cur_sz --;
			}
			else
			{
				cur_sz += cur_first - pos[i] - 1;
				cur_first = pos[i];
			}
		}
	}
	for (int i = 0; i < tot; ++ i) reverse(ans[i].begin(), ans[i].end());
	printf("%d\n", tot);
	for (int cur = tot - 1; cur >= 0; -- cur)
	{
		printf("%d", ans[cur].size());
		for (int j = 0; j < ans[cur].size(); ++ j) printf(" %d", ans[cur][j]);
		printf("\n");
	}
}

