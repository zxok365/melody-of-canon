#include<iostream>
#include<cstdio>
using namespace std;
int t[11111];
int a[1111111];

int gcd(int p, int q){
	return q == 0 ? p : gcd(q, p % q);
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
/*	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j<= n; j++)
		{
			int p = gcd(t[i], t[j]);
			t[i] /= p;
		}
	a[1] = 1;
	a[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[0]; j++)
			a[j] = a[j] * t[i];
		for (int j = 1; j <= a[0]; j++)
		if (a[j] >= 10){
			a[j + 1] += a[j] / 10;
			a[j] %= 10;
			if (j == a[0]) a[0]++;
		}
	}
	int fz = 1;
	if (a[1] % 2 != 0) fz = 2; else		
	{
		for (int i = a[0]; i >= 1; i--)
		{
			a[i - 1] += a[i] % 2 * 10;
			a[i] /= 2;
			if (a[i] == 0 && i == a[0]) a[0]--;
		}
	}
	for (int i = a[0];i >= 1; i--) printf("%d",a[i]);
	printf(" %d\n", fz);*/
}
