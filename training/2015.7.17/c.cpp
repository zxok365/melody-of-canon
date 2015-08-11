#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define Mod 1000000007LL
using namespace std;
typedef long long ll;
int tot = 1;
int e[30001], nxt[30001], g[30001];
int h[30001], ans[30001], size[30001];
ll iden[30001];
bool mark[30001];
int stack[30001];
int n;
int px[30001], py[30001];
bool vis[30001];
void Add(int u, int v)
{
	e[tot] = v; nxt[tot] = g[u]; g[u] = tot ++;
	e[tot] = u; nxt[tot] = g[v]; g[v] = tot ++;
}
ll dfs(int x, int deep)
{
	ll sum = h[deep];
	vis[x] = true;
	for (int i = g[x]; i; i = nxt[i])
		if (!vis[e[i]]) sum = (sum + 1LL * h[deep] * dfs(e[i], deep + 1) % Mod) % Mod;
	return sum * sum % Mod;
}
int f[10001];
bool v[10001];
int st[10001];
vector<ll > num[20];
int getfa(int x)
{
	if (f[x] == 0) return x;
	return f[x] = getfa(f[x]);
}
bool Judge(int mask)
{
	int tp = 0;
	for (int i = 1; i <= n; i ++) v[i] = false, f[i] = 0;
	for (int i = 1; i <= n; i ++)
		if ((mask >> (i - 1)) & 1) v[i] = true, st[++ tp] = i;
	for (int i = 1; i < n; i ++)
		if (v[px[i]] && v[py[i]])
		{
			int tmpx = getfa(px[i]), tmpy = getfa(py[i]);
			if (tmpx == tmpy) continue;
			f[tmpx] = tmpy;
		}
	int now = getfa(st[1]);
	for (int i = 2; i <= tp; i ++)
		if (getfa(st[i]) != now) return false;
	return true;
}
void Work()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) h[i] = (ll )(rand()) * rand() % Mod, ans[i] = 0, size[i] = 0, num[i].clear();
	for (int i = 1; i < n; i ++)
		scanf("%d %d", &px[i], &py[i]);
	for (int i = 1; i < (1 << n); i ++)
	{
		int top = 0;
		if (!Judge(i)) continue;
		for (int j = 1; j <= n; j ++) mark[j] = 0;
		for (int j = 1; j <= n; j ++)
			if ((i >> (j - 1)) & 1) mark[j] = true, stack[++ top] = j;
		for (int j = 1; j <= n; j ++) g[j] = 0;
		tot = 1;
		for (int j = 1; j < n; j ++)
			if (mark[px[j]] && mark[py[j]]) Add(px[j], py[j]);
		bool flag = false;
		ll fget;
		for (int j = 1; j <= top; j ++)
		{
			ll tmp = dfs(stack[j], 1);
			for (int k = 1; k <= n; k ++) vis[k] = 0;
			for (int k = 0; k < ans[top]; k ++)
				if (num[top][k] == tmp) { flag = true; break; }
			if (flag) break;
			fget = tmp;
		}
		if (flag == false)
		{
			++ ans[top];
			num[top].push_back(fget);
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i ++) sum += ans[i];
	printf("%d\n", sum);
}
int main( )
{
	int T;
	srand(343);
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++)
	{
		printf("Case #%d: ", i);
		Work();
	}
	return 0;
}
