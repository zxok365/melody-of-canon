#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define PII pair<int, int>
#define SS first
#define TT second
using namespace std;
const int MAXN = 1000;
int nod_cnt, edge_cnt, to[MAXN], nex[MAXN], st[MAXN];
char ch[MAXN], s[200];
int d[MAXN][MAXN];
bool f[MAXN][MAXN];
char ans[MAXN][MAXN];
PII pre[MAXN][MAXN];
void ae(int s, int t, char c)
{
	edge_cnt ++;
	to[edge_cnt] = t;
	nex[edge_cnt] = st[s];
	st[s] = edge_cnt;
	ch[edge_cnt] = c;
}
PII large(PII x)
{
	int s = ++ nod_cnt;
	int t = ++ nod_cnt;
	ae(s, x.SS, '#');
	ae(x.TT, t, '#');
	return PII(s, t);
}
PII AL(PII x, PII y)
{
	int s = ++ nod_cnt;
	int t = ++ nod_cnt;
	ae(s, x.SS, '#');
	ae(s, y.SS, '#');
	ae(x.TT, t, '#');
	ae(y.TT, t, '#');
	return PII(s, t);
}
PII CO(PII x, PII y)
{
	if (x == PII(0, 0)) return y;
	ae(x.TT, y.SS, '#');
	return PII(x.SS, y.TT);
}
PII KL(PII x)
{
	int nod = ++ nod_cnt;
	ae(x.TT, nod, '#');
	ae(nod, x.SS, '#');
	return PII(nod, x.SS);
}
PII ONE(char c)
{
	int s = ++ nod_cnt;
	int t = ++ nod_cnt;
	ae(s, t, c);
	return PII(s, t);
}
PII build(int L, int R)
{
	while (s[L] == '(' && s[R] == ')') -- L, -- R;
	//printf(" *** %d %d\n", L, R);
	if (L == R) return ONE(s[L]);
	if (s[R] == '*') return KL(build(L, R - 1));
	for (int i = L; i <= R; ++ i)
	{
		if (s[i] == '|')
		{
			return AL(build(L, i - 1), build(i + 1, R));
		}
	}
	PII last, cur;
	last = cur = PII(0, 0);
	int cnt = 0, j = L;
	for (int i = L; i <= R; ++ i)
	{
		if (cnt == 0) j = i;
		if (s[i] == '(') cnt ++;
		if (s[i] == ')') cnt --;
		if (cnt == 0)
		{
			if (s[i] == '*')
			{
				last = KL(last);
			}
			else
			{
				cur = CO(cur, last);
				last = build(j, i);
			}
		}
	}
	return CO(cur, last);
}
queue<PII> q;
bool in_queue[MAXN][MAXN];
void update(PII x, PII y, int dd, char cc)
{
	if (f[x.first][x.second] && d[x.first][x.second] <= dd) return;
	f[x.first][x.second] = 1;
	d[x.first][x.second] = dd;
	pre[x.first][x.second] = y;
	ans[x.first][x.second] = cc;
	if (!in_queue[x.first][x.second])
	{
		q.push(x);
		in_queue[x.first][x.second] = 1;
	}
}
char A[5005];
void SPFA(PII T1, PII T2)
{
	memset(f, 0, sizeof(f));
	memset(in_queue, 0, sizeof(in_queue));
	f[T1.SS][T2.SS] = 1;
	in_queue[T1.SS][T2.SS] = 1;
	while (!q.empty()) q.pop();
	q.push(PII(T1.SS, T2.SS));
	while (!q.empty())
	{
		PII p = q.front(); q.pop(); in_queue[p.first][p.second] = 0;
		for (int i = st[p.first]; i; i = nex[i])
		{
			if (ch[i] == '#')
			{
				int C = d[p.first][p.second];
				update(PII(to[i], p.second), p, C, '#');
			}
		}
		for (int i = st[p.second]; i; i = nex[i])
		{
			if (ch[i] == '#')
			{
				int C = d[p.first][p.second];
				update(PII(p.first, to[i]), p, C, '#');
			}
		}
		for (int i = st[p.first]; i; i = nex[i])
		{
			for (int j = st[p.second]; j; j = nex[j])
			{
				if (ch[i] == ch[j] && ch[i] != '#')
				{
					int C = d[p.first][p.second] + 1;
					update(PII(to[i], to[j]), p, C, ch[i]);
				}
			}
		}
	}
	if (f[T1.TT][T2.TT])
	{
		puts("Wrong");
		int len = 0;
		for (PII x = PII(T1.TT, T2.TT); x != PII(T1.SS, T2.SS); x = pre[x.SS][x.TT])
		{
			if (ans[x.SS][x.TT] != '#')
			{
				A[len ++] = ans[x.SS][x.TT];
			}
		}
		for (int i = len - 1; i >= 0; -- i) putchar(A[i]);
		puts("");
	}
	else
	{
		puts("Correct");
	}
}
int main()
{
	nod_cnt = edge_cnt = 0;
	memset(st, 0 ,sizeof(st));
	gets(s);
	PII T1 = build(0, strlen(s) - 1);
	T1 = large(T1);
	gets(s);
	PII T2 = build(0, strlen(s) - 1);
	T2 = large(T2);
	SPFA(T1, T2);
}

