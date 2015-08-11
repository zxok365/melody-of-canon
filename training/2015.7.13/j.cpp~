#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;
const int Mp = 302;
bool ok[Mp];
int pr[Mp],tot;
long long A, B, k;
long long ans(0);
void dfs(long long cur, int sign, long long pos, long long lim) {
	if(pr[pos] > k || pos > tot)
		return;
	// 0
	dfs(cur, sign, pos + 1, lim);
	// 1
	cur = cur * pr[pos];
	sign = -sign;
	if(cur <= lim) {
//cerr << lim << " " << cur << ":" << sign * lim / cur << endl; 
		ans += sign * lim / cur;
		dfs(cur, sign, pos + 1, lim);
	}
}
inline long long calc(long long lim) {
	ans = 0;
	dfs(1, -1, 1, lim);
	return ans;
}
int main() {
	for(int i = 2; i < Mp; ++i) {
		if(!ok[i]) {
			pr[++tot] = i;
			for(int j = i ; i * j < Mp; ++j)
				ok[i * j] = true;
		}
	}
//cerr << tot << endl;
	cin >> A >> B >> k;
	++k; 
	cout << B - (calc(A + B) - calc(A)) << endl;
	return 0;
}
