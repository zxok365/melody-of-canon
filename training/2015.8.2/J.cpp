#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct nod
{
	int x, y, d, step;
	bool reach;
	nod() {x = y = d = step = reach = 0;}
	nod(int x, int y, int d, int step, bool reach) : x(x), y(y), d(d), step(step), reach(reach) {}
};
int map[25][25];
bool v[25][25][4][2];
int xz[4] = {1, 0, -1, 0}, yz[4] = {0, 1, 0, -1};
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int n, i, j, k, l, type, qq, ww;
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		bool no_gold = 1;
		while (scanf("%d%d%d", &type, &qq, &ww) == 3)
		{
			if (type == -1) break;
			if (type == 2) type = 1;
			map[qq][ww] = type;
			if (type == 3) no_gold = 0;
		}
		if (no_gold || map[0][0] == 1)
		{
			puts("-1");
			continue;
		}
		queue<nod> q;
		q.push(nod(0, 0, 0, 0, 0));
		memset(v, 0, sizeof(v));
		v[0][0][0][0] = 1;
		nod ans = nod(0, 0, 0, 10000, 0);
		while (!q.empty())
		{
			nod p = q.front(); q.pop();
			if (map[p.x][p.y] == 3)
			{
				p.reach = 1;
			}
			if (p.x == 0 && p.y == 0 && p.reach)
			{
				ans = p;
				break;
			}
			int xx, yy;
			xx = p.x + xz[p.d];
			yy = p.y + yz[p.d];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n && !v[xx][yy][p.d][p.reach] && map[xx][yy] != 1)
			{
				v[xx][yy][p.d][p.reach] = 1;
				q.push(nod(xx, yy, p.d, p.step + 1, p.reach));
			}
			int dd;
			dd = (p.d + 1) % 4;
			if (!v[p.x][p.y][dd][p.reach])
			{
				v[p.x][p.y][dd][p.reach] = 1;
				q.push(nod(p.x, p.y, dd, p.step + 1, p.reach));
			}
			dd = (p.d + 3) % 4;
			if (!v[p.x][p.y][dd][p.reach])
			{
				v[p.x][p.y][dd][p.reach] = 1;
				q.push(nod(p.x, p.y, dd, p.step + 1, p.reach));
			}
		}
		int A = 1000 - (ans.step + 2) * 10;
		if (A < 0) A = -1;
		printf("%d\n", A);
	}
}

