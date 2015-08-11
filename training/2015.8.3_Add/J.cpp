#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int ans = 0;
		while (n > 0) n /= 2, ans++;
		printf("%d\n", ans);
	}
}
