#include<iostream>
#include<cstdio>
using namespace std;

int n, m, t;

long long min(const long long &p, const long long &q){
	if (p == -1) return q;
	if (q == -1) return p;
	return p > q ? q : p;
}
long long find(long long p, long long q){
	long long ans = -1;
	if (p == 0) return q - 1;
	if (p < q) return ans;
	ans = min(ans, find(p, q * 2));
	ans = min(ans, find(p, q * 2 - 1));
	ans = min(ans, find(p - q, q * 2));
	ans = min(ans, find(p - q - 1, q * 2 + 1));
	return ans;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		t = m - n + 1;
		if (t==1) cout<<m<<endl;else cout << find(n, t) << endl;
	}
}


