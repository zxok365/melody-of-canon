#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long sqr(long long x) {return x * x;}
int f[111][33];
long long p[111];
long long ans[111];
bool bo[11][11];
int n, m;
int main(){
	scanf("%d", &m);
	for (int i =1 ; i <= m; i++) cin >> p[i];
	sort(p + 1,p + m + 1);
	int n = (int)sqrt(m * 2);
	if ((n - 1)* (n - 2) == 2 * m) n = n - 1;
	if (n * (n + 1) == 2 * m) n = n + 1;/*
	for (int i = 1; i <= m; i++)
	{
		for (int j = 31;j >= 0;j --)
			cout << f[i][j];
		cout << endl;
	}*/
	int now;
	for (int l = 0; l < 31; l++){
		ans[1] = (1 << l);
	//	cout << "1:" << ans[1] << endl;
		now = 1;
		for (int t = 1; t <= m; t++){
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					bo[j][k] = false;
			now = 1;
			for (int i = t; i <= m; i++)
			{
				if ((p[i] ^ ans[1]) == 0) continue;
				bool pick = true;
				for (int j = 1; j <= now; j++)
				if (pick)
					for (int k = j + 1;k <= now; k++)
					if (bo[j][k] == false && p[i] == (ans[j] ^ ans[k])){
						bo[j][k] = true; pick = false; break;
					}
			//	cout << p[i] << ' ' << (p[i] ^ ans[1]) << ' ' << pick << endl;
				if (pick) ans[++now] = (p[i] ^ ans[1]);
			}
			if (now != n)
				continue; 
			else
			{
				for (int i = 1; i <= now - 1; i++) cout << ans[i] << ' ';
				cout << ans[now] << endl;
				return 0;
			}
		}
	}
}
