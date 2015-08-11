#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int BLOCK = 710, INF = 0x3f3f3f3f;
int BLOCKSZ = 710;
struct num
{
	int a, id;
	num() {a = id = -1;}
	num(int q, int w) {a = q; id = w;}
};
bool operator < (const num &a, const num &b)
{
	if (a.a == b.a) return a.id > b.id;
	return a.a < b.a;
}
__inline num operator + (const num &a, const int &p){
	return num(a.a + p, a.id);
}
__inline num operator * (const num &a, const int &p){
	return num(a.a * p, a.id);
}
__inline num operator % (const num &a, const int &n)
{
	return num(a.a % n, a.id);
}
__inline num imin(const num &a, const num &b)
{
	if (a.a == -1) return b;
	if (b.a == -1) return a;
	if (a < b) return a;
	return b;
}
num sml[2010];
set<num> G[2010];
char input[40005][3];
int xy[40005];
int main()
{
	ios::sync_with_stdio(false);
	int n, z = 0;
	//while (scanf("%d", &n), n != 0)
	while (cin >> n && n)
	{
		//printf("***\n");
		int i, l, cnta = 0, xmax = 0;
		for (i = 1; i <= n; ++ i)
		{
			//scanf("%s%d", input[i], &xy[i]);
			cin >> input[i] >> xy[i];
			if (input[i][0] == 'B') xmax = max(xmax, xy[i]);
		}
		//BLOCK = (int)sqrt(xmax) + 1;
		//BLOCKSZ = xmax / BLOCK + 1;
		BLOCK = BLOCKSZ = 2000;
		for (i = 0; i < BLOCK + 5; ++ i) G[i].clear();
		for (i = 0; i < BLOCKSZ + 5; ++ i) sml[i] = num();
		++ z;
		//if (z != 1) puts("");
		if (z > 1) cout << endl;
		//printf("Case %d:\n", z);
		cout << "Case " << z << ':' << endl;
		for (l = 1; l <= n; ++ l)
		{
			char c;
			int x;
			c = input[l][0];
			x = xy[l];
			//printf("IN %s %d", c, x);
			if (c == 'B')
			{
				cnta ++;
				for (i = 1; i < BLOCKSZ + 5; ++ i) sml[i] = imin(sml[i], num(x, cnta) % i);
				//printf("sml[5] = %d %d\n", sml[5].a, sml[5].id);
				G[x / BLOCKSZ].insert(num(x, cnta) % BLOCKSZ);
			}
			else
			{
				x = min(x, xmax + 1);
				if (x < BLOCKSZ + 5)
				{
					//printf("%d\n", sml[x].id);
					cout << sml[x].id << endl;
					continue;
				}
				num tmp = num();
				for (i = 0; i < BLOCK; ++ i)
				{
					if (G[i].size() == 0) continue;
					if (i * BLOCKSZ / x == ((i + 1)  * BLOCKSZ - 1) / x)
					{
						tmp = imin(tmp, (*(G[i].begin()) + i * BLOCKSZ) % x);
						continue;
					}
					set<num>::iterator it = G[i].lower_bound(num((x - (i * BLOCKSZ) % x) % x, INF));
					if (it == G[i].end()) it = G[i].begin();
					tmp = imin(tmp, ((*it) + i * BLOCKSZ) % x);
				}
				//printf("%d\n", tmp.id);
				cout << tmp.id << endl;
			}
		}
	}
}

