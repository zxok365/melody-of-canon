#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;

int n, m, t, step;
long long tot_ans;
int g[3000000],f[3000000];
int min2(int p, int q){
	if (p == -1) return q;
	if (q == -1) return p;
	return p < q ? p : q;
}

int ttry(int p, int q, int r){
	int s = p / r;
	int remain = p % r;


}


void make(int p, int q){
	if (p == q)
		return;
	for (int i = p; i <= q; i++)
		g[x] = f[x];
	int x = (q - p) / 2;
	for (int i = 1; i <= x; i++)
	{
		f[i + p] = g[i * 2 - 1 + p];
		f[i + x + p] = g[i * 2 + p];
	}
	make(p, x);
	make(x + 1, q);
}
int main(){
	for (int i = 1; i <= (1 << 20); i++)
		f[i] = i;
	make(1, 1 << 20);
	while (scanf("%d%d", &n, &m) == 2){
		t = m - n + 1;
		if (n == 0) printf("%d\n", m); else
		{
			for (int i = 1; i <= n / max((t - 1), 1); i++)
				ans = min2(ans, ttry(n, t, i));
			printf("%d\n", ans);
		}
	}
}
