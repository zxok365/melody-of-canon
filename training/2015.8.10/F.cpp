#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int Gxx;
long long mo = 100000007;
long long ans;
int n, m, k;
pair<int , int> p[11111];

long long calc(int p, int q){
	if (q == 0) return 1;
	if (q == 1) return p % mo;
	long long t = calc(p, q / 2);
	if (q % 2)
		return t * t % mo * p % mo;
	else
		return t * t % mo;
}
int main(){
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &p[i].first, &p[i].second);
			p[i].first ++;
			p[i].second ++;
			if (p[i].first * 2 > n) p[i].first = n + 1- p[i].first;
			if (p[i].second * 2 > n) p[i].second = n + 1 - p[i].second;
			if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
		}
		int now = (n + 1)/ 2;
		now = now * (now + 1) / 2;
		sort(p + 1, p + m + 1);
		p[0].first = p[0].second = 0;
		for (int i = 1; i <= m; i++)
			if (p[i].first != p[i - 1].first || p[i].second != p[i - 1].second)
				now--;
		ans = calc(k, now);
		cout << ans << endl;
	}
}
