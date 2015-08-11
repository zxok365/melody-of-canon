#include<iostream>
#include<cstdio>
using namespace std;
long long n, m;
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		cin >> n;
		long double ans = 0;
		n -= 1;
		for (int i = 0; (n >> i) > 0; i++){
			long long t = (n >> (i + 1) << i);
			if ((n & (1 << i)) != 0) t = t + n % (1LL << i) + 1;
		//	cout << t << endl;
			ans = ans + 1. * (1LL << i) * t * (n + 1 - t) * 2;
		//	cout << ans << endl;
		}
		ans = ans / (n + 1) / (n + 1);
		printf("%.2f\n",(double)ans);
	}
}
