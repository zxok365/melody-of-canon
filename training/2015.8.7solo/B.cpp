#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char str[33333];
int c[33333];
int n, m;
int tot;

void insert(int p, int q){
	while (p <= n){
		c[p] = c[p] + q;
		p += p & (-p);
	}
}

int find(int p){
	int ans = 0;
	while (p != 0){
		ans = ans + c[p];
		p -= p & (-p);
	}
	return ans;
}
int main(){
	n = 0;
	tot = 1999;
	while (1){
		char ch = getchar();
		if (ch == EOF) break;
		if (ch == '\n' || ch == '\r') continue;
		str[++n] = ch;
	}
	for (int i = 0; i <=n; i++) c[i] = 0;
	for (int i = 1; i <= n; i++) insert(i,1);
	int now = 0;
//`	cout << n << endl;
//	for (int i = 1; i <= n; i++) cout << c[i] << endl;
	for (int i = 0; i < n; i++)
	{
	//	tot++;
		int step = tot % (n - i);
//		cout << step << endl;
		if (step == 0) step = n - i;
		int t = find(n) - find(now);
		if (t < step){
			step -= t;
			now = 0;
		}
		int l = now;
		int r = n;
		while (l + 1 < r){
			int mid = (l + r) / 2;
			if (find(mid) - find(now) >= step) r = mid; else l = mid;
		}
		now = r;
		insert(r, -1);
//		cout << r << ' ' << str[r] << endl;
	}
	if (str[now] == '?') printf("Yes\n"); else
	if (str[now] == ' ') printf("No\n"); else
		printf("No comments\n");
	
}
