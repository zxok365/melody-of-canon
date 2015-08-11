#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int f[111111];
int s[111111];
int power[111111], ir_power[111111];
int tot, n, m;
const int Mo = 1e9 + 7;
int ans;
int remain;

int Quick(int p, int q){
	if (q == 0) return 1;
	if (q == 1) return p;
	int t = Quick(p, q / 2);
	if (q % 2 == 1) return 1LL * t * t % Mo * p % Mo; else return 1LL * t * t % Mo;
}

bool check(int p){
	while (p > 0){
		if (p % 10 != 4 && p % 10 != 7) return false;
		p /= 10;
	}
	return true;
}
int c(int p, int q){
	if (p < q) return 0;
	return 1LL * power[p] * ir_power[q] % Mo * ir_power[p - q] % Mo;
}
int k;
int main(){
	scanf("%d%d", &n, &k);
	power[0] = 1;
	remain = 0;
	for (int i = 1; i <= n; i++) power[i] = 1LL * power[i - 1] * i % Mo;
	for (int i = 0; i <= n; i++) ir_power[i] = Quick(power[i], Mo - 2);
	for (int i = 1; i <= n; i++){
		int p;
		scanf("%d", &p);
		if (check(p))
			f[++tot] = p;
		else
			remain++;
	}
	s[0] = 1;
	sort(f + 1, f + tot + 1);
	int m = 1;
	if (tot == 0) m = 0;
	for (int i = 2; i <= tot ; i++)
		if (f[i] != f[i - 1]) m++;
	int now = 1;
	for (int i = 2; i <= tot; i++)
	{
		if (f[i] != f[i - 1]){
			for (int j = m; j >= 1; j--)
			{
				s[j] += 1LL * s[j - 1] * now % Mo;
				s[j] %= Mo;
			}
			now = 1;
		} else
			now++;
	}
	for (int j = m; j >= 1; j--)
	{
		s[j] += 1LL * s[j - 1] * now % Mo;
		s[j] %= Mo;
	}
	for (int i = 0; i <= min(m, k); i++)
	{
		ans += 1LL * s[i] * c(remain, k - i) % Mo;
		ans %= Mo;
	}
	printf("%d\n", ans);
}
