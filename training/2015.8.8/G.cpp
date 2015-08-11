#include<iostream>
#include<cstdio>
using namespace std;


int calc(int p, int q, int r){
	if (r == 1) return p + q;
	if (r == 2) return p - q;
	if (r == 3) return p * q;
	if (r == 4) return p / q;
	if (r == 5) return p % q;
}
int trans(char ch){
	if (ch == '+') return 1;
	if (ch == '-') return 2;
	if (ch == '*') return 3;
	if (ch == '/') return 4;
	return 5;
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		int a, b, c;
		char p1, p2;
		int now1, now2;
		scanf("%d %c %d %c %d", &a, &p1, &b, &p2, &c);
		now1 = trans(p1);
		now2 = trans(p2);
		if (now1 >= 3 || (now1 < 3 && now2 < 3)){
			a = calc(a, b, now1);
			now1 = now2;
			b = c;
		} else 
			b = calc(b, c, now2);
		a = calc(a, b, now1);
		printf("%d\n", a);
	}
}
