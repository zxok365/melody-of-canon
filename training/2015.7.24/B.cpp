#include <cstdio>
#include <iostream>

using namespace std;

int n, a, b, c;
int sum[100005], maxa[100005];

int main() {
	int test;
	scanf("%d", &test);
	int tot=0;
	while (test--) {
		tot++;
		scanf("%d", &n);
		int ans=0;
		for (int i=1; i<=n; i++) {
			sum[i]=0;
			maxa[i]=0;
		}
		for (int i=1; i<n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			ans+=c;
			maxa[a]=max(maxa[a], c);
			maxa[b]=max(maxa[b], c);
			sum[a]+=c;
			sum[b]+=c;
		}
		for (int i=1; i<=n; i++) {
			int sumd2=(sum[i]>>1);
			if (sumd2<maxa[i]) ans-=sum[i]-maxa[i];
				else ans-=sumd2;
		}
		printf("Case #%d: %d\n", tot, ans);
	}
	return 0;
}
