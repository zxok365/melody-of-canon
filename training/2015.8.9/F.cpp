#include<iostream>
#include<cstdio>
using namespace std;
int  a[1111111];
int n, m;
void read(int &p){
	char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	int x = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch - '0';
	p = x;
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
			if (ans = 
	}
}
