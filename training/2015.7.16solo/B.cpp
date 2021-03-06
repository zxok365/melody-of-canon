#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n, k;
int a[111111];
long long l, r;
bool check(long long x){
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = ans + (max(0LL, a[i] - x) + k - 1) / k;
		if (ans > x) return false;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	r = 0;
	int now = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		now = max(now, a[i]);
	}
	scanf("%d", &k);
	l = 0;
	for (int i = 1; i <= n; i++)
		r = r + (a[i] + k - 1) / k;
	k -= 1;
	
	if (k == 0)
		printf("%d\n", now);
	else
	{
		while (l + 1 < r){
			long long mid = (l + r) / 2;
			if (check(mid))
				r = mid;
			else
				l = mid;
		}
		cout << r << endl;
	}
}
