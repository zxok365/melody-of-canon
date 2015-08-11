#include<iostream>
#include<cstdio>
using namespace std;
bool bo[11];
int n;
int calc(long long p){
	for (int i = 0 ; i<= 9; i++) bo[i] = false;
	while (p > 0){
		bo[p % 10] = true;
		p /= 10;
	}
	int now = 0;
	for (int i = 0 ; i <= 9; i++) if (bo[i]) now++;
	return now;
}
int main(){
	while (1){
		scanf("%d", &n);
		if (n == 0) break;
		int ans = 10;
		long long tot_ans = 0;
		int l = n;
		int r = 1;
		while (l > 0) r *= 10,l /= 10;
		for (int i = 1; i <= r;i++)
		{
			int t = calc(1LL * n * i);
			if (t < ans){
				ans = t;
				tot_ans = i;
			}
		}	
		cout << tot_ans * n << endl;
	}
}
