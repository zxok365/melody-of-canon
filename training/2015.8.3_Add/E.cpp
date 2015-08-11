#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		long long ans = 1;
		long long sum = 1;
		long long tot = 1;
		while (tot < n){
			ans++;
			sum *= 3;
			tot += sum;
		}
		cout << ans << endl;
	}
}
