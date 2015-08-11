#include<iostream>
#include<cstdio>
using namespace std;
int f[222222], len[222222], now[222222];
int nnow[222222],nnow2[222222],now2[222222];
int n ,m;
void manacher (int str[], int len[], int n){
	len[0] = 1;
	for (int i = 1, j  = 0; i < (n << 1) - 1; ++i){
		int p = i >> 1,	q = i - p,r = ((j + 1) >> 1) + len[j] - 1;
		len[i] = r < q ? 0 : min( r - q + 1, len[(j << 1) - i]);
		while (p - len[i] > -1 && q + len[i] < n &&  str[p - len[i]] == str[q + len[i]]){
			len[i] += 1;
		}
		if (q + len[i] - 1 > r){
			j = i;
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &f[i]);
	manacher(f, len, n);
	/*for (int i = 0 ; i < n * 2; i++)
		cout << len[i] << endl;*/
	now[0] = f[0];
	for (int i = 1; i < n; i++)
		now[i] = now[i - 1] + f[i];
	nnow[0] = now[0];
	for (int i = 1; i < n; i++)
		nnow[i] = nnow[i - 1] + now[i];
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		p -= 1;
		q -= 1;
		ans = 0;
		for (int j = p * 2;j <= q * 2;j++){
			if (j % 2 == 0){
				int t = j / 2 ;
				int pp = max(t - len[j] + 1, p);
				int qq = min(t + len[j] - 1, q);
				if (t - pp > qq - t) pp = 2 * t - qq; else qq = 2 * t - pp;
				//cout << pp << ' ' << qq << endl;
				if (pp <= qq)
				{
					int tmp = nnow[qq] - (t - 1 < 0 ? 0 : nnow[t - 1])
						- (qq - t + 1) * (t - 1 < 0 ? 0 : now[t - 1]);
					ans = ans + tmp * 2 - f[t] * (qq - t + 1);
				}
			}
			else
			{
				int t = j / 2;
				int pp = max(t - len[j] + 1, p);
				int qq = min(t + len[j], q);
				//cout << pp << ' ' << qq << endl;
				if (t - pp + 1 > qq - t) pp = 2 * t + 1- qq; else qq = 2 * t + 1- pp;
				//cout << pp << ' ' << qq << endl;
				if (pp <= qq)
				{
					int tmp = (nnow[qq] - nnow[t] - (qq - t) * now[t]) * 2;
					ans = ans + tmp;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

