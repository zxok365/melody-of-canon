#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
const int Mn = 100 + 10;
int a[Mn],n,ans;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);
	}
	sort(a + 1, a + n + 1);
	ans = a[1] + a[n];
	for(int i = 1; i < n; ++i) {
		ans = ans + max(a[i], a[i + 1]);
	}
	printf("%d\n",ans);
}
