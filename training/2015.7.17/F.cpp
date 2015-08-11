#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll Sum[41], a[41];
int n, k;
ll ans;
void dfs(int x, int sum, ll now)
{
	if (sum > k) return ;
	if (x == n + 1)
	{
		if (sum == k) ans = min(ans, now);
		return ;
	}
	if ((now & Sum[x]) >= ans) return ;
	dfs(x + 1, sum + 1, now & a[x]);
	dfs(x + 1, sum, now);
}
int main( )
{
	int T;
	scanf("%d", &T);
	for (int j = 1; j <= T; j ++)
	{
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		Sum[n] = a[n];
		for (int i = n - 1; i >= 1; i --)
			Sum[i] = a[i] & Sum[i + 1];
		ans = (1LL << 60) - 1;
		dfs(1, 0, ans);
		printf("Case #%d: %lld\n", j, ans);
	}
	return 0;
}
