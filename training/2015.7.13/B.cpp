#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int Mn = 70000 + 10;
string s[Mn],t[Mn];
long long f[10],c[10][10];
int n;
int main() {
	c[1][0] = c[2][0] = c[3][0] = c[4][0] = 1;
	c[2][1] = 2;
	c[3][1] = c[3][2] = 3;
	c[4][1] = c[4][3] = 4;
	c[4][2] = 6;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	int tot = 1<<4;
	for(int mask = 1; mask < tot; ++mask) {
		for(int i = 1; i <= n; ++i) {
			t[i] = "";
			for(int j = 0; j < 4; ++j)
				if(mask >> j & 1) {
					t[i] += s[i][j];
				}
		}
		
		int cnt(0);
		for(int i = 0; i < 4; ++i) {
			if(mask >> i & 1)
				++cnt;
		}
		sort(t + 1, t + n + 1);
		long long tmp(0);
		for(int i = 1; i <= n;) {
			int j = i + 1;
			for(;t[j] == t[i]; ++j);
			tmp += (long long) (j - i) * (j - i - 1) / 2;
			i = j;
		}
		f[cnt] += tmp;
 	}
 	f[0] = (long long)n * (n - 1) / 2;
 	for(int i = 4; i >= 1; --i) {
 		for(int j = i - 1; j >= 0; --j) {
 			f[j] -= c[i][j] * f[i];
 		}
 	}
 	for(int i = 1; i <= 4; ++i) {
 		cout << f[4 - i];
 		if(i == 4)
 			cout << endl;
 		else
 			cout << " ";
 	}
	return 0;
}
