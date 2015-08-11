#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, k, u, v;
vector<int> a[4005];
pair<int, int> b[4005];
int c[50005];
int Size;
bool flag[5005];

int main() {
	scanf("%d%d", &n, &k);
	int maxu = 1;
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
		maxu = max(maxu, u);
	}
	int sum = 0;
	for (int i = 1; i <= maxu; i ++) {
		if ((int)a[i].size() > 0) b[++sum] = make_pair((int)a[i].size(), i);
	}
	sort(b + 1, b + sum + 1);
	int low = sum - k + 1;
	if (low > 0)
	{
		while (a[b[low].second].size() == a[b[low - 1].second].size()) low--;
		low--;
		Size = (int)a[b[low + 1].second].size();
		for (int i = low + 1; i <= sum; i ++) {
			flag[b[i].second] = true;
		}
	}
	int tot = 0;
	for (int i = 1; i <= maxu; i ++) if (flag[i]) {
		if ((int)a[i].size() > 0) sort(a[i].begin(), a[i].end());
		int num = 0;
		for (int j = (int)a[i].size() - 1; j >= (int)a[i].size() - Size; j --) num += a[i][j];
		c[++tot] = num;
	}
	sort(c + 1, c + tot + 1);
	if (tot < k) printf("%d %d\n", 0, 0); else
	{
		int ans = 0;
		for (int i = tot; i >= tot - k + 1; i --) ans += c[i];
		printf("%d %d\n", Size, ans);
	}
	return 0;
}
