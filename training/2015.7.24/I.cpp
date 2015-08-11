#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long dx1,dx2,dx3,dy1,dy2,dy3;

long long gcd(long long p, long long q){
	return q == 0 ? p : gcd(q, p % q);
}


long long ttry(long long a,long long b,long long c,long long d){
	if (a < 0) a = -a, b = -b;
	if (c < 0) c = -c, d = -d;
	if (a == 0 && c == 0) return gcd(abs(b), abs(d));
	if (a == 0) return abs(b);
	if (c == 0) return abs(d);
	long long GCD = gcd(a, c);
	long long LCM = a * c / GCD;
	long long p = LCM / a * b;
	long long q = LCM / c * d;
	return abs(p - q);

}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case ; time++)
	{
		cin >> dx1 >> dy1;
		cin >> dx2 >> dy2;
		cin >> dx3 >> dy3;
		long long GCD = gcd(gcd(abs(dx1), abs(dx2)),abs(dx3));
		long long now1 = ttry(dx1, dy1, dx2, dy2);
		long long now2 = ttry(dx1, dy1, dx3, dy3);
		long long now3 = ttry(dx2, dy2, dx3, dy3);

		long long GCD2 = gcd(gcd(now1, now2),now3);
		cout << "Case #" << time << ": " << GCD * GCD2 << endl;
	}
	return 0;
}
