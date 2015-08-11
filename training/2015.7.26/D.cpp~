#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define PII pair<int, int>
#define xx first
#define yy second
using namespace std;
struct nod
{
	PII a[4];
	int hash()
	{
		int res = 0;
		for (int i = 0; i < 4; ++ i) res = res * 7 + a[i].xx;
		for (int i = 0; i < 4; ++ i) res = res * 7 + a[i].yy;
		return res;
	}
	nod() {memset(a, 0, sizeof(a));}
};
int vis[5764810], tick = 0, ans, ind[10], H, TYPE;
char s[10][10];
bool board[10][10];
nod tmp;
bool cmp1(int i, int j) {return tmp.a[i].xx < tmp.a[j].xx;}
bool cmp2(int i, int j) {return tmp.a[i].yy > tmp.a[j].yy;}
bool cmp3(int i, int j) {return tmp.a[i].xx > tmp.a[j].xx;}
bool cmp4(int i, int j) {return tmp.a[i].yy < tmp.a[j].yy;}
bool ava(PII x)
{
	int i = x.xx, j = x.yy;
	if (i < 0 || i >= 8 || j < 0 || j >= 8) return 0;
	if (board[i][j]) return 0;
	return 1;
}
PII one2(const PII &a) {return PII(a.xx, a.yy + 1);}
PII one3(const PII &a) {return PII(a.xx + 1, a.yy);}
PII one4(const PII &a) {return PII(a.xx + 1, a.yy + 1);}
PII nex1(const PII &a) {return PII(a.xx - 1, a.yy);}
PII nex2(const PII &a) {return PII(a.xx, a.yy + 1);}
PII nex3(const PII &a) {return PII(a.xx + 1, a.yy);}
PII nex4(const PII &a) {return PII(a.xx, a.yy - 1);}
void set_1(PII a)
{
	PII b = one2(a);
	PII c = one3(a);
	PII d = one4(a);
	board[a.xx][a.yy] = 1;
	board[b.xx][b.yy] = 1;
	board[c.xx][c.yy] = 1;
	board[d.xx][d.yy] = 1;
}
void set_0(PII a)
{
	PII b = one2(a);
	PII c = one3(a);
	PII d = one4(a);
	board[a.xx][a.yy] = 0;
	board[b.xx][b.yy] = 0;
	board[c.xx][c.yy] = 0;
	board[d.xx][d.yy] = 0;
}
bool firfir;
void dfs(nod cur)
{
	H = cur.hash();
	if (!firfir)
	{
		if (vis[H] == tick) return;
		vis[H] = tick, ans ++;
	}
	else
	{
		firfir = 0;
	}
	//printf("A : %d %d   B : %d %d   C : %d %d   D : %d %d\n", cur.a[0].xx, cur.a[0].yy, cur.a[1].xx, cur.a[1].yy, cur.a[2].xx, cur.a[2].yy, cur.a[3].xx, cur.a[3].yy);
	///
	TYPE = 1;
	tmp = cur;
	for (int i = 0; i < 4; ++ i) ind[i] = i;
	sort(ind, ind + 4, cmp1);
	for (int i = 0; i < 4; ++ i)
	{
		int now = ind[i];
		while (ava(nex1(tmp.a[now])) && ava(nex1(one2(tmp.a[now])))) tmp.a[now] = nex1(tmp.a[now]);
		set_1(tmp.a[now]);
	}
	for (int i = 0; i < 4; ++ i) set_0(tmp.a[i]);
	dfs(tmp);
	///
	TYPE = 2;
	tmp = cur;
	for (int i = 0; i < 4; ++ i) ind[i] = i;
	sort(ind, ind + 4, cmp2);
	for (int i = 0; i < 4; ++ i)
	{
		int now = ind[i];
		while (ava(nex2(one4(tmp.a[now]))) && ava(nex2(one2(tmp.a[now])))) tmp.a[now] = nex2(tmp.a[now]);
		set_1(tmp.a[now]);
	}
	for (int i = 0; i < 4; ++ i) set_0(tmp.a[i]);
	dfs(tmp);
	///
	TYPE = 3;
	tmp = cur;
	for (int i = 0; i < 4; ++ i) ind[i] = i;
	sort(ind, ind + 4, cmp3);
	for (int i = 0; i < 4; ++ i)
	{
		int now = ind[i];
		while (ava(nex3(one3(tmp.a[now]))) && ava(nex3(one4(tmp.a[now])))) tmp.a[now] = nex3(tmp.a[now]);
		set_1(tmp.a[now]);
	}
	for (int i = 0; i < 4; ++ i) set_0(tmp.a[i]);
	dfs(tmp);
	///
	TYPE = 4;
	tmp = cur;
	for (int i = 0; i < 4; ++ i) ind[i] = i;
	sort(ind, ind + 4, cmp4);
	for (int i = 0; i < 4; ++ i)
	{
		int now = ind[i];
		while (ava(nex4(tmp.a[now])) && ava(nex4(one3(tmp.a[now])))) tmp.a[now] = nex4(tmp.a[now]);
		set_1(tmp.a[now]);
	}
	for (int i = 0; i < 4; ++ i) set_0(tmp.a[i]);
	dfs(tmp);
}
bool first[10];
int main()
{
	int T, z = 0;
	scanf("%d", &T);
	while (T --)
	{
		tick ++;
		memset(board, 0, sizeof(board));
		nod st = nod();
		memset(first, 1, sizeof(first));
		for (int i = 0; i < 8; ++ i)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < 8; ++ j)
			{
				if (s[i][j] >= 'A' && s[i][j] <= 'D')
				{
					if (first[s[i][j] - 'A'])
					{
						first[s[i][j] - 'A'] = 0;
						st.a[s[i][j] - 'A'] = PII(i, j);
					}
				}
				else if (s[i][j] == '#')
				{
					board[i][j] = 1;
				}
			}
		}
		ans = 0;
		firfir = 1;
		dfs(st);
		printf("Case %d: %d\n", ++ z, ans);
	}
}

