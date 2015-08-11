#include<iostream>
#include<cstdio>
using namespace std;
int l, r;
int n, m;
int f[1111];
int mi[2222][4444], ma[2222][4444];
void ttry(int x){
	int S = n + x + 1;
	int T = n + x + 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= S
		
}
int main(){
	scanf("%d", &n, &m);
	ans = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &f[i]);
		while (f[i] - 2 * m > 0) f[i] -= m, ans++;
		l = l + f[i];
		r = r + (f[i] + m - 1)/ m;
	}
	l = l / m;
	while (l + 1 < r){
		int mid = (l + r) / 2;
		if (ttry(mid)) r = mid; else l = mid;
	}
	printf("%d\n", ans + r);

}
