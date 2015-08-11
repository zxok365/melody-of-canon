#include <cstdio>
#include <iostream>

using namespace std;

long long ans[55];

int main() {
	int n;
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= 50; i ++) ans[i] = ans[i - 1] + ans[i - 2];
	while (scanf("%d", &n) == 1) {
		cout << ans[n] << endl;
	}
	return 0;
}
