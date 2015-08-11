#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int c[41111];
int n, m;

bool cmp(const int &p,const int &q){
	return p > q;
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		sort(c + 1, c + n + 1, cmp);
		if (n <= m)
		{
			printf("%d\n", c[1]);
			continue;
		}
		int now = m, remain = 0, pos = 0;
		for (int j = m + 1; j <= n; j++)
		{
			while (remain < c[j] && now > 1){
				now--;
				remain += (m - now) * (c[now] - c[now + 1]);
				/*		if (now == 1 || j == n){
						pos = j + 1;
						break;
						}*/
			}
			if (remain >= c[j])
				remain -= c[j];
			else
			{
				pos = j;
				break;
			}

			if (now == 1 || j == n){
				pos = j + 1;
				break;
			}
		}
		now = 0;
		for (int i = pos; i <= n; i++)
			now = now + c[i];
		if (remain >= now)
		{
			printf("%d\n", c[1]);
			continue;
		}
		printf("%d\n", (now - remain + m - 1) / m + c[1]);
	}
}
